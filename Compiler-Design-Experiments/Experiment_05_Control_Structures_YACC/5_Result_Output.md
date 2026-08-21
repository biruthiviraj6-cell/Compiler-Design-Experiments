# Experiment 05: Recognize Valid Control Structures Syntax Using YACC

### Sample Output:
```text
$ lex control.l
$ yacc -d control.y
$ gcc lex.yy.c y.tab.c -o control

$ ./control
Enter a C control structure syntax:
if (x < 5) { y = 10; }
Valid control structure syntax.

$ ./control
Enter a C control structure syntax:
while (i < 10) { a = 1; }
Valid control structure syntax.
```

### Result:
Thus, the program to recognize a valid control structure syntax of C language using LEX and YACC was executed and verified successfully.
