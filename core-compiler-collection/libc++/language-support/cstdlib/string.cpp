/* 
 * The Koreh-v1 Project
 * Koreh-v1 C++ Compiler (ccxx)
 * 
 * Copyright (C) 2021, Bryan "/dev/core" M.
 * Licensed under the Mozilla Public License 2.0
 * https://www.mozilla.org/en-US/MPL/2.0/
 * 
 * Common language definitions as defined in
 * Clause 17.2 of the ISO-C++ 23 working draft.
 * 
 * Matching header <cstdlib>
 * 
 * The ISO documents referenced by this compiler can be found at
 * http://open-std.org/JTC1/SC22/WG21/docs/papers/2020/n4878.pdf
 * 
 */

#include <cstdlib>
#include <cctype>
#include <cmath>

__BEGIN_NAMESPACE_STD

	double atof(const char* nptr) {
		double value = 0;
		int sign = 1;
		if(*nptr == '+' || *nptr == '-') {
			if(*nptr == '-') sign = -1;
			nptr++;
		}
		while(isdigit(*nptr)) {
			value *= 10;
			value += (int)(*nptr - '0');
			nptr++;
		}
		if(*nptr == '.') {
			nptr++;
			int count = 0;
			while(isdigit(*nptr)) {
				value += (double)(*nptr - '0') / pow(10, count + 1);
				nptr++;
			}
			if(*nptr == 'e' || *nptr == 'E') {

			}
		}
		return (value * sign);
	}

	int atoi(const char* nptr) {
		int value = 0;
		int sign = 1;
		if(*nptr == '+' || *nptr == '-') {
			if(*nptr == '-') sign = -1;
			nptr++;
		}
		while(isdigit(*nptr)) {
			value *= 10;
			value += (int)(*nptr - '0');
			nptr++;
		}
		return (value * sign);
	}

	long int atol(const char* nptr) {
		long value = 0;
		int sign = 1;
		if(*nptr == '+' || *nptr == '-') {
			if(*nptr == '-') sign = -1;
			nptr++;
		}
		while(isdigit(*nptr)) {
			value *= 10;
			value += (long)(*nptr - '0');
			nptr++;
		}
		return (value * sign);
	}

	long long int atoll(const char* nptr) {
		long long value = 0;
		int sign = 1;
		if(*nptr == '+' || *nptr == '-')     {
			if(*nptr == '-') sign = -1;
			nptr++;
		}
		while(isdigit(*nptr)) {
			value *= 10;
			value += (long long)*nptr - '0';
			nptr++;
		}
		return (value * sign);
	}

	double strtod(const char* nptr, char** endptr) {

	}

	float strtof(const char* nptr, char** endptr) {

	}

	long double strtold(const char* nptr, char** endptr) {

	}

	long int strtol(const char* nptr, char** endptr, int base) {

	}

	long long int strtoll(const char* nptr, char** endptr, int base) {

	}

	unsigned long int strtoul(const char* nptr, char** endptr, int base) {

	}

	unsigned long long int strtoull(const char* nptr, char** endptr, int base) {

	}

	int mblen(const char* s, size_t n) {

	}

	int mbtowc(wchar_t* pwc, const char* s, size_t n) {

	}

	int wctomb(char* s, wchar_t wchar) {

	}

	size_t mbstowcs(wchar_t* pwcs, const char* s, size_t n) {

	}

	size_t wcstombs(char* s, const wchar_t* pwcs, size_t n) {

	}

__END_NAMESPACE_STD
