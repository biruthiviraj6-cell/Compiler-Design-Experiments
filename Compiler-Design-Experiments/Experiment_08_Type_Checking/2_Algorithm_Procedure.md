# Experiment 08: Type Checking Implementation

### Algorithm:
1. **Start** the program.
2. Initialize data structures:
   - Symbol table array `tbl` storing `var` (variable name) and `dt` (data type).
   - Supported primitive types: `int`, `float`, `char`, `double`.
3. **Read Declarations**:
   - Parse each declaration line formatted as `<datatype> <varname>;`.
   - Validate data type and ensure no duplicate variable declarations.
   - Insert valid entries into the symbol table until `"END"` is entered.
4. **Read Expressions**:
   - Read assignment expressions formatted as `<result> = <op1> <operator> <op2>;` until `"END"` is entered.
5. **Perform Semantic Analysis / Type Checking**:
   - For each expression:
     a. Search `result`, `op1`, and `op2` in the symbol table.
     b. If any variable is not found, report `"Undefined variable"`.
     c. Retrieve declared data types: `resultvardt`, `arg1dt`, `arg2dt`.
     d. Verify operand compatibility: check if `arg1dt == arg2dt`. If not, report `"Type mismatch between operands"`.
     e. Verify assignment compatibility: check if `resultvardt == arg1dt`. If not, report `"Type mismatch: Lvalue and Rvalue must be same"`.
     f. If all types match, report `"No type mismatch in expression"`.
6. **Stop** the execution.

### Procedure:
1. Create source file `typecheck.c`.
2. Compile with GCC: `gcc typecheck.c -o typecheck`.
3. Run `./typecheck`.
4. Enter sample declarations followed by `END`.
5. Enter expressions to check followed by `END`.
6. Observe semantic analysis output.
