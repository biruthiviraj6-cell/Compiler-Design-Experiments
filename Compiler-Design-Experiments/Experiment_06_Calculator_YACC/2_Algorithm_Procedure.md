# Experiment 06: Calculator Implementation Using LEX and YACC

### Algorithm:
1. **Start** the program.
2. In the LEX specification (`cal.l`):
   - Define regular expression for numbers: `[0-9]+(\.[0-9]+)?`.
   - Convert matched text to `double` using `atof(yytext)` and assign to `yylval`.
   - Return token `NUM`.
   - Return operators and newline characters as single character tokens.
3. In the YACC specification (`cal.y`):
   - Define `#define YYSTYPE double`.
   - Set precedence and associativity rules:
     - `%left '+' '-'`
     - `%left '*' '/'`
     - `%right UMINUS`
   - Define grammar evaluation rules:
     - `E: E '+' E { $$ = $1 + $3; }`
     - `E: E '-' E { $$ = $1 - $3; }`
     - `E: E '*' E { $$ = $1 * $3; }`
     - `E: E '/' E { $$ = $1 / $3; }`
     - `E: '-' E %prec UMINUS { $$ = -$2; }`
     - `E: '(' E ')' { $$ = $2; }`
     - `E: NUM { $$ = $1; }`
   - Print the evaluated result upon reduction.
4. Execute and verify with arithmetic expressions.
5. **Stop** the program.

### Procedure:
1. Create `cal.l` and `cal.y`.
2. Generate scanner and parser: `lex cal.l` and `yacc -d cal.y`.
3. Compile using GCC: `gcc lex.yy.c y.tab.c -o calc -lm`.
4. Run `./calc`, input mathematical expressions (e.g. `2+2`, `10*5-4/2`), and observe output.
