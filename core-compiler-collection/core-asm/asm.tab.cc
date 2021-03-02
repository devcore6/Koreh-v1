/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "asm.yy"
 
    #include <asm.h>

    #define YYDEBUG 1

    extern "C" int yylex();
    extern "C" void yyerror(const char *s);

    size_t curline = 1;

#line 82 "asm.tab.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "asm.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EOL = 3,                        /* "end of line"  */
  YYSYMBOL_INTVAL = 4,                     /* "signed integer"  */
  YYSYMBOL_UINTVAL = 5,                    /* "unsigned integer"  */
  YYSYMBOL_FLOATVAL = 6,                   /* "double"  */
  YYSYMBOL_INTVAR = 7,                     /* "signed integer address"  */
  YYSYMBOL_UINTVAR = 8,                    /* "unsigned integer address"  */
  YYSYMBOL_REGISTER = 9,                   /* "register"  */
  YYSYMBOL_STRING = 10,                    /* "string"  */
  YYSYMBOL_11_ = 11,                       /* ','  */
  YYSYMBOL_12_ = 12,                       /* ';'  */
  YYSYMBOL_13_ = 13,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 14,                  /* $accept  */
  YYSYMBOL_parameter = 15,                 /* parameter  */
  YYSYMBOL_parametergroup = 16,            /* parametergroup  */
  YYSYMBOL_instructiongroup = 17,          /* instructiongroup  */
  YYSYMBOL_label = 18,                     /* label  */
  YYSYMBOL_start = 19                      /* start  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   27

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  14
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  17
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  20

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   265


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    11,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    13,    12,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    45,    51,    57,    63,    69,    74,    80,
      83,    87,    92,   485,   490,   491,   492,   493
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"end of line\"",
  "\"signed integer\"", "\"unsigned integer\"", "\"double\"",
  "\"signed integer address\"", "\"unsigned integer address\"",
  "\"register\"", "\"string\"", "','", "';'", "':'", "$accept",
  "parameter", "parametergroup", "instructiongroup", "label", "start", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    44,    59,    58
};
#endif

#define YYPACT_NINF (-16)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -16,     0,   -16,   -16,     7,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -10,    -8,    17,   -16,   -16
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      14,     0,     1,    15,     9,    17,    16,     2,     3,     4,
       5,     6,     7,     8,    13,    10,     0,     9,    12,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -16,   -16,   -15,   -16,   -16,   -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    16,     5,     6,     1
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       2,    17,    19,     3,    18,     0,     0,     0,     0,     0,
       4,     7,     8,     9,    10,    11,    12,    13,     0,     0,
      14,     7,     8,     9,    10,    11,    12,    13
};

static const yytype_int8 yycheck[] =
{
       0,    11,    17,     3,    12,    -1,    -1,    -1,    -1,    -1,
      10,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,     4,     5,     6,     7,     8,     9,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,     0,     3,    10,    17,    18,     4,     5,     6,
       7,     8,     9,    10,    13,    15,    16,    11,    12,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    14,    15,    15,    15,    15,    15,    15,    15,    16,
      16,    16,    17,    18,    19,    19,    19,    19
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     3,     3,     2,     0,     2,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* parameter: "signed integer"  */
#line 39 "asm.yy"
                             {
                        int64_t *val = new int64_t((yyvsp[0].ival));
                        (yyval.vptr) = new std::pair<uint8_t, void*>;
                        (yyval.vptr)->first = 1;
                        (yyval.vptr)->second = (void*)val;
                    }
#line 1089 "asm.tab.cc"
    break;

  case 3: /* parameter: "unsigned integer"  */
#line 45 "asm.yy"
                              {
                        uint64_t *val = new uint64_t((yyvsp[0].uval));
                        (yyval.vptr) = new std::pair<uint8_t, void*>;
                        (yyval.vptr)->first = 1;
                        (yyval.vptr)->second = (void*)val;
                    }
#line 1100 "asm.tab.cc"
    break;

  case 4: /* parameter: "double"  */
#line 51 "asm.yy"
                               {
                        double *val = new double((yyvsp[0].fval));
                        (yyval.vptr) = new std::pair<uint8_t, void*>;
                        (yyval.vptr)->first = 1;
                        (yyval.vptr)->second = (void*)val;
                    }
#line 1111 "asm.tab.cc"
    break;

  case 5: /* parameter: "signed integer address"  */
#line 57 "asm.yy"
                             {
                        int64_t *val = new int64_t((yyvsp[0].ival));
                        (yyval.vptr) = new std::pair<uint8_t, void*>;
                        (yyval.vptr)->first = 3;
                        (yyval.vptr)->second = (void*)val;
                    }
#line 1122 "asm.tab.cc"
    break;

  case 6: /* parameter: "unsigned integer address"  */
#line 63 "asm.yy"
                              {
                        uint64_t *val = new uint64_t((yyvsp[0].uval));
                        (yyval.vptr) = new std::pair<uint8_t, void*>;
                        (yyval.vptr)->first = 3;
                        (yyval.vptr)->second = (void*)val;
                    }
#line 1133 "asm.tab.cc"
    break;

  case 7: /* parameter: "register"  */
#line 69 "asm.yy"
                               {
                        (yyval.vptr) = new std::pair<uint8_t, void*>;
                        (yyval.vptr)->first = 2;
                        (yyval.vptr)->second = (void*)find(registers, *(yyvsp[0].sval));
                    }
#line 1143 "asm.tab.cc"
    break;

  case 8: /* parameter: "string"  */
#line 74 "asm.yy"
                             {
                        (yyval.vptr) = new std::pair<uint8_t, void*>;
                        (yyval.vptr)->first = 4;
                        (yyval.vptr)->second = (void*)(yyvsp[0].sval);
                    }
#line 1153 "asm.tab.cc"
    break;

  case 9: /* parametergroup: %empty  */
#line 80 "asm.yy"
                      {
                        (yyval.vptrvec) = new std::vector<std::pair<uint8_t, void*>*>;
                    }
#line 1161 "asm.tab.cc"
    break;

  case 10: /* parametergroup: parameter  */
#line 83 "asm.yy"
                                {
                        (yyval.vptrvec) = new std::vector<std::pair<uint8_t, void*>*>;
                        (yyval.vptrvec)->push_back((yyvsp[0].vptr));
                    }
#line 1170 "asm.tab.cc"
    break;

  case 11: /* parametergroup: parameter ',' parametergroup  */
#line 87 "asm.yy"
                                                   {
                        (yyval.vptrvec) = (yyvsp[0].vptrvec);
                        (yyval.vptrvec)->push_back((yyvsp[-2].vptr));
                    }
#line 1179 "asm.tab.cc"
    break;

  case 12: /* instructiongroup: "string" parametergroup ';'  */
#line 92 "asm.yy"
                                                {
                        std::vector<instruction_t> instructions = findall(validinstructions, *(yyvsp[-2].sval));
                        if(instructions.size() == 0) {
                            std::cerr << "line " << curline << ": " << "Error! Invalid instruction: " << *(yyvsp[-2].sval) << std::endl;
                            errors++;
                        } else {
                            size_t argc = 0;
                            while(instructions.size() > 0) {
                                argc = (instructions[0].arg1 > 0 ? 1 : 0) + (instructions[0].arg2 > 0 ? 1 : 0) + (instructions[0].arg3 > 0 ? 1 : 0);
                                if(argc != (yyvsp[-1].vptrvec)->size()) {
                                    instructions.erase(instructions.begin());
                                    continue;
                                }
                                std::vector<uint8_t> argt = getargt(instructions[0]);
                                for(size_t i = 0; i < argc; i++) if(argt[i] != (yyvsp[-1].vptrvec)->at(i)->first) {
                                    instructions.erase(instructions.begin());
                                    continue;
                                }
                                break;
                            }
                            if(instructions.size() == 0) {
                                std::cerr << "line " << curline << ": " << "Error! Invalid arguments for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                errors++;
                            } else {
                                instruction_t instruction = instructions[0]; // Just so I don't have to constantly type instructions[0]
                                if(instruction.opcode & (1 << 15)) { // 16 byte instruction
                                    if(mode == 32) {
                                        std::cerr << "line " << curline << ": " << "Error! Invalid size for 32-bit mode for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                        errors++;
                                    } else {
                                        binarydata.push_back((unsigned char)((instruction.opcode & 0xFF00) >> 8));
                                        binarydata.push_back((unsigned char)(instruction.opcode & 0x00FF));
                                        switch(argc) {
                                            case 1: {
                                                switch((yyvsp[-1].vptrvec)->at(0)->first) {
                                                    case 1: {
                                                        for(size_t i = 0; i < 6; i++) binarydata.push_back(0);
                                                        uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                        for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                        break;
                                                    }
                                                    case 2: {
                                                        register_t *val = (register_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                        if(!val) {
                                                            std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                            errors++;
                                                        } else {
                                                            uint8_t size = (instruction.opcode >> 13) & 3;
                                                            if(size != val->size) {
                                                                std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                                errors++;
                                                            } else {
                                                                binarydata.push_back(val->address);
                                                                for(size_t i = 0; i < 13; i++) binarydata.push_back(0);
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    case 3: {
                                                        binarydata.push_back(0xFF);
                                                        for(size_t i = 0; i < 5; i++) binarydata.push_back(0);
                                                        uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                        for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                        break;
                                                    }
                                                    case 4: {
                                                        for(size_t i = 0; i < 6; i++) binarydata.push_back(0);
                                                        schedulereplace(binarydata.size(), *(std::string*)(yyvsp[-1].vptrvec)->at(0)->second);
                                                        for(size_t i = 0; i < 8; i++) binarydata.push_back(0);
                                                        break;
                                                    }
                                                }
                                                break;
                                            } // argc = 1
                                            case 2: {
                                                switch((yyvsp[-1].vptrvec)->at(0)->first) {
                                                    /* case 1 doesn't exist here */
                                                    case 2: {
                                                        register_t *reg = (register_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                        if(!reg) {
                                                            std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                            errors++;
                                                        } else {
                                                            uint8_t size = (instruction.opcode >> 13) & 3;
                                                            if(size != reg->size) {
                                                                std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                                errors++;
                                                            } else {
                                                                binarydata.push_back(reg->address);
                                                            }
                                                        }
                                                        switch((yyvsp[-1].vptrvec)->at(1)->first) {
                                                            case 1: {
                                                                for(size_t i = 0; i < 5; i++) binarydata.push_back(0);
                                                                uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                                for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                                break;
                                                            }
                                                            case 2: {
                                                                reg = (register_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                                if(!reg) {
                                                                    std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                                    errors++;
                                                                } else {
                                                                    uint8_t size = (instruction.opcode >> 13) & 3;
                                                                    if(size != reg->size) {
                                                                        std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                                        errors++;
                                                                    } else {
                                                                        binarydata.push_back(reg->address);
                                                                        for(size_t i = 0; i < 12; i++) binarydata.push_back(0);
                                                                    }
                                                                }
                                                                break;
                                                            }
                                                            case 3: {
                                                                uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                                binarydata.push_back(0xFF);
                                                                for(size_t i = 0; i < 4; i++) binarydata.push_back(0);
                                                                for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                                break;
                                                            }
                                                            /* case 4 doesn't exist here */
                                                        }
                                                        break;
                                                    }
                                                    case 3: {
                                                        binarydata.push_back(0xFF);
                                                        switch((yyvsp[-1].vptrvec)->at(1)->first) {
                                                            case 1: {
                                                                if((instruction.opcode & (1 << 14)) && (instruction.opcode & (1 << 13))) {
                                                                    std::cerr << "line " << curline << ": " << "Error! Argument size mismatch for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                                    errors++;
                                                                } else {
                                                                    binarydata.push_back(0);
                                                                    uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                                }
                                                                break;
                                                            }
                                                            case 2: {
                                                                register_t *reg = (register_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                                if(!reg) {
                                                                    std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                                    errors++;
                                                                } else {
                                                                    uint8_t size = (instruction.opcode >> 13) & 3;
                                                                    if(size != reg->size) {
                                                                        std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                                        errors++;
                                                                    } else {
                                                                        binarydata.push_back(reg->address);
                                                                    }
                                                                }
                                                            }
                                                            /* case 3 doesn't exist here */
                                                            /* case 4 doesn't exist here */
                                                        }
                                                        uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                        for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                        break;
                                                    }
                                                    /* case 4 doesn't exist here */
                                                }
                                                break;
                                            } // argc = 2
                                            case 3: {
                                                // so far argc == 3 only exists for arguments of type 1, 2, 2 so that makes this less complex
                                                register_t *reg = (register_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                if(!reg) {
                                                    std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                    errors++;
                                                } else {
                                                    uint8_t size = (instruction.opcode >> 13) & 3;
                                                    if(size != reg->size) {
                                                        std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                        errors++;
                                                    } else {
                                                        binarydata.push_back(reg->address);
                                                    }
                                                }
                                                reg = (register_t*)(yyvsp[-1].vptrvec)->at(2)->second;
                                                if(!reg) {
                                                    std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                    errors++;
                                                } else {
                                                    uint8_t size = (instruction.opcode >> 13) & 3;
                                                    if(size != reg->size) {
                                                        std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                        errors++;
                                                    } else {
                                                        binarydata.push_back(reg->address);
                                                    }
                                                }
                                                uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                for(size_t i = 0; i < 4; i++) binarydata.push_back(0);
                                                for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                break;
                                            } // argc = 3
                                            case 0:
                                            default: {
                                                for(size_t i = 0; i < 14; i++) binarydata.push_back(0);
                                                break;
                                            }
                                        }
                                    }
                                } else { // 8 byte instruction
                                    binarydata.push_back((unsigned char)((instruction.opcode & 0xFF00) >> 8));
                                    binarydata.push_back((unsigned char)(instruction.opcode & 0x00FF));
                                    switch(argc) {
                                        case 1: {
                                            switch((yyvsp[-1].vptrvec)->at(0)->first) {
                                                case 1: {
                                                    for(size_t i = 0; i < 2; i++) binarydata.push_back(0);
                                                    uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                    break;
                                                }
                                                case 2: {
                                                    register_t *reg = (register_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                    if(!reg) {
                                                        std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                        errors++;
                                                    } else {
                                                        uint8_t size = (instruction.opcode >> 13) & 3;
                                                        if(size != reg->size) {
                                                            std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                            errors++;
                                                        } else {
                                                            binarydata.push_back(reg->address);
                                                            for(size_t i = 0; i < 5; i++) binarydata.push_back(0);
                                                        }
                                                    }
                                                    break;
                                                }
                                                case 3: {
                                                    binarydata.push_back(0xFF);
                                                    binarydata.push_back(0);
                                                    uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                    break;
                                                }
                                                case 4: {
                                                    for(size_t i = 0; i < 2; i++) binarydata.push_back(0);
                                                    schedulereplace(binarydata.size(), *(std::string*)(yyvsp[-1].vptrvec)->at(0)->second);
                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back(0);
                                                    break;
                                                }
                                            }
                                            break;
                                        } // argc = 1
                                        case 2: {
                                            switch((yyvsp[-1].vptrvec)->at(0)->first) {
                                                /* case 1 doesn't exist here */
                                                case 2: {
                                                    register_t *reg = (register_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                    if(!reg) {
                                                        std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                        errors++;
                                                    } else {
                                                        uint8_t size = (instruction.opcode >> 13) & 3;
                                                        if(size != reg->size) {
                                                            std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                            errors++;
                                                        } else {
                                                            binarydata.push_back(reg->address);
                                                        }
                                                    }
                                                    switch((yyvsp[-1].vptrvec)->at(1)->first) {
                                                        case 1: {
                                                            binarydata.push_back(0);
                                                            uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                            for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                            break;
                                                        }
                                                        case 2: {
                                                            reg = (register_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                            if(!reg) {
                                                                std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                                errors++;
                                                            } else {
                                                                uint8_t size = (instruction.opcode >> 13) & 3;
                                                                if(size != reg->size) {
                                                                    std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                                    errors++;
                                                                } else {
                                                                    binarydata.push_back(reg->address);
                                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back(0);
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        case 3: {
                                                            uint64_t* val = (uint64_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                            binarydata.push_back(0xFF);
                                                            for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                            break;
                                                        }
                                                        /* case 4 doesn't exist here */
                                                    }
                                                    break;
                                                }
                                                case 3: {
                                                    binarydata.push_back(0xFF);
                                                    switch((yyvsp[-1].vptrvec)->at(1)->first) {
                                                        case 1: {
                                                            if((instruction.opcode & (1 << 14)) && (instruction.opcode & (1 << 13))) {
                                                                std::cerr << "line " << curline << ": " << "Error! Argument size mismatch for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                                errors++;
                                                            } else {
                                                                binarydata.push_back(0);
                                                                uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                                for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                            }
                                                            break;
                                                        }
                                                        case 2: {
                                                            register_t *reg = (register_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                                            if(!reg) {
                                                                std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                                errors++;
                                                            } else {
                                                                uint8_t size = (instruction.opcode >> 13) & 3;
                                                                if(size != reg->size) {
                                                                    std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                                    errors++;
                                                                } else {
                                                                    binarydata.push_back(reg->address);
                                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back(0);
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        /* case 3 doesn't exist here */
                                                        /* case 4 doesn't exist here */
                                                    }
                                                    uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                    break;
                                                }
                                                /* case 4 doesn't exist here */
                                            }
                                            break;
                                        } // argc = 2
                                        case 3: {
                                            // so far argc == 3 only exists for arguments of type 1, 2, 2 so that makes this less complex
                                            register_t *reg = (register_t*)(yyvsp[-1].vptrvec)->at(1)->second;
                                            if(!reg) {
                                                std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                errors++;
                                            } else {
                                                uint8_t size = (instruction.opcode >> 13) & 3;
                                                if(size != reg->size) {
                                                    std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                    errors++;
                                                } else {
                                                    binarydata.push_back(reg->address);
                                                }
                                            }
                                            reg = (register_t*)(yyvsp[-1].vptrvec)->at(2)->second;
                                            if(!reg) {
                                                std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                errors++;
                                            } else {
                                                uint8_t size = (instruction.opcode >> 13) & 3;
                                                if(size != reg->size) {
                                                    std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *(yyvsp[-2].sval) << std::endl;
                                                    errors++;
                                                } else {
                                                    binarydata.push_back(reg->address);
                                                }
                                            }
                                            uint64_t *val = (uint64_t*)(yyvsp[-1].vptrvec)->at(0)->second;
                                            for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                            break;
                                        } // argc = 3
                                        case 0:
                                        default: {
                                            for(size_t i = 0; i < 14; i++) binarydata.push_back(0);
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        for(size_t i = 0; i < (yyvsp[-1].vptrvec)->size(); i++) {
                            delete (yyvsp[-1].vptrvec)->at(i)->second;
                            delete (yyvsp[-1].vptrvec)->at(i);
                        }
                        delete (yyvsp[-1].vptrvec);
                        delete (yyvsp[-2].sval);
                    }
#line 1576 "asm.tab.cc"
    break;

  case 13: /* label: "string" ':'  */
#line 485 "asm.yy"
                                 {
                        addlabel(*(yyvsp[-1].sval));
                        delete (yyvsp[-1].sval);
                    }
#line 1585 "asm.tab.cc"
    break;


#line 1589 "asm.tab.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 495 "asm.yy"


void yyerror(const char *s) {
    std::cerr << "line " << curline << ": " << s << std::endl;
    errors++;
}
