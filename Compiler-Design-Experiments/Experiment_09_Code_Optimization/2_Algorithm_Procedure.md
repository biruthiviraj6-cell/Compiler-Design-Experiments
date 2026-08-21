# Experiment 09: Code Optimization Techniques

### Algorithm:
1. **Start** the program.
2. Read a block of Three-Address Code (TAC) statements from user input or input file (`infile.txt`).
3. Display the unoptimized input TAC block.
4. Process each statement `lhs = op1 opr op2;`:
   - **Constant Folding**:
     - Check if both `op1` and `op2` are numeric constants (`isdigit`).
     - Compute the compile-time result: `res = op1 opr op2`.
     - Output optimized form: `lhs = res;`.
   - **Algebraic Simplification**:
     - Check for identity properties:
       - Multiplication by 1: `x * 1` -> `x`
       - Division by 1: `x / 1` -> `x`
       - Addition with 0: `x + 0` -> `x`
       - Subtraction with 0: `x - 0` -> `x`
     - Output simplified form: `lhs = op1;`.
   - **Strength Reduction**:
     - Replace computationally expensive operations with cheaper equivalents:
       - Multiplication by 2: `x * 2` -> `x + x`
     - Output strength-reduced form: `lhs = op1 + op1;`.
   - **No Optimization**:
     - If no rules match, retain the original statement.
5. Display the complete optimized Three-Address Code with optimization annotations.
6. **Stop** the execution.

### Procedure:
1. Create `optimize.c` and sample input file `infile.txt`.
2. Compile with GCC: `gcc optimize.c -o optimize`.
3. Run `./optimize`, provide TAC lines, and view the optimized code.
