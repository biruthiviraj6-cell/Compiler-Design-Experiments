%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *s);
%}

%union {
    double dval;
}

%token <dval> NUM
%type <dval> E

%left '+' '-'
%left '*' '/'
%right UMINUS

%%
Statement:
    E '\n' { printf("Answer: %g\n", $1); exit(0); }
    | E     { printf("Answer: %g\n", $1); exit(0); }
    ;

E:
    E '+' E           { $$ = $1 + $3; }
    | E '-' E         { $$ = $1 - $3; }
    | E '*' E         { $$ = $1 * $3; }
    | E '/' E         {
                          if ($3 == 0) {
                              printf("Error: Division by zero!\n");
                              exit(1);
                          }
                          $$ = $1 / $3;
                      }
    | '-' E %prec UMINUS { $$ = -$2; }
    | '(' E ')'       { $$ = $2; }
    | NUM             { $$ = $1; }
    ;
%%

int main(void) {
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    printf("Invalid Expression\n");
    return 0;
}
