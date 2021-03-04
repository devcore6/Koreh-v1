#include <emulator.h>

uint64_t cores = 8;
uint64_t frequency = 1000000;
uint8_t bits = 64;
uint64_t memorysize = 268435456; // 256 MB
uint8_t* memory;

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
	std::cout << "         -c <driveimage> <size[K|M|G]>    Creates a drive image <driveimage> of the given size.\n";
	std::cout << "         -V                               print version information.\n";
	std::cout << "         --32                             emulates a 32-bit system.";
	std::cout << "         --64                             emulates a 64-bit system.";
	std::cout << std::endl;

}

void makedriveimage(char* const path, uint64_t size) {

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
						for(int j = 0; argv[i][j]; j++) switch(argv[i][j]) {
							case 'K': { argv[i][j] = argv[i][j + 1] = 0; size = atoi(argv[i]) * 1024; break; }
							case 'M': { argv[i][j] = argv[i][j + 1] = 0; size = atoi(argv[i]) * 1048576; break; }
							case 'G': { argv[i][j] = argv[i][j + 1] = 0; size = atoi(argv[i]) * 1073741824; break; }
						}
						makedriveimage(argv[i - 1], size);
					} else {
						std::cerr << "option -c requires two argument after it.\n";
						std::cout << "try option -h for a help message." << std::endl;
						return -1;
					}
					return 0;
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
	if(binaryfile == "") {
		help();
		return -1;
	}
	
	memory = new uint8_t[memorysize];



	delete[] memory;
	return 0;
}