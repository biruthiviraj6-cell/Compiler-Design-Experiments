# Experiment 01: Symbol Table Implementation

### Algorithm:
1. **Start** the program.
2. Define a structure `table` containing fields for variable name (`var`) and its associated value (`value`).
3. Maintain an array of symbol table records and a counter `n` for total entries.
4. Implement the following operations:
   - **Create**: Prompt the user for the number of initial entries, validate variable naming rules (must start with an alphabet), ensure no duplicates, and populate the table.
   - **Insert**: Check if the table has space. If yes, increment count, read new variable-value pair, check validity and uniqueness, and add to the table.
   - **Modify**: Search for the variable in the table. If found, prompt for the new variable name and value, validate, and update the record. If not found, report error.
   - **Search**: Linearly search through table entries comparing variable names. Return index if found, else return 0.
   - **Display**: Iterate through all entries and print the variable names and their values in tabular format.
5. Provide an interactive menu for the user to choose operations (1. Create, 2. Insert, 3. Modify, 4. Search, 5. Display, 6. Exit).
6. **Stop** the execution when choice 6 is selected.

### Procedure:
1. Open a terminal and create `symbol_table.c`.
2. Compile using GCC: `gcc symbol_table.c -o symbol_table`.
3. Run the executable: `./symbol_table`.
4. Perform symbol table operations and verify outputs.
