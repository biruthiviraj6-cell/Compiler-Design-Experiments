# Experiment 03: Recognize Valid Arithmetic Expression Using YACC

### Sample Output:
```text
$ lex art_expr.l
$ yacc -d art_expr.y
$ gcc lex.yy.c y.tab.c -o art_expr

$ ./art_expr
Enter the Expression:
a+b*c-d/e
Valid Expression

$ ./art_expr
Enter the Expression:
a=b
Invalid Expression
```

### Result:
Thus, the program to recognize a valid arithmetic expression that uses operators `+`, `-`, `*`, and `/` using LEX and YACC tools was executed and verified successfully.
