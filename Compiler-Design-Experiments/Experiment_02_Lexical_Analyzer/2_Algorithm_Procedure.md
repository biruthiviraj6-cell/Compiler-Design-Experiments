# Experiment 02: Lexical Analyzer Implementation

### Algorithm:
1. **Start** the program.
2. Initialize tables/arrays for:
   - Delimiters: `' '`, `'\t'`, `'\n'`, `','`, `';'`, `'('`, `')'`, `'{'`, `'}'`, `'['`, `']'`, `'#'`, `'<'`, `'>'`
   - Operators: `'+'`, `'-'`, `'*'`, `'/'`, `'%'`, `'='`, `'!'`
   - Keywords: `int`, `float`, `char`, `double`, `bool`, `void`, `extern`, `unsigned`, `goto`, `static`, `class`, `struct`, `for`, `if`, `else`, `return`, `register`, `long`, `while`, `do`
   - Preprocessor directives: `include`, `define`
   - Standard header files: `stdio.h`, `conio.h`, `stdlib.h`, `string.h`, `ctype.h`, `math.h`
3. Prompt for and open the input C source file (`iplex.c`).
4. Read characters from the file one by one:
   - Check and skip single-line (`//`) and multi-line (`/* ... */`) comments.
   - If a letter is encountered, accumulate alphanumeric characters to form a token, then classify as a keyword, preprocessor directive, header file, or identifier.
   - If a digit is encountered, accumulate digits to form a number constant.
   - If a delimiter is encountered, print it as a Delimiter.
   - If an operator symbol is encountered, check for multi-character operators (e.g. `==`, `<=`) and print as an Operator.
5. Continue scanning until `EOF` is reached.
6. **Stop** the execution.

### Procedure:
1. Write the lexical analyzer program `lexer.c`.
2. Create a test C source file `iplex.c`.
3. Compile with GCC: `gcc lexer.c -o lexer`.
4. Run the executable: `./lexer` and enter `iplex.c` as input.
5. Verify the token classification output.
