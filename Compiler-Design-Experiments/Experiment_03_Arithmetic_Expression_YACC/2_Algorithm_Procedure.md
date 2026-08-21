# Experiment 03: Recognize Valid Arithmetic Expression Using YACC

### Algorithm:
#### LEX:
1. Include required header declarations and `"y.tab.h"`.
2. Define regular expressions for:
   - Identifiers: `[a-zA-Z][0-9a-zA-Z]*` -> return token `ID`.
   - Digits/Numbers: `[0-9]+` -> return token `DIG`.
   - Whitespace: `[ \t]+` -> ignore/skip.
   - Newline: `\n` -> return `0` (end of input).
   - Any other single character: return `yytext[0]`.
3. Return `1` in `yywrap()` when input scanning is finished.

#### YACC:
1. Declare tokens `ID`, `DIG` and define operator precedence and associativity:
   - `%left '+' '-'`
   - `%left '*' '/'`
   - `%right UMINUS`
2. Define grammar productions for valid arithmetic expressions:
   - `stmt: expn;`
   - `expn: expn '+' expn | expn '-' expn | expn '*' expn | expn '/' expn | '-' expn %prec UMINUS | '(' expn ')' | DIG | ID;`
3. Call `yyparse()` in `main()`. If parsing succeeds, print `"Valid Expression"`.
4. Define `yyerror()` to print `"Invalid Expression"` on syntax errors.

### Procedure:
1. Create LEX specification file `art_expr.l`.
2. Create YACC specification file `art_expr.y`.
3. Run `lex art_expr.l` to generate `lex.yy.c`.
4. Run `yacc -d art_expr.y` to generate `y.tab.c` and `y.tab.h`.
5. Compile with GCC: `gcc lex.yy.c y.tab.c -o art_expr`.
6. Run `./art_expr`, provide arithmetic expressions, and observe validation output.
