/*
 * The Koreh-v1 Project
 * Koreh-v1 C/C++ Compiler (ccxx)
 *
 * Copyright (C) 2021, Bryan "/dev/core" M.
 * Licensed under the Mozilla Public License 2.0
 * https://www.mozilla.org/en-US/MPL/2.0/
 * 
 * This file handles line splicing (backslash followed by new line)
 * Each backslash followed by new lines is deleted as defined in
 * Clause 5.2 paragraph 1.2 of the ISO-C++23 working draft.
 * 
 * The ISO documents referenced by this compiler can be found at
 * http://open-std.org/JTC1/SC22/WG21/docs/papers/2020/n4878.pdf (C++23 Working Draft)
 * http://open-std.org/JTC1/SC22/WG14/www/docs/n2310.pdf (C2x Working Draft)
 * 
 */

#include "shared.h"

/*
 * Function returns the path to the partially processed temporary file
 * To be used in the next steps.
 */
std::string splice_lines(std::string in_file, std::string file_name) {
	std::ifstream ifs;
	ifs.open(in_file, std::ios::in);
	if(!ifs.is_open()) {
		std::cerr << "Fatal error: failed opening input file \"" << in_file << "\"";
		exit(ENOENT);
	}
	std::ofstream ofs;
	std::string out_file = std::filesystem::temp_directory_path().string() + file_name + "-spliced.cpp";
	ofs.open(out_file, std::ios::out);
	if(!ofs.is_open()) {
		std::cerr << "Fatal error: failed opening temporary output file";
		exit(EIO);
	}
	std::string line;
	while(std::getline(ifs, line)) {
		ofs << line;
		if(!line.empty() && line.back() == '\\') continue;
		ofs << '\n';
	}
	ofs.close();
	ifs.close();
	return out_file;
}
