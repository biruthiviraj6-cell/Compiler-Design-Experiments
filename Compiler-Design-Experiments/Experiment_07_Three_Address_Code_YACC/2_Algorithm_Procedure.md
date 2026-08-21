# Experiment 07: Three-Address Code Generation Using LEX and YACC

### Algorithm:
#### LEX:
1. Tokenize identifiers `[a-zA-Z][a-zA-Z0-9]*` and numbers `[0-9]+`.
2. Duplicate matched string using `strdup(yytext)` and store in `yylval.str`.
3. Return `ID` and `NUM` tokens respectively.
4. Skip spaces and return single characters (`=`, `+`, `-`, `*`, `/`).

#### YACC:
1. Maintain a global temporary variable counter `tempCount = 1`.
2. Define helper functions `printTAC(result, op1, operator, op2)` and `printAssign(var, val)`.
3. In expression reductions (`expr '+' expr`, etc.):
   - Generate a new temporary variable `sprintf(temp, "t%d", tempCount++)`.
   - Emit TAC instruction: `printf("%s = %s %s %s\n", temp, $1.str, op, $3.str)`.
   - Pass the temporary name `temp` up the parse tree.
4. In assignment statement `ID '=' expr`:
   - Emit assignment TAC: `printf("%s = %s\n", $1.str, $3.str)`.
5. Call `yyparse()` in `main()`.

### Procedure:
1. Create `tac.l` and `tac.y`.
2. Generate C files: `lex tac.l` and `yacc -d tac.y`.
3. Compile using GCC: `gcc lex.yy.c y.tab.c -o tac`.
4. Run `./tac` and input expressions such as `a=b+c*d` or `x=a*b+c/d`.
