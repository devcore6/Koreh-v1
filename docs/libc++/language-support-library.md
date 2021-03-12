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

This file implements common language definitions as defined in clause 17.2 of the ISO-C++ 23 working draft.

**synopsys:**

```c++
extern "C++" {

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

}
```

It's matching source file is [language-support/cstddef.cpp](../../core-compiler-collection/libc++/language-support/cstddef.cpp)
