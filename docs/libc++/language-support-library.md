# Instructions 
## Table of Contents
1. [config](#config)
2. [cstddef](#cstddef)
3. [cstdlib](#cstdlib)
4. [version](#version)
5. [limits](#limits)
6. [climits](#climits)
7. [cfloat](#cfloat)
8. [cstdint](#cstdint)
9. [new](#new)
10. [typeinfo](#typeinfo)
11. [source_location](#source_location)
12. [exception](#exception)
13. [initializer_list](#initializer_list)
14. [compare](#compare)
15. [coroutine](#coroutine)
16. [cstdarg](#cstdarg)
17. [csetjmp](#csetjmp)
18. [csignal](#csignal)

# [config](../../core-compiler-collection/libc++/include/config)

This file implements macros and configurations used by my implementation of the standard c++ library (libc++)

**synopsis:**

```c++
#define __BEGIN_NAMESPACE_STD
#define __END_NAMESPACE_STD
#define __LIBCPP_VERSION

#define __CHAR_BIT__ 8
#undef __CHAR_UNSIGNED__
#define __CHAR_SIGN__

#define __INTEGRAL_TRAPS__

#if __cplusplus >= 201103L
#define __HAS_CONSTEXPR__ constexpr
#define __HAS_NOEXCEPT__ noexcept
#define __HAS_NORETURN__ [[noreturn]]
#else
#define __HAS_CONSTEXPR__
#define __HAS_NOEXCEPT__
#define __HAS_NORETURN__
#endif

#define __FLT_MIN__ 1.17549435e-38f
#define __FLT_MAX__ 3.40282347e+38f
#define __FLT_DIGITS__ 24
#define __FLT_DIGITS10__ 6
#define __FLT_RADIX__ 2
#define __FLT_EPSILON__ 1.19209290e-7f
#define __FLT_MIN_EXP__ (-125)
#define __FLT_MIN_EXP_10__ (-37)
#define __FLT_MAX_EXP__ 128
#define __FLT_MAX_EXP_10__ 38
#define __FLT_DENORM_MIN 1.40129846e-45f

#define __DBL_MIN__ 2.2250738585072014e-308
#define __DBL_MAX__ 1.7976931348623157e+308
#define __DBL_DIGITS__ 53
#define __DBL_DIGITS10__ 15
#define __DBL_EPSILON__ 2.2204460492503131e-16
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_MIN_EXP_10__ (-307)
#define __DBL_MAX_EXP__ 1024
#define __DBL_MAX_EXP_10__ 308
#define __DBL_DENORM_MIN 1.40129846e-45f

#define __LDBL_MIN__ 3.36210314311209350626e-4932l
#define __LDBL_MAX__ 1.18973149535723176502e+4932l
#define __LDBL_DIGITS__ 64
#define __LDBL_DIGITS10__ 18
#define __LDBL_EPSILON__ 1.08420217248550443401e-19l
#define __LDBL_MIN_EXP__ (-16381)
#define __LDBL_MIN_EXP_10__ (-4931)
#define __LDBL_MAX_EXP__ 16384
#define __LDBL_MAX_EXP_10__ 4932
#define __LDBL_DENORM_MIN 3.64519953188247460253e-4951l
 ```

# [cstddef](../../core-compiler-collection/libc++/include/cstddef)

This file implements common language definitions as defined in clause 17.2.1 of the ISO-C++ 23 working draft.

**synopsis:**

```c++
#define __cpp_lib_byte
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

**synopsis:**

```c++
__BEGIN_NAMESPACE_STD
#if __ARCH == 64
	using size_t = unsigned long long;
#else
	using size_t = unsigned long;
#endif
	using div_t = struct;
	using ldiv_t = struct;
#if __ARCH == 64
	using lldiv_t = struct;
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
#if __ARCH == 64 && __cplusplus >= 201103L
	long long int atoll(const char* nptr);
#endif
	double strtod(const char* nptr, char** endptr);
	float strtof(const char* nptr, char** endptr);
	long double strtold(const char* nptr, char** endptr);
	long int strtol(const char* nptr, char** endptr, int base);
#if __ARCH == 64 && __cplusplus >= 201103L
	long long int strtoll(const char* nptr, char** endptr, int base);
#endif
	unsigned long int strtoul(const char* nptr, char** endptr, int base);
#if __ARCH == 64 && __cplusplus >= 201103L
	unsigned long long int strtoull(const char* nptr, char** endptr, int base);
#endif

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
#if __ARCH == 64
	long long int llabs(long long int j);
#endif
	div_t div(int numer, int denom);
	ldiv_t div(long int numer, long int denom);
#if __ARCH == 64
	lldiv_t div(long long int numer, long long int denom);
#endif
	ldiv_t ldiv(long int numer, long int denom);
#if __ARCH == 64
	lldiv_t lldiv(long long int numer, long long int denom);
#endif
__END_NAMESPACE_STD
 ```

Matching source files: [abort.cpp](../../core-compiler-collection/libc++/language-support/cstdlib/abort.cpp), [memory.cpp](../../core-compiler-collection/libc++/language-support/cstdlib/memory.cpp), [string.cpp](../../core-compiler-collection/libc++/language-support/cstdlib/string.cpp), [cstdlib.cpp](../../core-compiler-collection/libc++/language-support/cstdlib/cstdlib.cpp) and [math.cpp](../../core-compiler-collection/libc++/language-support/cstdlib/math.cpp)

# [version](../../core-compiler-collection/libc++/include/version)

This file contains macros supplying implementation-dependent information about the C++ standard library as defined in clause 17.3.2 of the ISO-C++ 23 working draft.

```c++
#define __cpp_lib_addressof_constexpr
#define __cpp_lib_allocator_traits_is_always_equal
#define __cpp_lib_any
#define __cpp_lib_apply
#define __cpp_lib_array_constexpr
#define __cpp_lib_as_const
#define __cpp_lib_assume_aligned
#define __cpp_lib_atomic_flag_test
#define __cpp_lib_atomic_float
#define __cpp_lib_atomic_is_always_lock_free
#define __cpp_lib_atomic_lock_free_type_aliases
#define __cpp_lib_atomic_ref
#define __cpp_lib_atomic_shared_ptr
#define __cpp_lib_atomic_value_initialization
#define __cpp_lib_atomic_wait
#define __cpp_lib_barrier
#define __cpp_lib_bind_front
#define __cpp_lib_bit_cast
#define __cpp_lib_bitops
#define __cpp_lib_bool_constant
#define __cpp_lib_bounded_array_traits
#define __cpp_lib_boyer_moore_searcher
#define __cpp_lib_byte
#define __cpp_lib_char8_t
#define __cpp_lib_chrono
#define __cpp_lib_chrono_udls
#define __cpp_lib_clamp
#define __cpp_lib_complex_udls
#define __cpp_lib_concepts
#define __cpp_lib_constexpr_algorithms
#define __cpp_lib_constexpr_complex
#define __cpp_lib_constexpr_dynamic_alloc
#define __cpp_lib_constexpr_functional
#define __cpp_lib_constexpr_iterator
#define __cpp_lib_constexpr_memory
#define __cpp_lib_constexpr_numeric
#define __cpp_lib_constexpr_string
#define __cpp_lib_constexpr_string_view
#define __cpp_lib_constexpr_tuple
#define __cpp_lib_constexpr_utility
#define __cpp_lib_constexpr_vector
#define __cpp_lib_coroutine
#define __cpp_lib_destroying_delete
#define __cpp_lib_enable_shared_from_this
#define __cpp_lib_endian
#define __cpp_lib_erase_if
#define __cpp_lib_exchange_function
#define __cpp_lib_execution
#define __cpp_lib_filesystem
#define __cpp_lib_format
#define __cpp_lib_gcd_lcm
#define __cpp_lib_generic_associative_lookup
#define __cpp_lib_generic_unordered_lookup
#define __cpp_lib_hardware_interference_size
#define __cpp_lib_has_unique_object_representations
#define __cpp_lib_hypot
#define __cpp_lib_incomplete_container_elements
#define __cpp_lib_int_pow2
#define __cpp_lib_integer_comparison_functions
#define __cpp_lib_integer_sequence
#define __cpp_lib_integral_constant_callable
#define __cpp_lib_interpolate
#define __cpp_lib_invoke
#define __cpp_lib_is_aggregate
#define __cpp_lib_is_constant_evaluated
#define __cpp_lib_is_final
#define __cpp_lib_is_invocable
#define __cpp_lib_is_layout_compatible
#define __cpp_lib_is_nothrow_convertible
#define __cpp_lib_is_null_pointer
#define __cpp_lib_is_pointer_interconvertible
#define __cpp_lib_is_scoped_enum
#define __cpp_lib_is_swappable
#define __cpp_lib_jthread
#define __cpp_lib_latch
#define __cpp_lib_launder
#define __cpp_lib_list_remove_return_type
#define __cpp_lib_logical_traits
#define __cpp_lib_make_from_tuple
#define __cpp_lib_make_reverse_iterator
#define __cpp_lib_make_unique
#define __cpp_lib_map_try_emplace
#define __cpp_lib_math_constants
#define __cpp_lib_math_special_functions
#define __cpp_lib_memory_resource
#define __cpp_lib_node_extract
#define __cpp_lib_nonmember_container_access
#define __cpp_lib_not_fn
#define __cpp_lib_null_iterators
#define __cpp_lib_optional
#define __cpp_lib_parallel_algorithm
#define __cpp_lib_polymorphic_allocator
#define __cpp_lib_quoted_string_io
#define __cpp_lib_ranges
#define __cpp_lib_raw_memory_algorithms
#define __cpp_lib_remove_cvref
#define __cpp_lib_result_of_sfinae
#define __cpp_lib_robust_nonmodifying_seq_ops
#define __cpp_lib_sample
#define __cpp_lib_scoped_lock
#define __cpp_lib_semaphore
#define __cpp_lib_shared_mutex
#define __cpp_lib_shared_ptr_arrays
#define __cpp_lib_shared_ptr_weak_type
#define __cpp_lib_shared_timed_mutex
#define __cpp_lib_shift
#define __cpp_lib_smart_ptr_for_overwrite
#define __cpp_lib_source_location
#define __cpp_lib_span
#define __cpp_lib_ssize
#define __cpp_lib_stacktrace
#define __cpp_lib_starts_ends_with
#define __cpp_lib_stdatomic_h
#define __cpp_lib_string_contains
#define __cpp_lib_string_udls
#define __cpp_lib_string_view
#define __cpp_lib_syncbuf
#define __cpp_lib_three_way_comparison
#define __cpp_lib_to_address
#define __cpp_lib_to_array
#define __cpp_lib_to_chars
#define __cpp_lib_transformation_trait_aliases
#define __cpp_lib_transparent_operators
#define __cpp_lib_tuple_element_t
#define __cpp_lib_tuples_by_type
#define __cpp_lib_type_identity
#define __cpp_lib_type_trait_variable_templates
#define __cpp_lib_uncaught_exceptions
#define __cpp_lib_unordered_map_try_emplace
#define __cpp_lib_unwrap_ref
#define __cpp_lib_variant
#define __cpp_lib_void_t
```

# [limits](../../core-compiler-collection/libc++/include/limits)

```c++
#define __cpp_lib_char8_t
__BEGIN_NAMESPACE_STD
	enum float_round_style;
	enum float_denorm_style;
	
	template<class T> class numeric_limits;
	
	template<class T> class numeric_limits<const T>;
	template<class T> class numeric_limits<volatile T>;
	template<class T> class numeric_limits<const volatile T>;
	
	template<> class numeric_limits<bool>;
	
	template<> class numeric_limits<char>;
	template<> class numeric_limits<signed char>;
	template<> class numeric_limits<unsigned char>;
	template<> class numeric_limits<char8_t>;
	template<> class numeric_limits<char16_t>;
	template<> class numeric_limits<char32_t>;
	template<> class numeric_limits<wchar_t>;
	
	template<> class numeric_limits<short>;
	template<> class numeric_limits<int>;
	template<> class numeric_limits<long>;
	#if __ARCH == 64
	template<> class numeric_limits<long long>;
	#endif
	template<> class numeric_limits<unsigned short>;
	template<> class numeric_limits<unsigned int>;
	template<> class numeric_limits<unsigned long>;
	#if __ARCH == 64
	template<> class numeric_limits<unsigned long long>;
	#endif
	
	template<> class numeric_limits<float>;
	template<> class numeric_limits<double>;
	template<> class numeric_limits<long double>;
__END_NAMESPACE_STD
```

# [climits](../../core-compiler-collection/libc++/include/climits)

This file implements type size limits as defined in clause 17.3.6 of the ISO-C++ 23 working draft.


**synopsis:**

```c++
#define CHAR_BIT
#define SCHAR_MIN
#define SCHAR_MAX
#define UCHAR_MAX
#define CHAR_MIN
#define CHAR_MAX
#define MB_LEN_MAX
#define SHRT_MIN
#define SHRT_MAX
#define USHRT_MAX
#define INT_MIN
#define INT_MAX
#define UINT_MAX
#define LONG_MIN
#define LONG_MAX
#define ULONG_MAX
#define LLONG_MIN
#define LLONG_MAX
#define ULLONG_MAX
 ```

# [cfloat](../../core-compiler-collection/libc++/include/cfloat)

# [cstdint](../../core-compiler-collection/libc++/include/cstdint)

# [new](../../core-compiler-collection/libc++/include/new)

# [typeinfo](../../core-compiler-collection/libc++/include/typeinfo)

# [source_location](../../core-compiler-collection/libc++/include/source_location)

# [exception](../../core-compiler-collection/libc++/include/exception)

# [initializer_list](../../core-compiler-collection/libc++/include/initializer_list)

# [compare](../../core-compiler-collection/libc++/include/compare)

# [coroutine](../../core-compiler-collection/libc++/include/coroutine)

# [cstdarg](../../core-compiler-collection/libc++/include/cstdarg)

# [csetjmp](../../core-compiler-collection/libc++/include/csetjmp)

# [csignal](../../core-compiler-collection/libc++/include/csignal)
