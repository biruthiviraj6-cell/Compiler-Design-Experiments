# Experiment 07: Three-Address Code Generation Using LEX and YACC

### Sample Output:
```text
$ lex tac.l
$ yacc -d tac.y
$ gcc lex.yy.c y.tab.c -o tac

$ ./tac
Enter the expression (e.g. a=b+c*d):
a=b+c*d
t1 = c * d
t2 = b + t1
a = t2
```

### Result:
Thus, the program to generate Three-Address Code (TAC) using LEX and YACC was executed and verified successfully.
