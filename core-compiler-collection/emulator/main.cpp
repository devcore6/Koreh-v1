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
	if(binaryfile == "") {
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

	std::vector<std::thread*> threads;

	_cores.push_back(new core_t);
	_cores[0]->id = 0;

	for(uint64_t i = 1; i < cores; i++) {
		_cores.push_back(new core_t);
		_cores[i]->id = _cores.size() - 1;
		threads.push_back(new std::thread(corehandlercall, _cores[i], _cores[i]->promise.get_future()));
	}

	bool shutdown = false;
	const long double tickduration = 1.0L / (long double)frequency; // long double is 64-bit double on MSVC and either 80 or 96-bit on GCC

	std::chrono::high_resolution_clock::time_point lasttime = std::chrono::high_resolution_clock::now();

	while(!shutdown) {
		corehandler(_cores[0]);
		long double duration = std::chrono::duration_cast<std::chrono::duration<long double>>(std::chrono::high_resolution_clock::now() - lasttime).count();
		if(duration < tickduration) std::this_thread::sleep_for(std::chrono::duration<long double>(tickduration - duration));
	}

	for(uint64_t i = 1; i < _cores.size(); i++) _cores[i]->promise.set_value();

	while(_cores.size() > 1) {
		threads[_cores.size() - 2]->join();
		delete threads[_cores.size() - 2];
		delete _cores[_cores.size() - 1];
		threads.pop_back();
		_cores.pop_back();
	}

	delete[] memory;
	return 0;
}