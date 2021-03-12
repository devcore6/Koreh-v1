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

__BEGIN_NAMESPACE_STD

	void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*)) {

	}

	void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*)) {

	}

	int rand() {

	}

	void srand(unsigned int seed) {

	}
	
__END_NAMESPACE_STD
