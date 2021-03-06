/*
 * The Koreh-v1 Project
 * Koreh-v1 C/C++ Compiler (ccxx)
 *
 * Copyright (C) 2021, Bryan "/dev/core" M.
 * Licensed under the Mozilla Public License 2.0
 * https://www.mozilla.org/en-US/MPL/2.0/
 *
 * This file handles the preprocessor as described in
 * Clause 5.2 paragraph 1.4 of the ISO-C++23 working draft.
 *
 * The ISO documents referenced by this compiler can be found at
 * http://open-std.org/JTC1/SC22/WG21/docs/papers/2020/n4878.pdf (C++23 Working Draft)
 * http://open-std.org/JTC1/SC22/WG14/www/docs/n2310.pdf (C2x Working Draft)
 *
 */

#include "shared.h"

std::string include(std::string file, bool search_type) {
	return "";
}

std::string preprocess(std::string in_file, std::string file_name) {
	std::ifstream ifs;
	ifs.open(in_file, std::ios::in);
	if(!ifs.is_open()) {
		std::cerr << "Fatal error: failed opening temporary input file \"" << in_file << "\"" << std::endl;
		exit(ENOENT);
	}
	std::ofstream ofs;
	std::string out_file = std::filesystem::temp_directory_path().string() + file_name + "-preprocessed-2.cpp";
	ofs.open(out_file, std::ios::out);
	if(!ofs.is_open()) {
		std::cerr << "Fatal error: failed opening temporary output file" << std::endl;
		exit(EIO);
	}



	ifs.close();
	ofs.close();
	std::filesystem::remove(std::filesystem::absolute(in_file));	// Delete temporary file
	return out_file;
}
