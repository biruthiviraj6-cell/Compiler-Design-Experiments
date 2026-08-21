# Experiment 10: Target Code Generation (TAC to 8086 Assembly)

## Pseudocode
```text
FUNCTION generateAssembly(line):
    IF parse(line, result, op1, operator, op2) MATCHES 4:
        PRINT "MOV AX,", op1
        SWITCH operator:
            CASE '+': PRINT "ADD AX,", op2
            CASE '-': PRINT "SUB AX,", op2
            CASE '*': PRINT "MUL", op2
            CASE '/': PRINT "MOV DX, 0\nMOV BX,", op2, "\nDIV BX"
        PRINT "MOV", result, ", AX"
    ELSE IF parse(line, result, op1) MATCHES 2:
        PRINT "MOV AX,", op1
        PRINT "MOV", result, ", AX"

MAIN:
    READ n
    FOR i = 1 TO n:
        READ tac[i]
    FOR i = 1 TO n:
        generateAssembly(tac[i])
```
