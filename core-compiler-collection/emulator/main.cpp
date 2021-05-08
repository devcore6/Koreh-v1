#include <emulator.h>

uint64_t cores = 8;
uint64_t frequency = 1000000;
uint8_t bits = 64;
uint64_t memorysize = 268435456; // 256 MB
uint8_t* memory;
std::fstream drive;

void printversion() {
	std::cout << "core-emulator v" << ((version & 0xFF000000) >> 24) << "." << \
		((version & 0x00FF0000) >> 16) << "." << \
		((version & 0x0000FF00) >> 8) << \
		((version & 0x00000001) ? "a" : (version & 0x00000002) ? "b" : "") << "\n";
	std::cout << "core compiler collection v" << ((collectionversion & 0xFF000000) >> 24) << "." << \
		((collectionversion & 0x00FF0000) >> 16) << "." << \
		((collectionversion & 0x0000FF00) >> 8) << \
		((collectionversion & 0x00000001) ? "a" : (version & 0x00000002) ? "b" : "") << std::endl;

}

void help() {
	std::cout << "\n";
	std::cout << "usage: cemu    <binaryfile> [-d <driveimage>] [options]\n";
	std::cout << "       cemu -c <driveimage> <size[K|M|G]>\n";
	std::cout << "\n";
	std::cout << "options:\n";
	std::cout << "         -h                               show this help message\n";
	std::cout << "         -d <driveimage>                  uses a given drive image.\n";
	std::cout << "         -c <driveimage> <size[K|M|G]>    creates a drive image <driveimage> of the given size.\n";
	std::cout << "         -m <size[K|M|G]>                 specifies the amount of RAM to give the machine, default is 256MB.\n";
	std::cout << "         -f <frequency[K|M]>              specifies the frequency for the machine, default is 1MHz.\n";
	std::cout << "         -V                               print version information.\n";
	std::cout << "         --32                             emulates a 32-bit system.\n";
	std::cout << "         --64                             emulates a 64-bit system.";
	std::cout << std::endl;

}

void makedriveimage(char* const path, uint64_t size) {

}

void corehandler(core_t* core) {
	try {

	} catch(uint8_t f) {
		if(f < INT_KEYBOARD_DATA_READY) {
			/* todo: fault handling */
		} else {
			/* todo: intewrrupt handling */
		}
	}
}

void corehandlercall(core_t* core, std::future<void> shutdown) {
	const long double tickduration = 1.0L / (long double)frequency; // long double is 64-bit double on MSVC and either 80 or 96-bit on GCC
	std::chrono::high_resolution_clock::time_point lasttime = std::chrono::high_resolution_clock::now();
	long double duration = 0;
	while(shutdown.wait_for(std::chrono::duration<long double>(duration)) == std::future_status::timeout) {
		corehandler(_cores[core->id]);
		duration = std::chrono::duration_cast<std::chrono::duration<long double>>(std::chrono::high_resolution_clock::now() - lasttime).count();
	}
}

std::vector<core_t*> _cores;

#ifdef _MSC_VER
# define SDL_MAIN_HANDLED
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
TTF_Font* font = nullptr;

bool initgraphics() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Could not init video: " << SDL_GetError() << std::endl;
		return false;
	}
	window = SDL_CreateWindow("Koreh v1 Emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);
	if(!window) {
		std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
		return false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(!renderer) {
		std::cerr << "Could not create window renderer: " << SDL_GetError() << std::endl;
		return false;
	}
	if(TTF_Init() < 0) {
		std::cerr << "Could not init font: " << TTF_GetError() << std::endl;
		return false;
	}
	font = TTF_OpenFont("font.ttf", 32);
	if(!font) {
		std::cerr << "Could not load font: " << TTF_GetError() << std::endl;
		return false;
	}
	charsData.resize(VGA_WIDTH * VGA_HEIGHT);
	return true;
}

enum {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

SDL_Color Colors[16] = {
	{ 0  , 0  , 0  , 255 },
	{ 0  , 0  , 255, 255 },
	{ 0  , 255, 0  , 255 },
	{ 0  , 255, 255, 255 },
	{ 255, 0  , 0  , 255 },
	{ 255, 0  , 255, 255 },
	{ 128, 64 , 32 , 255 },
	{ 192, 192, 192, 255 },
	{ 64 , 64 , 64 , 255 },
	{ 128, 128, 255, 255 },
	{ 128, 255, 128, 255 },
	{ 128, 255, 255, 255 },
	{ 255, 128, 128, 255 },
	{ 255, 128, 255, 255 },
	{ 128, 192, 160, 255 },
	{ 255, 255, 255, 255 }
};

struct charData {
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	SDL_Rect rect;
	uint8_t fg;
	char C[2] = { 0, 0 };
	char c;
};
std::vector<charData> charsData;

constexpr uint8_t VGA_WIDTH = 160;
constexpr uint8_t VGA_HEIGHT = 50;

void genCharacter(uint16_t position, char c, uint8_t fg = VGA_COLOR_WHITE) {
	if(!font) font = TTF_OpenFont("font.ttf", 32);
	if(charsData[position].surface != NULL) SDL_FreeSurface(charsData[position].surface);
	if(charsData[position].texture != NULL) SDL_DestroyTexture(charsData[position].texture);
	int x = position % VGA_WIDTH;
	int y = position / VGA_WIDTH;
	charsData[position].fg = fg;
	charsData[position].c = c;
	charsData[position].rect.x = x * (1600 / VGA_WIDTH);
	charsData[position].rect.y = y * (900 / VGA_HEIGHT);
	charsData[position].rect.w = (1600 / VGA_WIDTH);
	charsData[position].rect.h = (900 / VGA_HEIGHT);
	charsData[position].C[0] = c;
	charsData[position].surface = TTF_RenderText_Solid(font, charsData[position].C, Colors[fg]);
	charsData[position].texture = SDL_CreateTextureFromSurface(renderer, charsData[position].surface);
}

void renderCharacter(uint16_t position, char c, uint8_t bg = VGA_COLOR_BLACK, uint8_t fg = VGA_COLOR_WHITE) {
	if(charsData[position].c != c || charsData[position].fg != fg) genCharacter(position, c, fg);
	int y = position / VGA_WIDTH;
	int x = position % VGA_WIDTH;
	SDL_SetRenderDrawColor(renderer, Colors[bg].r, Colors[bg].g, Colors[bg].b, Colors[bg].a);
	SDL_RenderFillRect(renderer, &charsData[position].rect);
	SDL_RenderCopy(renderer, charsData[position].texture, NULL, &charsData[position].rect);
}

bool _shutdown = false;

void graphicsloop() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_Event e;
	while(SDL_PollEvent(&e) != 0) {
		if(e.type == SDL_QUIT) {
			_shutdown = true;
		} else if(e.type == SDL_KEYDOWN) {
			interrupt(INT_KEYBOARD_DATA_READY, (uint64_t)e.key.keysym.sym, 0, _cores[0]);
		}
	}
	for(size_t i = 2048; i < 18048; i += 2) {
		renderCharacter(i, memory[i], memory[i + 1] & 0x0F, (memory[i + 1] & 0xF0) >> 4);
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(10);
}

void cleanupgraphics() {
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* const argv[]) {
	std::string binaryfile = "";
	std::string driveimage = "";
	
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			switch(argv[i][1]) {
				case 'h': {
					help();
					return 0;
				}
				case 'd': {
					if(i + 1 < argc) {
						i++;
						driveimage = argv[i];
					} else {
						std::cerr << "option -d requires an argument after it.\n";
						std::cout << "try option -h for a help message." << std::endl;
						return -1;
					}
					break;
				}
				case 'c': {
					if(i + 2 < argc) {
						i += 2;
						uint64_t size = 0;
						bool found = false;
						for(int j = 0; argv[i][j]; j++) switch(argv[i][j]) {
							case 'K': { argv[i][j] = argv[i][j + 1] = 0; size = atoll(argv[i]) * 1024; found = true; break; }
							case 'M': { argv[i][j] = argv[i][j + 1] = 0; size = atoll(argv[i]) * 1048576; found = true; break; }
							case 'G': { argv[i][j] = argv[i][j + 1] = 0; size = atoll(argv[i]) * 1073741824; found = true; break; }
						}
						if(!found) size = atoll(argv[i]);
						makedriveimage(argv[i - 1], size);
					} else {
						std::cerr << "option -c requires two argument after it.\n";
						std::cout << "try option -h for a help message." << std::endl;
						return -1;
					}
					return 0;
				}
				case 'm': {
					if(i + 1 < argc) {
						i++;
						bool found = false;
						for(int j = 0; argv[i][j]; j++) switch(argv[i][j]) {
							case 'K': { argv[i][j] = argv[i][j + 1] = 0; memorysize = atoll(argv[i]) * 1024; found = true; break; }
							case 'M': { argv[i][j] = argv[i][j + 1] = 0; memorysize = atoll(argv[i]) * 1048576; found = true; break; }
							case 'G': { argv[i][j] = argv[i][j + 1] = 0; memorysize = atoll(argv[i]) * 1073741824; found = true; break; }
						}
						if(!found) memorysize = atoll(argv[i]);
					} else {
						std::cerr << "option -m requires an argument after it.\n";
						std::cout << "try option -h for a help message." << std::endl;
						return -1;
					}
					break;
				}
				case 'f': {
					if(i + 1 < argc) {
						i++;
						bool found = false;
						for(int j = 0; argv[i][j]; j++) switch(argv[i][j]) {
							case 'K': { argv[i][j] = argv[i][j + 1] = 0; frequency = atoll(argv[i]) * 1024; found = true; break; }
							case 'M': { argv[i][j] = argv[i][j + 1] = 0; frequency = atoll(argv[i]) * 1048576; found = true; break; }
						}
						if(!found) frequency = atoll(argv[i]);
					} else {
						std::cerr << "option -f requires an argument after it.\n";
						std::cout << "try option -h for a help message." << std::endl;
						return -1;
					}
					break;
				}
				case 'V': {
					printversion();
					return 0;
				}
				case '-': {
					if(!strcmp(argv[i] + 2, "32")) {
						bits = 32;
					} else if(!strcmp(argv[i] + 2, "64")) {
						bits = 64;
					} else {
						std::cerr << "unrecognized option \"" << argv[i] << "\".\n";
						std::cout << "try option -h for a help message." << std::endl;
						return -1;
					}
					break;
				}
				default: {
					std::cerr << "unrecognized option \"" << argv[i] << "\".\n";
					std::cout << "try option -h for a help message." << std::endl;
					return -1;
				}
			}
		} else {
			if(binaryfile == "") binaryfile = argv[i];
			else {
				help();
				return -1;
			}
		}
	}
	if(binaryfile == "" && driveimage == "") {
		help();
		return -1;
	}
	
	try {
		memory = new uint8_t[memorysize];
	} catch(std::bad_alloc& e) {
		uint64_t humanreadable = memorysize;
		char unit = 0;
		if(humanreadable > 1024) { humanreadable /= 1024; unit = 'K'; }
		if(humanreadable > 1024) { humanreadable /= 1024; unit = 'M'; }
		if(humanreadable > 1024) { humanreadable /= 1024; unit = 'G'; }
		std::cerr << "Failed to allocate memory - not enough system memory available (tried to allocate ";
		std::cerr << humanreadable << unit << "B.)" << std::endl;
		std::cout << "Try allocating less memory with the -m option." << std::endl;
		return -2;
	}
	
	for(size_t i = 0; i < memorysize; i++) {
		memory[i] = 0;
	}

	std::vector<std::thread*> threads;

	for(uint64_t i = 0; i < cores; i++) {
		_cores.push_back(new core_t);
		_cores[i]->id = _cores.size() - 1;
		if(i == 0) {
			_cores[0]->regs[rpc]->setvalue(18048);
		}
		threads.push_back(new std::thread(corehandlercall, _cores[i], _cores[i]->promise.get_future()));
	}

	if(driveimage != "") {
		drive.open(driveimage, std::ios::in | std::ios::out | std::ios::binary);
		if(!drive) {
			std::cerr << "Failed to open drive image " << driveimage << "!" << std::endl;
			return -3;
		}
		drive.read((char*)memory + 18048, 512);
	} else if(binaryfile != "") {
		std::ifstream binary;
		binary.open(binaryfile, std::ios::in | std::ios::binary);
		if(!binary) {
			std::cerr << "Failed to open binary file " << binaryfile << "!" << std::endl;
			return -3;
		}
		binary.read((char*)memory + 18048, memorysize - 18048);
		binary.close();
	}

	if(!initgraphics()) {
		return -4;
	}

	while(!_shutdown) {
		graphicsloop();
	}

	cleanupgraphics();

	for(uint64_t i = 0; i < _cores.size(); i++) _cores[i]->promise.set_value();

	while(_cores.size() > 0) {
		threads[_cores.size() - 1]->join();
		delete threads[_cores.size() - 1];
		delete _cores[_cores.size() - 1];
		threads.pop_back();
		_cores.pop_back();
	}
	
	if(drive) drive.close();

	delete[] memory;
	return 0;
}