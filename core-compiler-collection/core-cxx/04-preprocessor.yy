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
%token INCLUDE DEFINE UNDEF LINE ERROR PRAGMA
%token UTF8_PREFIX UNIVERSAL_CHARACTER_ESCAPE DOUBLE_UNIVERSAL_CHARACTER_ESCAPE
%token IMPORT MODULE EXPORT
%token DOUBLE_HASH

// %destructor { delete $$; } 

%%

pp_keyword: IF
          | IFDEF
          | IFNDEF
          | ELIF
          | ELSE
          | ENDIF
          | INCLUDE
          | DEFINE
          | UNDEF
          | LINE
          | ERROR
          | PRAGMA
          | IMPORT
          | MODULE
          | EXPORT

pp_suffix: LONG_LONG_SUFFIX

pp_prefix: UTF8_PREFIX
         | UNIVERSAL_CHARACTER_ESCAPE
         | DOUBLE_UNIVERSAL_CHARACTER_ESCAPE

pp_symbol: DOUBLE_PIPE
         | DOUBLE_AND
         | DOUBLE_EQUAL
         | NOT_EQUAL
         | LOWER_EQUAL
         | GREATER_EQUAL
         | LSHIFT
         | RSHIFT
         | DOUBLE_HASH

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
          | identifier pp_keyword // Not included in the PDF, but needed for how our implementation works
          | pp_keyword identifier // Not included in the PDF, but needed for how our implementation works
          | pp_suffix // Not included in the PDF, but needed for how our implementation works
          | identifier pp_suffix // Not included in the PDF, but needed for how our implementation works
          | pp_prefix // Not included in the PDF, but needed for how our implementation works
          | identifier pp_prefix // Not included in the PDF, but needed for how our implementation works

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



character_constant: '\'' c_char_sequence '\''
                    LQUOTE c_char_sequence '\''
                    UQUOTE c_char_sequence '\''

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
      | pp_keyword // Not included in the PDF, but needed for how our implementation works
      | pp_suffix // Not included in the PDF, but needed for how our implementation works
      | pp_prefix // Not included in the PDF, but needed for how our implementation works
      | pp_symbol // Not included in the PDF, but needed for how our implementation works

c_char_sequence: c_char
               | c_char_sequence c_char

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

header_name: '<' h_char_sequence '>'
           | '"' q_char_sequence '"'

h_char_sequence: h_char
               | h_char_sequence h_char

h_char: 'a'
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
      | '\\'
      | '\"'
      | '\''
      | '\t'
      | '\v'
      | '\f'
      | ' '
      | pp_keyword // Not included in the PDF, but needed for how our implementation works
      | pp_suffix // Not included in the PDF, but needed for how our implementation works
      | pp_prefix // Not included in the PDF, but needed for how our implementation works
      | pp_symbol // Not included in the PDF, but needed for how our implementation works

q_char_sequence: q_char
               | q_char_sequence q_char

q_char: 'a'
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
      | '\\'
      | '\''
      | '\t'
      | '\v'
      | '\f'
      | ' '
      | pp_keyword // Not included in the PDF, but needed for how our implementation works
      | pp_suffix // Not included in the PDF, but needed for how our implementation works
      | pp_prefix // Not included in the PDF, but needed for how our implementation works
      | pp_symbol // Not included in the PDF, but needed for how our implementation works

identifier_list: identifier
               | identifier_list ',' identifier

identifier_list_opt: 
                   | identifier_list

control_line: '#' INCLUDE header_name new_line
            | '#' DEFINE identifier replacement_list new_line
            | '#' DEFINE identifier '(' identifier_list_opt ')' replacement_list new_line
            | '#' UNDEF identifier new_line
            | '#' LINE pp_tokens new_line
            | '#' ERROR pp_tokens_opt new_line
            | '#' PRAGMA pp_tokens_opt new_line
            | '#' new_line

text_line: pp_tokens_opt new_line

non_directive: pp_tokens new_line

replacement_list: pp_tokens_opt

pp_tokens: preprocessing_token
         | pp_tokens preprocessing_token

pp_tokens_opt:
             | pp_tokens

pp_number: digit
         | '.' digit
         | pp_number digit
         | pp_number identifier_nondigit
         | pp_number '’' digit
         | pp_number '’' nondigit
         | pp_number 'e' sign
         | pp_number 'E' sign
         | pp_number 'p' sign
         | pp_number 'P' sign
         | pp_number '.'

encoding_prefix: 'L'
               | UTF8_PREFIX
               | 'u'
               | 'U'

encoding_prefix_opt:
                   | encoding_prefix

string_literal: encoding_prefix_opt '"' s_char_sequence_opt '"'
//              | encoding_prefix_opt 'R' raw_string // raw string may come at some point in the future

s_char_sequence: s_char
               | s_char_sequence s_char

s_char_sequence_opt:
                   | s_char_sequence

hex_quad: hexadecimal_digit hexadecimal_digit hexadecimal_digit hexadecimal_digit

universal_character_name: UNIVERSAL_CHARACTER_ESCAPE hex_quad
                        | DOUBLE_UNIVERSAL_CHARACTER_ESCAPE hex_quad hex_quad

s_char: basic_s_char
      | escape_sequence
      | universal_character_name
      | pp_prefix // Not included in the PDF, but needed for how our implementation works
      | pp_suffix // Not included in the PDF, but needed for how our implementation works
      | pp_keyword // Not included in the PDF, but needed for how our implementation works
      | pp_symbol // Not included in the PDF, but needed for how our implementation works

basic_s_char: 'a'
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
            | '\''
            | '\t'
            | '\v'
            | '\f'
            | ' '

preprocessing_token: header_name
                   | IMPORT
                   | MODULE
                   | EXPORT
                   | identifier
                   | pp_number
                   | character_constant
                   | string_literal
                   // | preprocessing_op_or_punc Honestly, this is kind of a mess to have in the preprocessor too.
                   // | each non-whitespace character that cannot be one of the above
