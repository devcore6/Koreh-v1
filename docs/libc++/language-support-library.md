# Instructions 
## Table of Contents
1. [config](#config)
2. [cstddef](#cstddef)

# [config](../../core-compiler-collection/libc++/include/config)

This file implements macros and configurations used by my implementation of the standard c++ library (libc++)

**synopsys:**

```c++
#define __BEGIN_NAMESPACE_STD
#define __END_NAMESPACE_STD
#define __LIBCPP_VERSION
 ```

# [cstddef](../../core-compiler-collection/libc++/include/cstddef)

This file implements common language definitions as defined in clause 17.2.1 of the ISO-C++ 23 working draft.

**synopsys:**

```c++
__BEGIN_NAMESPACE_STD
#if __ARCH == 64
	using ptrdiff_t = long long;
	using size_t = unsigned long long;
#else
	using ptrdiff_t = long;
	using size_t = unsigned long;
#endif
	using max_align_t = long double;
	using nullptr_t = decltype(nullptr);
	enum class byte : unsigned char {};
	template<class IntType>
	constexpr byte& operator<<=(byte& b, IntType shift) noexcept;
	template<class IntType>
	constexpr byte operator<<(byte b, IntType shift) noexcept;
	template<class IntType>
	constexpr byte& operator>>=(byte& b, IntType shift) noexcept;
	template<class IntType>
	constexpr byte operator>>(byte b, IntType shift) noexcept;
	constexpr byte& operator|=(byte& l, byte r) noexcept;
	constexpr byte operator|(byte l, byte r) noexcept;
	constexpr byte& operator&=(byte& l, byte r) noexcept;
	constexpr byte operator&(byte l, byte r) noexcept;
	constexpr byte& operator^=(byte& l, byte r) noexcept;
	constexpr byte operator^(byte l, byte r) noexcept;
	constexpr byte operator~(byte b) noexcept;
	template<class IntType>
	constexpr IntType to_integer(byte b) noexcept;
__END_NAMESPACE_STD

#define NULL
#define offsetof(P, D)
```

# [cstdlib](../../core-compiler-collection/libc++/include/cstddef)

This file implements common language definitions as defined in clause 17.2.2 of the ISO-C++ 23 working draft.

**synopsys:**

```c++
__BEGIN_NAMESPACE_STD
#if __ARCH == 64
	using size_t = unsigned long long;
#else
	using size_t = unsigned long;
#endif
	typedef struct div_t;
	typedef struct ldiv_t;
#if __ARCH == 64
	typedef struct lldiv_t;
#endif
__END_NAMESPACE_STD

#define NULL
#define EXIT_FAILURE
#define EXIT_SUCCESS
#define RAND_MAX
#define MB_CUR_MAX

__BEGIN_NAMESPACE_STD
	[[noreturn]] void abort() noexcept;
	int atexit(void (*func)()) noexcept;
	int at_quick_exit(void (*func)()) noexcept;
	[[noreturn]] void exit(int status);
	[[noreturn]] void _Exit(int status) noexcept;
	[[noreturn]] void quick_exit(int status) noexcept;
	char* getenv(const char* name);
	int system(const char* string);

	void* aligned_alloc(size_t alignment, size_t size);
	void* calloc(size_t nmemb, size_t size);
	void free(void* ptr);
	void* malloc(size_t size);
	void* realloc(void* ptr, size_t size);
	double atof(const char* nptr);
	int atoi(const char* nptr);
	long int atol(const char* nptr);
	long long int atoll(const char* nptr);
	double strtod(const char* nptr, char** endptr);
	float strtof(const char* nptr, char** endptr);
	long double strtold(const char* nptr, char** endptr);
	long int strtol(const char* nptr, char** endptr, int base);
	long long int strtoll(const char* nptr, char** endptr, int base);
	unsigned long int strtoul(const char* nptr, char** endptr, int base);
	unsigned long long int strtoull(const char* nptr, char** endptr, int base);

	int mblen(const char* s, size_t n);
	int mbtowc(wchar_t* pwc, const char* s, size_t n);
	int wctomb(char* s, wchar_t wchar);
	size_t mbstowcs(wchar_t* pwcs, const char* s, size_t n);
	size_t wcstombs(char* s, const wchar_t* pwcs, size_t n);

	void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
	void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

	int rand();
	void srand(unsigned int seed);

	int abs(int j);
	long int abs(long int j);
	long long int abs(long long int j);
	float abs(float j);
	double abs(double j);
	long double abs(long double j);
	long int labs(long int j);
	long long int llabs(long long int j);
	div_t div(int numer, int denom);
	ldiv_t div(long int numer, long int denom);
#if ARCH == 64
	lldiv_t div(long long int numer, long long int denom);
#endif
	ldiv_t ldiv(long int numer, long int denom);
#if ARCH == 64
	lldiv_t lldiv(long long int numer, long long int denom);
#endif
__END_NAMESPACE_STD
```

Matching source files: [abort.cpp](language-support/cstdlib/abort.cpp), [memory.cpp](language-support/cstdlib/memory.cpp), [string.cpp](language-support/cstdlib/string.cpp), [cstdlib.cpp](language-support/cstdlib/cstdlib.cpp) and [math.cpp](language-support/cstdlib/math.cpp)
