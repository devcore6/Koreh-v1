/* 
 * The Koreh-v1 Project
 * Koreh-v1 C/C++ Compiler (ccxx)
 * 
 * Copyright (C) 2021, Bryan "/dev/core" M.
 * Licensed under the Mozilla Public License 2.0
 * https://www.mozilla.org/en-US/MPL/2.0/
 * 
 * This file contains macros and configurations used
 * By the library
 * 
 * The ISO documents referenced by this compiler can be found at
 * http://open-std.org/JTC1/SC22/WG21/docs/papers/2020/n4878.pdf (C++23 Working Draft)
 * http://open-std.org/JTC1/SC22/WG14/www/docs/n2310.pdf (C2x Working Draft)
 * 
 */

/* 
 * synopsis:
 * 
 * #define __LIBC_VERSION

 * #define __FLT_MIN__ 1.17549435e-38f
 * #define __FLT_MAX__ 3.40282347e+38f
 * #define __FLT_DIGITS__ 24
 * #define __FLT_DIGITS10__ 6
 * #define __FLT_RADIX__ 2
 * #define __FLT_EPSILON__ 1.19209290e-7f
 * #define __FLT_MIN_EXP__ (-125)
 * #define __FLT_MIN_EXP_10__ (-37)
 * #define __FLT_MAX_EXP__ 128
 * #define __FLT_MAX_EXP_10__ 38
 * #define __FLT_DENORM_MIN 1.40129846e-45f

 * #define __DBL_MIN__ 2.2250738585072014e-308
 * #define __DBL_MAX__ 1.7976931348623157e+308
 * #define __DBL_DIGITS__ 53
 * #define __DBL_DIGITS10__ 15
 * #define __DBL_EPSILON__ 2.2204460492503131e-16
 * #define __DBL_MIN_EXP__ (-1021)
 * #define __DBL_MIN_EXP_10__ (-307)
 * #define __DBL_MAX_EXP__ 1024
 * #define __DBL_MAX_EXP_10__ 308
 * #define __DBL_DENORM_MIN 1.40129846e-45f

 * #define __LDBL_MIN__ 3.36210314311209350626e-4932l
 * #define __LDBL_MAX__ 1.18973149535723176502e+4932l
 * #define __LDBL_DIGITS__ 64
 * #define __LDBL_DIGITS10__ 18
 * #define __LDBL_EPSILON__ 1.08420217248550443401e-19l
 * #define __LDBL_MIN_EXP__ (-16381)
 * #define __LDBL_MIN_EXP_10__ (-4931)
 * #define __LDBL_MAX_EXP__ 16384
 * #define __LDBL_MAX_EXP_10__ 4932
 * #define __LDBL_DENORM_MIN 3.64519953188247460253e-4951l
 * 
 */

#ifndef __LIBC_CONFIG_H
# define __LIBC_CONFIG_H

# define __LIBC_VERSION 1

# define __FLT_MIN__ 1.17549435e-38f
# define __FLT_MAX__ 3.40282347e+38f
# define __FLT_DIGITS__ 24
# define __FLT_DIGITS10__ 6
# define __FLT_RADIX__ 2
# define __FLT_EPSILON__ 1.19209290e-7f
# define __FLT_MIN_EXP__ (-125)
# define __FLT_MIN_EXP_10__ (-37)
# define __FLT_MAX_EXP__ 128
# define __FLT_MAX_EXP_10__ 38
# define __FLT_DENORM_MIN 1.40129846e-45f

# define __DBL_MIN__ 2.2250738585072014e-308
# define __DBL_MAX__ 1.7976931348623157e+308
# define __DBL_DIGITS__ 53
# define __DBL_DIGITS10__ 15
# define __DBL_EPSILON__ 2.2204460492503131e-16
# define __DBL_MIN_EXP__ (-1021)
# define __DBL_MIN_EXP_10__ (-307)
# define __DBL_MAX_EXP__ 1024
# define __DBL_MAX_EXP_10__ 308
# define __DBL_DENORM_MIN 1.40129846e-45f

# define __LDBL_MIN__ 3.36210314311209350626e-4932l
# define __LDBL_MAX__ 1.18973149535723176502e+4932l
# define __LDBL_DIGITS__ 64
# define __LDBL_DIGITS10__ 18
# define __LDBL_EPSILON__ 1.08420217248550443401e-19l
# define __LDBL_MIN_EXP__ (-16381)
# define __LDBL_MIN_EXP_10__ (-4931)
# define __LDBL_MAX_EXP__ 16384
# define __LDBL_MAX_EXP_10__ 4932
# define __LDBL_DENORM_MIN 3.64519953188247460253e-4951l

#endif // __LIBC_CONFIG_H
