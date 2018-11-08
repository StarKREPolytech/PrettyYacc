%{

#include<calc/calc.h>
#include<calc/calc_token.h>

%}
%%
"print"				   {return print;}
"exit"				   {return exit_command;}
[a-zA-Z]			   {calc_lval.id = calc_text[0]; return identifier;}
[0-9]+                 {calc_lval.num = atoi(calc_text); return number;}
[ \t\n]                ;
[-+=;]           	   {return calc_text[0];}
.                      {ECHO; calc_error ("unexpected character");}

%%
int calc_wrap (void) {return 1;}