%{ 
    #include "shared.h"

    #define YYDEBUG 1

    extern "C" int yylex();
    extern "C" void yyerror(const char *s);

    size_t curline = 1;
%}

/*%union {
    bool                                bool_val;
    std::pair<bool, std::string>*       bool_string_val;
    std::string*                        string_val;
}*/

%start preprocessing_file

%token IF IFDEF IFNDEF ELIF ELSE ENDIF
%token DOUBLE_PIPE DOUBLE_AND DOUBLE_EQUAL NOT_EQUAL LOWER_EQUAL GREATER_EQUAL LSHIFT RSHIFT
%token HEXADECIMAL_PREFIX LONG_LONG_SUFFIX
%token LQUOTE UQUOTE
%token ESCAPE_QUOTE ESCAPE_DQUOTE ESCAPE_QMARK ESCAPE_BACKSLASH ESCAPE_A ESCAPE_B ESCAPE_FORMFEED ESCAPE_NEWLINE ESCAPE_RETURN ESCAPE_HTAB ESCAPE_VTAB ESCAPE_X

// %destructor { delete $$; } 

%%

new_line: '\n'

preprocessing_file: group_opt                                           // Preprocessing a file starts with an optional group

group: group_part                                                       // A group is either just a group part
     | group group_part                                                 // Or a group with multiple group parts

group_opt:                                                              // Optional group is either nothing or a group
         | group

group_part: if_section                                                  // A group part is either an if section (#if [#elif] [#else] #endif)
/*          | control_line                                                // Or a control line (#include, #define, #undef, #line, #error, #pragma #\n)
          | text_line                                                   // Or a text line
          | '#' non_directive                                           // Or a # followed by a non directive*/

if_section: if_group elif_groups_opt else_group_opt endif_line          // An #if section contains an #if group and an #endif line, and optional #endif groups and an optional #else group

if_group: '#' IF constant_expression new_line group_opt                 // An #if group consists of a # followed by if with optional whitespaces, a constant expression, a new line, and an optional group
        | '#' IFDEF identifier new_line group_opt                       // Or an #ifdef
        | '#' IFNDEF identifier new_line group_opt                      // Or an #ifndef

elif_groups: elif_group                                                 // A list of #elif groups is one or more #elif groups
           | elif_groups elif_group

elif_group: '#' ELIF constant_expression new_line group_opt             // An #elif group is just like an #if group

elif_groups_opt:                                                        // Optional list of #elif groups is either nothing or a list of #elif groups
               | elif_groups

else_group: '#' ELSE new_line group_opt                                 // An else group is just an #else with a new line character following it

else_group_opt:                                                         // Optional #else group
              | else_group

endif_line: '#' ENDIF new_line                                          // An #endif line



// For the most part taken from http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2310.pdf, did minor changes for the preprocessor version.
identifier: identifier_nondigit
          | identifier identifier_nondigit
          | identifier digit

identifier_nondigit: nondigit

nondigit: '_'
		| 'a'
		| 'b'
		| 'c'
		| 'd'
		| 'e'
		| 'f'
		| 'g'
		| 'h'
		| 'i'
		| 'j'
		| 'k'
		| 'l'
		| 'm'
		| 'n'
		| 'o'
		| 'p'
		| 'q'
		| 'r'
		| 's'
		| 't'
		| 'u'
		| 'v'
		| 'w'
		| 'x'
		| 'y'
		| 'z'
		| 'A'
		| 'B'
		| 'C'
		| 'D'
		| 'E'
		| 'F'
		| 'G'
		| 'H'
		| 'I'
		| 'J'
		| 'K'
		| 'L'
		| 'M'
		| 'N'
		| 'O'
		| 'P'
		| 'Q'
		| 'R'
		| 'S'
		| 'T'
		| 'U'
		| 'V'
		| 'W'
		| 'X'
		| 'Y'
		| 'Z'

digit: '0'
     | '1'
     | '2'
     | '3'
     | '4'
     | '5'
     | '6'
     | '7'
     | '8'
     | '9'

integer_constant: decimal_constant integer_suffix_opt
                | octal_constant integer_suffix_opt
                | hexadecimal_constant integer_suffix_opt

decimal_constant: nonzero_digit
                | decimal_constant digit

octal_constant: '0'
              | octal_constant octal_digit

hexadecimal_constant: HEXADECIMAL_PREFIX hexadecimal_digit
hexadecimal_constant hexadecimal_digit

nonzero_digit: '1'
             | '2'
             | '3'
             | '4'
             | '5'
             | '6'
             | '7'
             | '8'
             | '9'

octal_digit: '0'
           | '1'
           | '2'
           | '3'
           | '4'
           | '5'
           | '6'
           | '7'

hexadecimal_digit: '0'
                 | '1'
                 | '2'
                 | '3'
                 | '4'
                 | '5'
                 | '6'
                 | '7'
                 | '8'
                 | '9'
                 | 'a'
                 | 'b'
                 | 'c'
                 | 'd'
                 | 'e'
                 | 'f'
                 | 'A'
                 | 'B'
                 | 'C'
                 | 'D'
                 | 'E'
                 | 'F'

integer_suffix: unsigned_suffix long_suffix_opt
              | unsigned_suffix LONG_LONG_SUFFIX
              | long_suffix unsigned_suffix_opt
              | LONG_LONG_SUFFIX unsigned_suffix_opt

integer_suffix_opt:
                  | integer_suffix

unsigned_suffix: 'u'
               | 'U'

unsigned_suffix_opt:
                   | unsigned_suffix

long_suffix: 'l'
           | 'L'

long_suffix_opt:
               | long_suffix



floating_constant: decimal_floating_constant
                 | hexadecimal_floating_constant

decimal_floating_constant: fractional_constant exponent_part_opt floating_suffix_opt
                         | digit_sequence exponent_part floating_suffix_opt

hexadecimal_floating_constant: HEXADECIMAL_PREFIX hexadecimal_fractional_constant binary_exponent_part floating_suffix_opt
                             | HEXADECIMAL_PREFIX hexadecimal_digit_sequence binary_exponent_part floating_suffix_opt

fractional_constant: digit_sequence_opt '.' digit_sequence
                   | digit_sequence '.'

exponent_part: 'e' sign_opt digit_sequence
             | 'E' sign_opt digit_sequence

exponent_part_opt:
                 | exponent_part

sign: '+'
    | '-'

sign_opt:
        | sign

digit_sequence: digit
              | digit_sequence digit

digit_sequence_opt:
                  | digit_sequence

hexadecimal_fractional_constant: hexadecimal_digit_sequence_opt '.' hexadecimal_digit_sequence
                               | hexadecimal_digit_sequence '.'

binary_exponent_part: 'p' sign_opt digit_sequence
                    | 'P' sign_opt digit_sequence

hexadecimal_digit_sequence: hexadecimal_digit
                          | hexadecimal_digit_sequence hexadecimal_digit

hexadecimal_digit_sequence_opt:
                              | hexadecimal_digit_sequence

floating_suffix: 'f'
               | 'l'
               | 'F'
               | 'L'

floating_suffix_opt:
                   | floating_suffix



character_constant: '\'' c_char '\''
                    LQUOTE c_char '\''
                    UQUOTE c_char '\''

c_char: 'a'
	  | 'b'
	  | 'c'
	  | 'd'
	  | 'e'
	  | 'f'
	  | 'g'
	  | 'h'
	  | 'i'
	  | 'j'
	  | 'k'
	  | 'l'
	  | 'm'
	  | 'n'
	  | 'o'
	  | 'p'
	  | 'q'
	  | 'r'
	  | 's'
	  | 't'
	  | 'u'
	  | 'v'
	  | 'w'
	  | 'x'
	  | 'y'
	  | 'z'
	  | 'A'
	  | 'B'
	  | 'C'
	  | 'D'
	  | 'E'
	  | 'F'
	  | 'G'
	  | 'H'
	  | 'I'
	  | 'J'
	  | 'K'
	  | 'L'
	  | 'M'
	  | 'N'
	  | 'O'
	  | 'P'
	  | 'Q'
	  | 'R'
	  | 'S'
	  | 'T'
	  | 'U'
	  | 'V'
	  | 'W'
	  | 'X'
	  | 'Y'
	  | 'Z'
	  | '0'
	  | '1'
	  | '2'
	  | '3'
	  | '4'
	  | '5'
	  | '6'
	  | '7'
	  | '8'
	  | '9'
	  | '_'
	  | '{'
	  | '}'
	  | '['
	  | ']'
	  | '#'
	  | '('
	  | ')'
	  | '<'
	  | '>'
	  | '%'
	  | ':'
	  | ';'
	  | '.'
	  | '?'
	  | '*'
	  | '+'
	  | '-'
	  | '/'
	  | '^'
	  | '&'
	  | '|'
	  | '~'
	  | '!'
	  | '='
	  | ','
	  | '\"'
	  | '\t'
	  | '\v'
	  | '\f'
	  | ' '
	  | escape_sequence

escape_sequence: simple_escape_sequence
               | octal_escape_sequence
               | hexadecimal_escape_sequence

simple_escape_sequence: ESCAPE_QUOTE
                      | ESCAPE_DQUOTE
                      | ESCAPE_QMARK
                      | ESCAPE_BACKSLASH
                      | ESCAPE_A
                      | ESCAPE_B
                      | ESCAPE_FORMFEED
                      | ESCAPE_NEWLINE
                      | ESCAPE_RETURN
                      | ESCAPE_HTAB
                      | ESCAPE_VTAB

octal_escape_sequence: '\\' octal_digit
                     | '\\' octal_digit octal_digit
                     | '\\' octal_digit octal_digit octal_digit

hexadecimal_escape_sequence: ESCAPE_X hexadecimal_digit
                           | hexadecimal_escape_sequence hexadecimal_digit



constant: integer_constant
        | floating_constant
        | character_constant

primary_expression: identifier
                  | constant
                  | '(' constant_expression ')'

unary_expression: primary_expression
                | unary_operator primary_expression

unary_operator: '˜'
              | '!'

multiplicative_expression: unary_expression
                         | multiplicative_expression '*' unary_expression
                         | multiplicative_expression '/' unary_expression
                         | multiplicative_expression '%' unary_expression

additive_expression: multiplicative_expression
                   | additive_expression '+' multiplicative_expression
                   | additive_expression '-' multiplicative_expression

shift_expression: additive_expression
                | shift_expression LSHIFT additive_expression
                | shift_expression RSHIFT additive_expression

relational_expression: shift_expression
                     | relational_expression '<' shift_expression
                     | relational_expression '>' shift_expression
                     | relational_expression LOWER_EQUAL shift_expression
                     | relational_expression GREATER_EQUAL shift_expression

equality_expression: relational_expression
                   | equality_expression DOUBLE_EQUAL relational_expression
                   | equality_expression NOT_EQUAL relational_expression

AND_expression: equality_expression
              | AND_expression '&' equality_expression

exclusive_OR_expression: AND_expression
                       | exclusive_OR_expression '^' AND_expression

inclusive_OR_expression: exclusive_OR_expression
                       | inclusive_OR_expression '|' exclusive_OR_expression

logical_AND_expression: inclusive_OR_expression
                      | logical_AND_expression DOUBLE_AND inclusive_OR_expression

logical_OR_expression: logical_AND_expression
                     | logical_OR_expression DOUBLE_PIPE logical_AND_expression

conditional_expression: logical_OR_expression
                      | logical_OR_expression '?' conditional_expression ':' conditional_expression

constant_expression: conditional_expression

/*(6.10) control-line:
# include pp-tokens new_line
# define identifier replacement-list new_line
# define identifier lparen identifier-listopt )
replacement-list new_line
# define identifier lparen ... ) replacement-list new_line
# define identifier lparen identifier-list , ... )
replacement-list new_line
# undef identifier new_line
# line pp-tokens new_line
# error pp-tokensopt new_line
# pragma pp-tokensopt new_line
# new_line
(6.10) text-line:
pp-tokensopt new_line
(6.10) non-directive:
pp-tokens new_line
(6.10) lparen:
a ( character not immediately preceded by white space
space
(6.10) replacement-list:
pp-tokensopt
(6.10) pp-tokens:
preprocessing-token
pp-tokens preprocessing-token
(6.10) new_line:
the new_line character
(6.10.6) on-off-switch: one of
ON OFF DEFAULT


preprocessing_token: header_name
                   | identifier
                   | pp_number
                   | character_constant
                   | string_literal
                   | punctuator
                   | non_white_space*/