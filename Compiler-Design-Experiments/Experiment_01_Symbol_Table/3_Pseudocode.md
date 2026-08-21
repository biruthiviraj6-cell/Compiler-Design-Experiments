# Experiment 01: Symbol Table Implementation

## Pseudocode
```text
FUNCTION create():
    READ n
    FOR i = 1 TO n:
        READ var, value
        IF var[0] is not an alphabet:
            RE-PROMPT valid variable name
        IF var exists in tbl[1..i-1]:
            RE-PROMPT unique variable name
        tbl[i] = (var, value)
    DISPLAY table

FUNCTION insert():
    IF n >= MAX_SIZE:
        PRINT "Table is full"
    ELSE:
        n = n + 1
        READ var, value
        VALIDATE var (alphabet start & uniqueness)
        tbl[n] = (var, value)
        DISPLAY table

FUNCTION modify():
    READ search_var
    index = search(search_var, n)
    IF index == 0:
        PRINT "Variable not found"
    ELSE:
        READ new_var, new_value
        VALIDATE new_var
        tbl[index] = (new_var, new_value)
        DISPLAY table

FUNCTION search(var, n):
    FOR i = 1 TO n:
        IF tbl[i].var == var:
            RETURN i
    RETURN 0

FUNCTION display():
    PRINT "VARIABLE    VALUE"
    FOR i = 1 TO n:
        PRINT tbl[i].var, tbl[i].value
```
