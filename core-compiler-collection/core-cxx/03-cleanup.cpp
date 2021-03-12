/*
 * The Koreh-v1 Project
 * Koreh-v1 C++ Compiler (ccxx)
 * 
 * Copyright (C) 2021, Bryan "/dev/core" M.
 * Licensed under the Mozilla Public License 2.0
 * https://www.mozilla.org/en-US/MPL/2.0/
 * 
 * This file replaces comments with a white space as described in
 * Clause 5.2 paragraph 1.3 of the ISO-C++ 23 working draft.
 *
 * The ISO documents referenced by this compiler can be found at
 * http://open-std.org/JTC1/SC22/WG21/docs/papers/2020/n4878.pdf
 * 
 */

#include "shared.h"

/*
 * Counts the amount of quotes in a line, returns true if the number is odd
 * Used to check if a // or /* is a comment or is part of a string literal
 */
bool countquotes(std::string str, size_t pos) {
	size_t count = 0;
	size_t _pos = 0;
	while(_pos = str.find("\"", _pos) != std::string::npos) {
		_pos++;
		count++;
	}
	return count % 2;
}

/*
 * Function returns the path to the partially processed temporary file
 * To be used in the next steps.
 */
std::string cleanup(std::string in_file, std::string file_name) {
	std::ifstream ifs;
	ifs.open(in_file, std::ios::in);
	if(!ifs.is_open()) {
		std::cerr << "Fatal error: failed opening temporary input file \"" << in_file << "\"";
		exit(ENOENT);
	}
	std::ofstream ofs;
	std::string out_file = std::filesystem::temp_directory_path().string() + file_name + "-preprocessed-1.cpp";
	ofs.open(out_file, std::ios::out);
	if(!ofs.is_open()) {
		std::cerr << "Fatal error: failed opening temporary output file";
		exit(EIO);
	}
	std::string line;
	bool in_comment = false;
	while(std::getline(ifs, line)) {
		size_t pos = line.find("/*");
		while(pos != std::string::npos) {							// Found /* comment
			in_comment = true;										// We are now in a comment
			ofs << line.substr(0, pos - 1) << ' ';					// Keep everything before comment and add a whitespace in place of the comment
			line.substr(0, pos + 1);								// Removes everything we've already written from the string
			pos = line.find("*/");									// Checks for matching */ in the current line
			if(pos != std::string::npos) {							// Found matching */
				in_comment = false;									// No longer in a comment
				line.substr(0, pos);								// Remove the comment from the string
				pos = line.find("/*");								// Search again and loop over
			}
		}
		if(in_comment) {											// Still in a comment from the previous line
			pos = line.find("*/");									// Search for matching */ in the current line
			if(pos == std::string::npos) continue;					// No matching */ found, skip this line
			line.substr(pos + 1);									// Matching */ found, so remove everything leading up to it from the string
			in_comment = false;										// We are no longer in a comment
		}
		if(line.find("//") != std::string::npos) {					// Found a // comment
			line.substr(0, line.find("//"));						// Removes // comments
			line = line + ' ';										// And replaces them with a whitespace
		}
		ofs << line << '\n';
	}
	ofs.close();
	ifs.close();
	std::filesystem::remove(std::filesystem::absolute(in_file));	// Delete temporary file
	return out_file;
}
