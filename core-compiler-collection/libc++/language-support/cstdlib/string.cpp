/* 
 * The Koreh-v1 Project
 * Koreh-v1 C/C++ Compiler (ccxx)
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
 * http://open-std.org/JTC1/SC22/WG21/docs/papers/2020/n4878.pdf (C++23 Working Draft)
 * http://open-std.org/JTC1/SC22/WG14/www/docs/n2310.pdf (C2x Working Draft)
 * 
 */

#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>

__BEGIN_NAMESPACE_STD

	// todo: locale

	long int atol(const char* nptr) { return strtol(nptr, NULL, 10); }
	double atof(const char* nptr) { return strtod(nptr, nullptr); }
	int atoi(const char* nptr) { return strtol(nptr, nullptr, 10); }
	long int atol(const char* nptr) { return strtol(nptr, nullptr, 10); }

# if __ARCH == 64 && __cplusplus >= 201103L
	long long int atoll(const char* nptr) { return strtoll(nptr, nullptr, 10); }
# endif // __ARCH == 64 && __cplusplus >= 201103L

	double strtod(const char* nptr, char** endptr) {
		if(!nptr) return 0;
		while(isspace(*nptr)) nptr++;						// Skip all whitespaces
		double value = 0;
		int sign = 1;
		int factor = 10;
		if(*nptr == '+' || *nptr == '-') {					// Check for sign
			if(*nptr == '-') sign = -1;
			nptr++;											// Move to the next character
		}
#if __cplusplus >= 201103L									// C++11 adds support for NAN, INF/INFINITY and hex numbers in 0x formatting
		if(!isdigit(*nptr)) {								// Not a character, check for NAN/INF/INFINITY
			if(tolower(*nptr) == 'n' && tolower(*(nptr + 1)) == 'a' && tolower(*(nptr + 2)) == 'n') return numeric_limits<double::signaling_NaN();
			if(tolower(*nptr) == 'i' && tolower(*(nptr + 1)) == 'n' && tolower(*(nptr + 2)) == 'f' && *(nptr + 3) == 0) return numeric_limits<double>::infinity();
			if(tolower(*nptr) == 'i' && tolower(*(nptr + 1)) == 'n' && tolower(*(nptr + 2)) == 'f' && tolower(*(nptr + 3)) == 'i' && \
			   tolower(*(nptr + 4)) == 'n' && tolower(*(nptr + 5)) == 'i' && tolower(*(nptr + 6)) == 't' && tolower(*(nptr + 7)) == 'y' && \
			  *(nptr + 8) == 0) return numeric_limits<double>::infinity();
		}
		if(*nptr == '0' && tolower(*(nptr + 1)) == 'x') {	// 0x indicates a hex number
			nptr + 2;										// Move two characters forward
			factor = 16;									// Factor is now 16
		}
		while(isdigit(*nptr) || (factor == 16 && (tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f'))) {
			if(tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f') {
				value *= 16;								// Multiply the value by the factor (16) as we are now on the next digit
				value += (double)(tolower(*nptr) - 'a' + 10); // Add the value of the character (lowercase character - a + 10)
				nptr++;										// Step to next character
				continue;									// Go back to the top of the loop
			}
#else
		while(isdigit(*nptr)) {
#endif // __cplusplus < 201103L
			value *= factor;								// Multiply the value by the factor as we are now on the next digit
			value += (double)(*nptr - '0');					// Add the value of the character
			nptr++;											// Step to next character
		}
		if(*nptr == '.') {									// Found a dot
			nptr++;											// Step to the next character
			int count = 0;									// Decimal place counter
#if __cplusplus >= 201103L									// C++11 adds support for hex numbers in 0x formatting
			while(isdigit(*nptr) || (factor == 16 && (tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f'))) {
			if(tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f') {
				value += (double)(tolower(*nptr) - 'a' + 10) / pow(16, count + 1); // Add the value of the character divided by
															// factor^(count+1) as we are adding a number in the decimal place
				count++;									// Increase decimal place counter
				nptr++;										// Step to next character
				continue;									// Go back to the top of the loop
			}
#else
			while(isdigit(*nptr)) {
#endif // __cplusplus < 201103L
				value += (double)(*nptr - '0') / pow(factor, count + 1); // Add the value of the character divided by factor^(count+1)
															// as we are adding a number in the decimal place
				count++;									// Increase decimal place counter
				nptr++;										// Step to next character
			}
			if((tolower(*nptr) == 'e' && factor == 10) || \
			   (tolower(*nptr) == 'p' && factor == 16)) {	// Scientific notation
				nptr++;										// Step to next character
				double exponent = 0;						// Keep track of the exponent
				int expsign = 1;							// Keep track of the exponent sign
				if(*nptr == '+' || *nptr == '-') {
					if(*nptr == '-') expsign = -1;			// Set exponent sign to -
					nptr++;									// Step to next character
				}
				while(isdigit(*nptr)) {
					exponent *= 10;							// Next digit, so multiply exponent by 10
					exponent += (double)(*nptr - '0');		// Add the value of the character
					nptr++;
				}
				if(factor == 10) value *= pow(10, exponent * expsign);
				else value *= pow(2, exponent * expsign);
			}
		}
		nptr++;												// Step to next character
		if(endptr != nullptr) *endptr = nptr;				// Set endptr to the current position
		return value * sign;
	}

	float strtof(const char* nptr, char** endptr) {
		if(!nptr) return 0;
		while(isspace(*nptr)) nptr++;						// Skip all whitespaces
		float value = 0;
		int sign = 1;
		int factor = 10;
		if(*nptr == '+' || *nptr == '-') {					// Check for sign
			if(*nptr == '-') sign = -1;
			nptr++;											// Move to the next character
		}
#if __cplusplus >= 201103L									// C++11 adds support for NAN, INF/INFINITY and hex numbers in 0x formatting
		if(!isdigit(*nptr)) {								// Not a character, check for NAN/INF/INFINITY
			if(tolower(*nptr) == 'n' && tolower(*(nptr + 1)) == 'a' && tolower(*(nptr + 2)) == 'n') return numeric_limits<float>::signaling_NaN();
			if(tolower(*nptr) == 'i' && tolower(*(nptr + 1)) == 'n' && tolower(*(nptr + 2)) == 'f' && *(nptr + 3) == 0) return numeric_limits<float>::infinity();
			if(tolower(*nptr) == 'i' && tolower(*(nptr + 1)) == 'n' && tolower(*(nptr + 2)) == 'f' && tolower(*(nptr + 3)) == 'i' && \
			   tolower(*(nptr + 4)) == 'n' && tolower(*(nptr + 5)) == 'i' && tolower(*(nptr + 6)) == 't' && tolower(*(nptr + 7)) == 'y' && \
			  *(nptr + 8) == 0) return numeric_limits<float>::infinity();
		}
		if(*nptr == '0' && tolower(*(nptr + 1)) == 'x') {	// 0x indicates a hex number
			nptr + 2;										// Move two characters forward
			factor = 16;									// Factor is now 16
		}
		while(isdigit(*nptr) || (factor == 16 && (tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f'))) {
			if(tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f') {
				value *= 16;								// Multiply the value by the factor (16) as we are now on the next digit
				value += (float)(tolower(*nptr) - 'a' + 10);// Add the value of the character (lowercase character - a + 10)
				nptr++;										// Step to next character
				continue;									// Go back to the top of the loop
			}
#else
		while(isdigit(*nptr)) {
#endif // __cplusplus < 201103L
			value *= factor;								// Multiply the value by the factor as we are now on the next digit
			value += (float)(*nptr - '0');					// Add the value of the character
			nptr++;											// Step to next character
		}
		if(*nptr == '.') {									// Found a dot
			nptr++;											// Step to the next character
			int count = 0;									// Decimal place counter
#if __cplusplus >= 201103L									// C++11 adds support for hex numbers in 0x formatting
			while(isdigit(*nptr) || (factor == 16 && (tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f'))) {
			if(tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f') {
				value += (float)(tolower(*nptr) - 'a' + 10) / pow(16, count + 1); // Add the value of the character divided by
															// factor^(count+1) as we are adding a number in the decimal place
				count++;									// Increase decimal place counter
				nptr++;										// Step to next character
				continue;									// Go back to the top of the loop
			}
#else
			while(isdigit(*nptr)) {
#endif // __cplusplus < 201103L
				value += (float)(*nptr - '0') / pow(factor, count + 1); // Add the value of the character divided by factor^(count+1)
															// as we are adding a number in the decimal place
				count++;									// Increase decimal place counter
				nptr++;										// Step to next character
			}
			if((tolower(*nptr) == 'e' && factor == 10) || \
			   (tolower(*nptr) == 'p' && factor == 16)) {	// Scientific notation
				nptr++;										// Step to next character
				float exponent = 0;							// Keep track of the exponent
				int expsign = 1;							// Keep track of the exponent sign
				if(*nptr == '+' || *nptr == '-') {
					if(*nptr == '-') expsign = -1;			// Set exponent sign to -
					nptr++;									// Step to next character
				}
				while(isdigit(*nptr)) {
					exponent *= 10;							// Next digit, so multiply exponent by 10
					exponent += (float)(*nptr - '0');		// Add the value of the character
					nptr++;
				}
#if __cplusplus >= 201103L									// powf introduced in C++11
				if(factor == 10) value *= powf(10, exponent * expsign);
				else value *= powf(2, exponent * expsign);
#else
				if(factor == 10) value *= pow(10, exponent * expsign);
				else value *= pow(2, exponent * expsign);
#endif // __cplusplus >= 201103L
			}
		}
		nptr++;												// Step to next character
		if(endptr != nullptr) *endptr = nptr;				// Set endptr to the current position
		return value * sign;
	}

	long double strtold(const char* nptr, char** endptr) {
		if(!nptr) return 0;
		while(isspace(*nptr)) nptr++;						// Skip all whitespaces
		long double value = 0;
		int sign = 1;
		int factor = 10;
		if(*nptr == '+' || *nptr == '-') {					// Check for sign
			if(*nptr == '-') sign = -1;
			nptr++;											// Move to the next character
		}
#if __cplusplus >= 201103L									// C++11 adds support for NAN, INF/INFINITY and hex numbers in 0x formatting
		if(!isdigit(*nptr)) {								// Not a character, check for NAN/INF/INFINITY
			if(tolower(*nptr) == 'n' && tolower(*(nptr + 1)) == 'a' && tolower(*(nptr + 2)) == 'n') return numeric_limits<long double>::signaling_NaN();
			if(tolower(*nptr) == 'i' && tolower(*(nptr + 1)) == 'n' && tolower(*(nptr + 2)) == 'f' && *(nptr + 3) == 0) return numeric_limits<long double>::infinity();
			if(tolower(*nptr) == 'i' && tolower(*(nptr + 1)) == 'n' && tolower(*(nptr + 2)) == 'f' && tolower(*(nptr + 3)) == 'i' && \
			   tolower(*(nptr + 4)) == 'n' && tolower(*(nptr + 5)) == 'i' && tolower(*(nptr + 6)) == 't' && tolower(*(nptr + 7)) == 'y' && \
			  *(nptr + 8) == 0) return numeric_limits<long double>::infinity();
		}
		if(*nptr == '0' && tolower(*(nptr + 1)) == 'x') {	// 0x indicates a hex number
			nptr + 2;										// Move two characters forward
			factor = 16;									// Factor is now 16
		}
		while(isdigit(*nptr) || (factor == 16 && (tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f'))) {
			if(tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f') {
				value *= 16;								// Multiply the value by the factor (16) as we are now on the next digit
				value += (long double)(tolower(*nptr) - 'a' + 10); // Add the value of the character (lowercase character - a + 10)
				nptr++;										// Step to next character
				continue;									// Go back to the top of the loop
			}
#else
		while(isdigit(*nptr)) {
#endif // __cplusplus < 201103L
			value *= factor;								// Multiply the value by the factor as we are now on the next digit
			value += (long double)(*nptr - '0');			// Add the value of the character
			nptr++;											// Step to next character
		}
		if(*nptr == '.') {									// Found a dot
			nptr++;											// Step to the next character
			int count = 0;									// Decimal place counter
#if __cplusplus >= 201103L									// C++11 adds support for hex numbers in 0x formatting
			while(isdigit(*nptr) || (factor == 16 && (tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f'))) {
			if(tolower(*nptr) >= 'a' && tolower(*nptr) <= 'f') {
				value += (long double)(tolower(*nptr) - 'a' + 10) / pow(16, count + 1); // Add the value of the character divided by
															// factor^(count+1) as we are adding a number in the decimal place
				count++;									// Increase decimal place counter
				nptr++;										// Step to next character
				continue;									// Go back to the top of the loop
			}
#else
			while(isdigit(*nptr)) {
#endif // __cplusplus < 201103L
				value += (long double)(*nptr - '0') / pow(factor, count + 1); // Add the value of the character divided by factor^(count+1)
															// as we are adding a number in the decimal place
				count++;									// Increase decimal place counter
				nptr++;										// Step to next character
			}
			if((tolower(*nptr) == 'e' && factor == 10) || \
			   (tolower(*nptr) == 'p' && factor == 16)) {	// Scientific notation
				nptr++;										// Step to next character
				long double exponent = 0;					// Keep track of the exponent
				int expsign = 1;							// Keep track of the exponent sign
				if(*nptr == '+' || *nptr == '-') {
					if(*nptr == '-') expsign = -1;			// Set exponent sign to -
					nptr++;									// Step to next character
				}
				while(isdigit(*nptr)) {
					exponent *= 10;							// Next digit, so multiply exponent by 10
					exponent += (long double)(*nptr - '0');	// Add the value of the character
					nptr++;
				}
#if __cplusplus >= 201103L									// powl introduced in C++11
				if(factor == 10) value *= powl(10, exponent * expsign);
				else value *= powl(2, exponent * expsign);
#else
				if(factor == 10) value *= pow(10, exponent * expsign);
				else value *= pow(2, exponent * expsign);
#endif // __cplusplus >= 201103L
			}
		}
		nptr++;												// Step to next character
		if(endptr != nullptr) *endptr = nptr;				// Set endptr to the current position
		return value * sign;
	}

	long int strtol(const char* nptr, char** endptr, int base) {
		if(!nptr) return 0;
		while(isspace(*nptr)) nptr++;						// Skip all whitespaces
		int value = 0;
		int sign = 1;
		if(*nptr == '+' || *nptr == '-') {					// Check sign
			if(*nptr == '-') sign = -1;
			nptr++;											// Step to next character
		}
		if(base == 0 || base == 8) if(*nptr == '0' && isdigit(*nptr + 1)) { // identifier 0 for base 8
			base = 8;
			nptr++;											// Step to next character
		}
		if(base == 0 || base == 16) if(*nptr == '0' && *(nptr + 1) == 'x' && isdigit(*nptr + 2)) { // identifier 0x for hex
			base = 16;
			nptr++;											// Step to next character
		}
		while((isdigit(*nptr) && (*nptr - '0' < base)) || (tolower(*nptr) - 'a' + 10 < base)) {
			value *= base;									// Multiply value by base (next character)
			if(isdigit(*nptr)) value += (long)(*nptr - '0');// Add value of character
			else value += (long)(tolower(*nptr) - 'a' + 10);// Add value of character
			nptr++;											// Step to next character
		}
		nptr++;												// Step to next character
		if(endptr != nullptr) *endptr = nptr;				// Set endptr to the current position
		return value * sign;
	}

# if __ARCH == 64 && __cplusplus >= 201103L
	long long int strtoll(const char* nptr, char** endptr, int base) {
		if(!nptr) return 0;
		while(isspace(*nptr)) nptr++;						// Skip all whitespaces
		long long value = 0;
		int sign = 1;
		if(*nptr == '+' || *nptr == '-') {					// Check sign
			if(*nptr == '-') sign = -1;
			nptr++;											// Step to next character
		}
		if(base == 0 || base == 8) if(*nptr == '0' && isdigit(*nptr + 1)) { // identifier 0 for base 8
			base = 8;
			nptr++;											// Step to next character
		}
		if(base == 0 || base == 16) if(*nptr == '0' && *(nptr + 1) == 'x' && isdigit(*nptr + 2)) { // identifier 0x for hex
			base = 16;
			nptr++;											// Step to next character
		}
		while((isdigit(*nptr) && (*nptr - '0' < base)) || (tolower(*nptr) - 'a' + 10 < base)) {
			value *= base;									// Multiply value by base (next character)
			if(isdigit(*nptr)) value += (long long)(*nptr - '0'); // Add value of character
			else value += (long long)(tolower(*nptr) - 'a' + 10); // Add value of character
			nptr++;											// Step to next character
		}
		nptr++;												// Step to next character
		if(endptr != nullptr) *endptr = nptr;				// Set endptr to the current position
		return value * sign;
	}
# endif // __ARCH == 64 && __cplusplus >= 201103L

	unsigned long int strtoul(const char* nptr, char** endptr, int base) {
		if(!nptr) return 0;
		while(isspace(*nptr)) nptr++;						// Skip all whitespaces
		unsigned long value = 0;
		if(base == 0 || base == 8) if(*nptr == '0' && isdigit(*nptr + 1)) { // identifier 0 for base 8
			base = 8;
			nptr++;											// Step to next character
		}
		if(base == 0 || base == 16) if(*nptr == '0' && *(nptr + 1) == 'x' && isdigit(*nptr + 2)) { // identifier 0x for hex
			base = 16;
			nptr++;											// Step to next character
		}
		while((isdigit(*nptr) && (*nptr - '0' < base)) || (tolower(*nptr) - 'a' + 10 < base)) {
			value *= base;									// Multiply value by base (next character)
			if(isdigit(*nptr)) value += (unsigned long)(*nptr - '0'); // Add value of character
			else value += (unsigned long)(tolower(*nptr) - 'a' + 10); // Add value of character
			nptr++;											// Step to next character
		}
		nptr++;												// Step to next character
		if(endptr != nullptr) *endptr = nptr;				// Set endptr to the current position
		return value;
	}

# if __ARCH == 64 && __cplusplus >= 201103L
	unsigned long long int strtoull(const char* nptr, char** endptr, int base) {
		if(!nptr) return 0;
		while(isspace(*nptr)) nptr++;						// Skip all whitespaces
		unsigned long long value = 0;
		if(base == 0 || base == 8) if(*nptr == '0' && isdigit(*nptr + 1)) { // identifier 0 for base 8
			base = 8;
			nptr++;											// Step to next character
		}
		if(base == 0 || base == 16) if(*nptr == '0' && *(nptr + 1) == 'x' && isdigit(*nptr + 2)) { // identifier 0x for hex
			base = 16;
			nptr++;											// Step to next character
		}
		while((isdigit(*nptr) && (*nptr - '0' < base)) || (tolower(*nptr) - 'a' + 10 < base)) {
			value *= base;									// Multiply value by base (next character)
			if(isdigit(*nptr)) value += (unsigned long long)(*nptr - '0'); // Add value of character
			else value += (unsigned long long)(tolower(*nptr) - 'a' + 10); // Add value of character
			nptr++;											// Step to next character
		}
		nptr++;												// Step to next character
		if(endptr != nullptr) *endptr = nptr;				// Set endptr to the current position
		return value;
	}
# endif // __ARCH == 64 && __cplusplus >= 201103L

	int mblen(const char* s, size_t n) {
		if(!s || !*s) return 0;

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
