# Experiment 04: Recognize Valid Variable Identifier Using YACC

## Pseudocode
```text
LEX:
    MATCH [a-zA-Z] -> RETURN LET
    MATCH [0-9]    -> RETURN DIG
    MATCH newline  -> RETURN 0
    MATCH other    -> RETURN yytext[0]

YACC:
    TOKENS: LET, DIG

    GRAMMAR:
        variable -> var
        var      -> var DIG
                  | var LET
                  | LET

    MAIN:
        PROMPT "Enter the variable:"
        yyparse()
        PRINT "Valid variable"

    YYERROR:
        PRINT "Invalid variable"
        EXIT
```
