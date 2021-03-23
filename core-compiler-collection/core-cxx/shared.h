/*
 * The Koreh-v1 Project
 * Koreh-v1 C/C++ Compiler (ccxx)
 *
 * Copyright (C) 2021, Bryan "/dev/core" M.
 * Licensed under the Mozilla Public License 2.0
 * https://www.mozilla.org/en-US/MPL/2.0/
 * 
 * Includes all the standard library headers used in just about
 * Every single source file for the compiler
 *
 * The ISO documents referenced by this compiler can be found at
 * http://open-std.org/JTC1/SC22/WG21/docs/papers/2020/n4878.pdf (C++23 Working Draft)
 * http://open-std.org/JTC1/SC22/WG14/www/docs/n2310.pdf (C2x Working Draft)
 * 
 */

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <regex>

#include <cerrno>

// 00-main.cpp
extern bool __c__; // set when compiling a C-file instead of C++

// 01-character-mapping.hpp
#include "01-character-mapping.hpp"

// 02-line-splicing.cpp
extern std::string splice_lines(std::string in_file, std::string file_name);

// 03-cleanup.cpp
extern std::string cleanup(std::string in_file, std::string file_name);

// 04-preprocessor.cpp
extern std::string include(std::string file, bool search_type);
extern std::string preprocess(std::string in_file, std::string file_name);
