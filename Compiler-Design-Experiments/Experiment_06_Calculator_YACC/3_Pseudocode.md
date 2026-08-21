# Experiment 06: Calculator Implementation Using LEX and YACC

## Pseudocode
```text
LEX:
    MATCH [0-9]+(\.[0-9]+)? -> yylval = atof(yytext); RETURN NUM
    MATCH whitespace        -> IGNORE
    MATCH '
' | OTHER      -> RETURN yytext[0]

YACC:
    TYPE: double
    PRECEDENCE:
        LEFT  '+', '-'
        LEFT  '*', '/'
        RIGHT UMINUS

    GRAMMAR:
        Statement -> E '
' { PRINT "Answer:", $1 }
        E -> E '+' E   { $$ = $1 + $3 }
           | E '-' E   { $$ = $1 - $3 }
           | E '*' E   { $$ = $1 * $3 }
           | E '/' E   { IF $3 == 0 ERROR ELSE $$ = $1 / $3 }
           | '-' E     { $$ = -$2 }
           | '(' E ')' { $$ = $2 }
           | NUM       { $$ = $1 }
```
