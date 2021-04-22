%{
    #include "shared.h"
    #include "04-preprocessor.tab.hh"
    #include <io.h>
    #pragma warning(disable : 4996) // Make VisualStudio shut up about isatty and fileno
    extern size_t curline;
    extern "C" int yylex();
    #define YY_DECL extern "C" int yylex()
%}

%option batch
%option nounistd
%option noyywrap

%%

"if" { return IF; }
"ifdef" { return IFDEF; }
"ifndef" { return IFNDEF; }
"elif" { return ELIF; }
"else" { return ELSE; }
"endif" { return ENDIF; }

"include" { return INCLUDE; }
"define" { return DEFINE; }
"undef" { return UNDEF; }
"line" { return LINE; }
"error" { return ERROR; }
"pragma" { return PRAGMA; }

"||" { return DOUBLE_PIPE; }
"&&" { return DOUBLE_AND; }
"==" { return DOUBLE_EQUAL; }
"!=" { return NOT_EQUAL; }
"<=" { return LOWER_EQUAL; }
">=" { return GREATER_EQUAL; }
"<<" { return LSHIFT; }
">>" { return RSHIFT; }

"0x" { return HEXADECIMAL_PREFIX; }
"0X" { return HEXADECIMAL_PREFIX; }

"ll" { return LONG_LONG_SUFFIX; }
"LL" { return LONG_LONG_SUFFIX; }

"L'" { return LQUOTE; }
"u'" { return UQUOTE; }
"U'" { return UQUOTE; }

"\\'" { return ESCAPE_QUOTE; }
"\\\"" { return ESCAPE_DQUOTE; }
"\\?" { return ESCAPE_QMARK; }
"\\\\" { return ESCAPE_BACKSLASH; }
"\\a" { return ESCAPE_A; }
"\\b" { return ESCAPE_B; }
"\\f" { return ESCAPE_FORMFEED; }
"\\n" { return ESCAPE_NEWLINE; }
"\\r" { return ESCAPE_RETURN; }
"\\t" { return ESCAPE_HTAB; }
"\\v" { return ESCAPE_VTAB; }
"\\x" { return ESCAPE_X; }

"u8" { return UTF8_PREFIX; }
"\\u" { return UNIVERSAL_CHARACTER_ESCAPE; }
"\\U" { return DOUBLE_UNIVERSAL_CHARACTER_ESCAPE; }

"import" { return IMPORT; }
"module" { return MODULE; }
"export" { return EXPORT; }

"##" { return DOUBLE_HASH; }

. { return static_cast<yytokentype>(*yytext); }
