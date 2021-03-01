#include <asm.h>

std::vector<unsigned char> binarydata;

bool bootable = false;
uint8_t mode = 64;
size_t errors = 0;

void printversion() {
	std::cout << "core-asm v" << ((version & 0xFF000000) >> 24) << "." << \
		((version & 0x00FF0000) >> 16) << "." << \
		((version & 0x0000FF00) >> 8) << \
		((version & 0x00000001) ? "a" : (version & 0x00000002) ? "b" : "") << "\n";
	std::cout << "core compiler collection v" << ((collectionversion & 0xFF000000) >> 24) << "." << \
		((collectionversion & 0x00FF0000) >> 16) << "." << \
		((collectionversion & 0x0000FF00) >> 8) << \
		((collectionversion & 0x00000001) ? "a" : (version & 0x00000002) ? "b" : "") << std::endl;

}

void help() {
	printversion();
	std::cout << "\n";
	std::cout << "usage: casm <infile> [-o <outfile>] [options]\n";
	std::cout << "\n";
	std::cout << "options:\n";
	std::cout << "         -h               show this help message\n";
	std::cout << "         -o <outfile>     sets the output file to <outfile>. If not specified,\n";
	std::cout << "                          the output file is <infile>.o by default.\n";
	std::cout << "         -V               print version information.\n";
	std::cout << "         -b               builds in a bootable format.\n";
	std::cout << "         --32             builds for 32-bit targets (compatible with 64-bit systems too).\n";
	std::cout << "         --64             builds for 64-bit targets (default).";
	std::cout << std::endl;
}

extern int yyparse();
extern FILE* yyin;

extern int yydebug;

int main(int argc, char* const argv[]) {
	yydebug = 1;
	std::string inFile = "";
	std::string outFile = "";
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			switch(argv[i][1]) {
				case 'h': {
					help();
					return 0;
				}
				case 'o': {
					if(i + 1 < argc) {
						i++;
						outFile = argv[i];
					} else {
						std::cerr << "option -o requires an argument after it.\n";
						std::cout << "try option -h for a help message." << std::endl;
						return -1;
					}
					break;
				}
				case 'V': {
					printversion();
					return 0;
				}
				case 'b': {
					bootable = true;
					break;
				}
				case '-': {
					if(!strcmp(argv[i] + 2, "32")) {
						mode = 32;
					} else if(!strcmp(argv[i] + 2, "64")) {
						mode = 32;
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
			if(inFile == "") inFile = argv[i];
			else {
				help();
				return -1;
			}
		}
	}
	if(inFile == "") {
		help();
		return -1;
	}
	if(outFile == "") outFile = inFile + ".o";
	std::ifstream in;
	in.open(inFile, std::ios::in);
	if(!in.is_open()) {
		std::cerr << "Fatal error! Failed to open input file \"" << inFile << "\"" << std::endl;
		return -1;
	}
	std::ofstream out;
	out.open(std::filesystem::temp_directory_path() / inFile, std::ios::out);
	if(!out.is_open()) {
		in.close();
		std::cerr << "Fatal error! Failed to open temporary output file" << std::endl;
		return -1;
	}
	char buf[8192] = "";
	in.getline(buf, 8192);
	while(in.good()) {
		if(strchr(buf, '#')) *strchr(buf, '#') = 0;
		out << buf << '\n';
		in.getline(buf, 8192);
	}
	out.close();
	in.close();
	yyin = fopen((std::filesystem::temp_directory_path() / inFile).string().c_str(), "r");
	if(!yyin) {
		std::cerr << "Fatal error! Failed to open input file \"" << inFile << "\"" << std::endl;
		return -1;
	}
	yyparse();
	fclose(yyin);
	std::filesystem::remove(std::filesystem::temp_directory_path() / inFile);
	if(errors != 0) {
		std::cerr << "Compilation failed - errors occured!" << std::endl;
		return errors;
	}
	out.open(outFile, std::ios::out | std::ios::binary);
	if(!out.is_open()) {
		std::cerr << "Fatal error: Couldn't open output file \"" << outFile << "\"" << std::endl;
		return -1;
	}
	for(size_t i = 0; i < binarydata.size(); i++) out << binarydata[i];
	out.close();
	return 0;
}