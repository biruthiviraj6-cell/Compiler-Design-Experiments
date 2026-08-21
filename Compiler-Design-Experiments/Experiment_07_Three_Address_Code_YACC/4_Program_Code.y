%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(const char *s);

int tempCount = 1;

void printTAC(char* result, char* op1, const char* op, char* op2) {
    printf("%s = %s %s %s\n", result, op1, op, op2);
}

void printAssign(char* var, char* val) {
    printf("%s = %s\n", var, val);
}
%}

%union {
    char* str;
}

%token <str> ID NUM
%type <str> expr stmt

%left '+' '-'
%left '*' '/'

%%
stmt:
    ID '=' expr {
        printAssign($1, $3);
    }
    ;

expr:
    expr '+' expr {
        char temp[10];
        sprintf(temp, "t%d", tempCount++);
        printTAC(temp, $1, "+", $3);
        $$ = strdup(temp);
    }
    | expr '-' expr {
        char temp[10];
        sprintf(temp, "t%d", tempCount++);
        printTAC(temp, $1, "-", $3);
        $$ = strdup(temp);
    }
    | expr '*' expr {
        char temp[10];
        sprintf(temp, "t%d", tempCount++);
        printTAC(temp, $1, "*", $3);
        $$ = strdup(temp);
    }
    | expr '/' expr {
        char temp[10];
        sprintf(temp, "t%d", tempCount++);
        printTAC(temp, $1, "/", $3);
        $$ = strdup(temp);
    }
    | '(' expr ')' {
        $$ = $2;
    }
    | ID {
        $$ = $1;
    }
    | NUM {
        $$ = $1;
    }
    ;
%%

int main(void) {
    printf("Enter the expression (e.g. a=b+c*d):\n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    printf("Error: %s\n", s);
    return 0;
}
