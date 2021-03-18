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

#ifdef __LIBCPP_IS_KERNEL
	void* do_aligned_alloc(size_t alignment, size_t size) {

	}

	void* do_calloc(size_t nmemb, size_t size) {

	}

	void do_free(void* ptr) {

	}

	void* do_malloc(size_t size) {

	}
	
	void* do_realloc(void* ptr, size_t size) {

	}
#endif // __LIBCPP_IS_KERNEL

void* aligned_alloc(size_t alignment, size_t size) {
#ifdef __LIBCPP_IS_KERNEL
	do_alligned_alloc(alignment, size);
#else
	// todo: kernel call whenever kernel is a thing

#endif
}

void* calloc(size_t nmemb, size_t size) {
#ifdef __LIBCPP_IS_KERNEL
	do_calloc(alignment, size);
#else
	// todo: kernel call whenever kernel is a thing
	
#endif
}

void free(void* ptr) {
#ifdef __LIBCPP_IS_KERNEL
	do_free(alignment, size);
#else
	// todo: kernel call whenever kernel is a thing
	
#endif
}

void* malloc(size_t size) {
#ifdef __LIBCPP_IS_KERNEL
	do_malloc(alignment, size);
#else
	// todo: kernel call whenever kernel is a thing
	
#endif
}

void* realloc(void* ptr, size_t size) {
#ifdef __LIBCPP_IS_KERNEL
	do_realloc(alignment, size);
#else
	// todo: kernel call whenever kernel is a thing
	
#endif
}

__END_NAMESPACE_STD
