# Experiment 03: Recognize Valid Arithmetic Expression Using YACC

## Pseudocode
```text
LEX:
    MATCH [a-zA-Z][0-9a-zA-Z]* -> RETURN ID
    MATCH [0-9]+               -> RETURN DIG
    MATCH whitespace           -> IGNORE
    MATCH newline              -> RETURN 0
    MATCH other char           -> RETURN char

YACC:
    PRECEDENCE:
        LEFT  '+', '-'
        LEFT  '*', '/'
        RIGHT UMINUS

    GRAMMAR:
        stmt -> expn
        expn -> expn '+' expn
              | expn '-' expn
              | expn '*' expn
              | expn '/' expn
              | '-' expn
              | '(' expn ')'
              | DIG
              | ID

    MAIN:
        PROMPT "Enter the Expression"
        yyparse()
        PRINT "Valid Expression"

    YYERROR:
        PRINT "Invalid Expression"
        EXIT
```
