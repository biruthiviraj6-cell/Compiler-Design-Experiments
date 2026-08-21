# Experiment 05: Recognize Valid Control Structures Syntax Using YACC

### Algorithm:
#### LEX:
1. Define keywords for control structures: `"if"` -> `IF`, `"else"` -> `ELSE`, `"for"` -> `FOR`, `"while"` -> `WHILE`, `"switch"` -> `SWITCH`, `"case"` -> `CASE`, `"default"` -> `DEFAULT`.
2. Define identifiers `[a-zA-Z][a-zA-Z0-9]*` -> `ID` and numbers `[0-9]+` -> `NUM`.
3. Match relational operators: `"=="` -> `EQ`, `"<="` -> `LE`, `">="` -> `GE`, `"<"` -> `LT`, `">"` -> `GT`, `"="` -> `ASSIGN`.
4. Match punctuation symbols: `"{"` -> `LBRACE`, `"}"` -> `RBRACE`, `"("` -> `LPAREN`, `")"` -> `RPAREN`, `":"` -> `COLON`, `";"` -> `SEMICOLON`.
5. Skip whitespaces and return single characters as tokens.

#### YACC:
1. Declare tokens from LEX.
2. Define grammar productions for statements:
   - `program: stmt_list`
   - `stmt_list: stmt_list stmt | stmt`
   - `stmt: if_stmt | while_stmt | for_stmt | switch_stmt | assignment_stmt | block_stmt`
   - `if_stmt: IF LPAREN cond RPAREN stmt | IF LPAREN cond RPAREN stmt ELSE stmt`
   - `while_stmt: WHILE LPAREN cond RPAREN stmt`
   - `for_stmt: FOR LPAREN ID ASSIGN NUM SEMICOLON cond SEMICOLON ID ASSIGN ID RPAREN stmt`
   - `switch_stmt: SWITCH LPAREN ID RPAREN LBRACE case_list RBRACE`
   - `cond: ID relop NUM | ID relop ID`
3. Call `yyparse()` in `main()`. Print `"Valid control structure syntax."` on success.
4. Define `yyerror()` to report invalid syntax.

### Procedure:
1. Create `control.l` and `control.y`.
2. Compile: `lex control.l`, `yacc -d control.y`, `gcc lex.yy.c y.tab.c -o control`.
3. Execute `./control` with sample C control structure constructs and verify.
