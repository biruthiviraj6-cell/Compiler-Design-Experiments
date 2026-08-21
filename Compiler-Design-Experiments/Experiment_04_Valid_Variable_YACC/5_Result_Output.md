# Experiment 04: Recognize Valid Variable Identifier Using YACC

### Sample Output:
```text
$ lex valvar.l
$ yacc -d valvar.y
$ gcc lex.yy.c y.tab.c -o valvar

$ ./valvar
Enter the variable:
add
Valid variable

$ ./valvar
Enter the variable:
addi
Valid variable

$ ./valvar
Enter the variable:
1add
Invalid variable
```

### Result:
Thus, the program to recognize a valid variable starting with a letter followed by any number of letters or digits using LEX and YACC tools was executed and verified successfully.
