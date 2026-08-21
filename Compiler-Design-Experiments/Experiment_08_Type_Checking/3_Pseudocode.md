# Experiment 08: Type Checking Implementation

## Pseudocode
```text
FUNCTION main():
    READ declarations until "END"
    FOR each declaration:
        PARSE datatype, varname
        INSERT into symbol_table(varname, datatype)

    READ expressions until "END"
    FOR each expression:
        PARSE result, op1, op, op2
        r_dt = lookup(result)
        o1_dt = lookup(op1)
        o2_dt = lookup(op2)

        IF any variable is NULL:
            PRINT "Undefined variable"
        ELSE IF o1_dt != o2_dt:
            PRINT "Type mismatch between operands"
        ELSE IF r_dt != o1_dt:
            PRINT "Type mismatch: Lvalue and Rvalue must be same"
        ELSE:
            PRINT "No type mismatch in expression" 
```
