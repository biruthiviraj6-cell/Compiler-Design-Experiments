# Experiment 10: Target Code Generation (TAC to 8086 Assembly)

### Algorithm:
1. **Start** the program.
2. Prompt user for the number of Three-Address Code (TAC) statements `n`.
3. Read each TAC statement line.
4. For each statement:
   - Use `sscanf()` to parse the format into `result = op1 operator op2` or assignment `result = op1`.
   - If it is an arithmetic operation (`op1 operator op2`):
     - Load first operand into accumulator: `MOV AX, op1`.
     - Translate operator:
       - `'+'`: Emit `ADD AX, op2`.
       - `'-'`: Emit `SUB AX, op2`.
       - `'*'`: Emit `MUL op2`.
       - `'/'`: Emit `MOV DX, 0`, `MOV BX, op2`, `DIV BX`.
     - Store accumulator result into destination variable: `MOV result, AX`.
   - If it is a simple assignment (`result = op1`):
     - Emit `MOV AX, op1` followed by `MOV result, AX`.
5. Display the generated 8086 assembly instructions.
6. **Stop** the execution.

### Procedure:
1. Create source file `codegen.c`.
2. Compile with GCC: `gcc codegen.c -o codegen`.
3. Run `./codegen`.
4. Enter the number of TAC lines followed by TAC expressions.
5. Observe the generated 8086 assembly instructions.
