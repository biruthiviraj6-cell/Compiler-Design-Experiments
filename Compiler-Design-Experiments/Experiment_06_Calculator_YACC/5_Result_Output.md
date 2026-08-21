# Experiment 06: Calculator Implementation Using LEX and YACC

### Sample Output:
```text
$ lex cal.l
$ yacc -d cal.y
$ gcc lex.yy.c y.tab.c -o calc -lm

$ ./calc
Enter the expression:
2+2
Answer: 4

$ ./calc
Enter the expression:
10+5*2-8/4
Answer: 18
```

### Result:
Thus, the program for implementing a calculator using LEX and YACC was executed and verified successfully.
