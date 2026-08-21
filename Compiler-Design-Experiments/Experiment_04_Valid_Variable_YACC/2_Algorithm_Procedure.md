# Experiment 04: Recognize Valid Variable Identifier Using YACC

### Algorithm:
#### LEX:
1. Include header declarations and `"y.tab.h"`.
2. Define regular expressions:
   - Letters `[a-zA-Z]` -> return token `LET`.
   - Digits `[0-9]` -> return token `DIG`.
   - Newline `\n` -> return `0` (indicates end of line/input).
   - Any other character -> return `yytext[0]`.
3. Return `1` in `yywrap()`.

#### YACC:
1. Declare tokens `LET` and `DIG`.
2. Define grammar productions for valid identifiers:
   - `variable: var;`
   - `var: var DIG | var LET | LET;`
3. Call `yyparse()` in `main()`. If parsing completes successfully, print `"Valid variable"`.
4. Define `yyerror()` to print `"Invalid variable"` and terminate on syntax errors.

### Procedure:
1. Create `valvar.l` (Lex file) and `valvar.y` (Yacc file).
2. Generate C source using `lex valvar.l` and `yacc -d valvar.y`.
3. Compile using GCC: `gcc lex.yy.c y.tab.c -o valvar`.
4. Execute `./valvar` and test with valid (e.g. `add`, `var123`) and invalid inputs (e.g. `1add`, `_var`).
