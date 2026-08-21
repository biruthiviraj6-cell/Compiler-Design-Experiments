%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%option noyywrap

%%
[0-9]+(\.[0-9]+)? { yylval.dval = atof(yytext); return NUM; }
[ \t]             { /* skip whitespace */ }
\n                { return '\n'; }
.                 { return yytext[0]; }
%%
