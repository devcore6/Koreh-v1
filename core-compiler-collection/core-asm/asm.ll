%{
    #include <asm.h>
    #include "asm.tab.hh"
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

"$0x"[0-9]+ {
    char*ptr;
    yylval.uval = std::strtoull(yytext+1, &ptr, 0);
    return UINTVAR;
}

"$-0x"[0-9]+ {
    char*ptr;
    yylval.ival = std::strtoll(yytext+1, &ptr, 0);
    return INTVAR;
}

"$"[0-9]+ {
    char*ptr;
    yylval.uval = std::strtoull(yytext+1, &ptr, 10);
    return UINTVAR;
}

"$-"[0-9]+ {
    char*ptr;
    yylval.ival = std::strtoll(yytext+1, &ptr, 10);
    return INTVAR;
}

"%"[A-Za-z0-9_]* {
    yylval.sval = new std::string(yytext+1, yyleng);
    return REGISTER;
}

"0x"[0-9]+ {
    char*ptr;
    yylval.uval = std::strtoull(yytext, &ptr, 0);
    return UINTVAL;
}

[0-9]+ {
    char*ptr;
    yylval.uval = std::strtoull(yytext, &ptr, 10);
    return UINTVAL;
}

"-0x"[0-9]+ {
    char*ptr;
    yylval.ival = std::strtoll(yytext, &ptr, 0);
    return INTVAL;
}

"-"[0-9]+ {
    char*ptr;
    yylval.ival = std::strtoll(yytext, &ptr, 10);
    return INTVAL;
}

"-"[0-9]+"."[0-9]*[fF] {
    yylval.fval = std::atof(yytext);
    return FLOATVAL;
}

"-"[0-9]+"."[0-9]* {
    yylval.fval = std::atof(yytext);
    return FLOATVAL;
}

[0-9]+"."[0-9]*[fF] {
    yylval.fval = std::atof(yytext);
    return FLOATVAL;
}

[0-9]+"."[0-9]* {
    yylval.fval = std::atof(yytext);
    return FLOATVAL;
}

[A-Za-z][A-Za-z0-9_]* {
    yylval.sval = new std::string(yytext, yyleng);
    return STRING;
}

"'"."'" {
    yylval.ival = yytext[1];
    return INTVAL;
}

[ \t\r]+ { }

\n {
    curline++;
    return EOL;
}

. {
    return static_cast<yytokentype>(*yytext);
}
