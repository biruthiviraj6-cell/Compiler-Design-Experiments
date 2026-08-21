# Experiment 07: Three-Address Code Generation Using LEX and YACC

## Pseudocode
```text
LEX:
    MATCH [a-zA-Z][a-zA-Z0-9]* -> yylval.str = strdup(yytext); RETURN ID
    MATCH [0-9]+               -> yylval.str = strdup(yytext); RETURN NUM
    MATCH whitespace           -> IGNORE
    MATCH other                -> RETURN yytext[0]

YACC:
    GLOBAL tempCount = 1

    stmt -> ID '=' expr { PRINT ID, "=", expr }

    expr -> expr '+' expr {
                t = "t" + tempCount++
                PRINT t, "=", expr1, "+", expr2
                $$ = t
            }
          | expr '-' expr {
                t = "t" + tempCount++
                PRINT t, "=", expr1, "-", expr2
                $$ = t
            }
          | expr '*' expr {
                t = "t" + tempCount++
                PRINT t, "=", expr1, "*", expr2
                $$ = t
            }
          | expr '/' expr {
                t = "t" + tempCount++
                PRINT t, "=", expr1, "/", expr2
                $$ = t
            }
          | ID  { $$ = ID }
          | NUM { $$ = NUM }
```
