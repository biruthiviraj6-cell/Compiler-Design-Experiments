# Experiment 05: Recognize Valid Control Structures Syntax Using YACC

## Pseudocode
```text
LEX:
    KEYWORDS: if, else, for, while, switch, case, default
    OPERATORS: ==, <=, >=, <, >, =
    PUNCTUATION: {, }, (, ), :, ;
    PATTERNS: ID, NUM

YACC:
    GRAMMAR:
        stmt -> if_stmt | while_stmt | for_stmt | switch_stmt | block
        if_stmt -> IF '(' cond ')' stmt | IF '(' cond ')' stmt ELSE stmt
        while_stmt -> WHILE '(' cond ')' stmt
        for_stmt -> FOR '(' ID '=' NUM ';' cond ';' ID '=' ID ')' stmt
        switch_stmt -> SWITCH '(' ID ')' '{' case_list '}'
        case_list -> CASE NUM ':' stmt | DEFAULT ':' stmt | case_list CASE NUM ':' stmt
        cond -> ID relop (NUM | ID)
        relop -> EQ | LE | GE | LT | GT

    MAIN:
        PROMPT "Enter a C control structure syntax:"
        yyparse()
        PRINT "Valid control structure syntax." 
```
