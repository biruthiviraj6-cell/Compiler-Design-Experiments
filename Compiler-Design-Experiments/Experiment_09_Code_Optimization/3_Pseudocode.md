# Experiment 09: Code Optimization Techniques

## Pseudocode
```text
READ TAC lines into code[]
PRINT "Unoptimized Code:", code[]

FOR each line in code[]:
    PARSE lhs, op1, opr, op2
    IF isdigit(op1) AND isdigit(op2):
        val1 = to_int(op1), val2 = to_int(op2)
        res = compute(val1, opr, val2)
        PRINT lhs "=" res "; // Constant Folding"
    ELSE IF (opr == '*' AND op2 == '1') OR (opr == '/' AND op2 == '1'):
        PRINT lhs "=" op1 "; // Algebraic Simplification"
    ELSE IF (opr == '+' AND op2 == '0') OR (opr == '-' AND op2 == '0'):
        PRINT lhs "=" op1 "; // Algebraic Simplification"
    ELSE IF opr == '*' AND op2 == '2':
        PRINT lhs "=" op1 "+" op1 "; // Strength Reduction"
    ELSE:
        PRINT line 
```
