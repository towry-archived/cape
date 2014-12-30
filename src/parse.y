// Copyright 2014 by Towry Wang

%{
#include "intern.h"
#include "debug.h"
#include <stdio.h>

#ifdef YYTEXT_POINTER
  extern char *yytext;
#else
  extern char yytext[];
#endif

extern int yylineno;

int error_reported = 0;

void yyerror(const char *);
%}

%output "y.tab.c"
%defines "y.tab.h"
%locations

%token <node> TIDENT TSTRING_CONST TINT_CONST TFLOAT_CONST
%token <node> TTRUE TFALSE
%token TVAR TIMPORT TMODULE TAS TSELF
%token TSTRING TINT TFLOAT
%token TIF TELSE TELIF TBREAK TCONTINUE
%token TFOR TWHILE TIN TNIL TBOOL
%token TRET TFUNC TEND TNOT TASSIGN
%token TAND TOR TINC TDEC TPOW TEQ TNE 
%token TLE TGE TNEWL

%type <node> program stmt_list
%type <node> top_stmt
%type <node> import function_definition stmt 
%type <node> method_call declaration expressions assignment
%type <node> bodystmt bodystmt_list
%type <node> condition logic comparison arithmetic
%type <node> term factor final primary
%type <node> opt_parameters opt_call_args operation
%type <node> declaration_list declaration_specifier type_specifier
%type <node> arguments call_args

%left '+' '-' '|' '^'
%left '*' '/' '%' '&' TAND TNOT
%left '('
%left ')'

%start files

%error-verbose

%%
files
  : program { xtop = make_node(NT_PROGRAM, $1, NULL, null_value()); }
;
program
  : none { $$ = nil; }
  | program stmt_list { $$ = list2($1, $2); }
;
stmt_list
  : newl { $$ = nil; }
  | stmt_list top_stmt newl { $$ = list2($1, $2); }
;
top_stmt
  : import { $$ = $1; }
  | function_definition { $$ = $1; } 
  | stmt { $$ = $1; }
;
stmt
  : method_call { $$ = $1; }
  | declaration { $$ = $1; }
  | expressions { $$ = $1; }
  | assignment { $$ = $1; }
;
bodystmt
  : none { $$ = nil; }
  | bodystmt bodystmt_list { $$ = list2($1, $2); }
;
bodystmt_list
  : newl { $$ = nil; }
  | stmt newl { $$ = $1; }
;
assignment
  : TIDENT TASSIGN expressions { $$ = make_node(NT_VASSIGN, $1, $3, null_value()); }
  | TIDENT '=' expressions { $$ = make_node(NT_ASSIGN, $1, $3, null_value()); }
;
expressions
  : condition { $$ = $1; }
;
condition
  : condition TAND logic { $$ = make_node(NT_AND, $1, $3, null_value()); }
  | condition TOR logic { $$ = make_node(NT_OR, $1, $3, null_value()); }
  | logic { $$ = $1; }
;
logic
  : TNOT comparison { $$ = make_node(NT_NOT, $2, NULL, null_value()); }
  | comparison { $$ = $1; }
;
comparison
  : comparison TEQ arithmetic { $$ = make_node(NT_EQ, $1, $3, null_value()); }
  | comparison TNE arithmetic { $$ = make_node(NT_NE, $1, $3, null_value()); }
  | comparison '<' arithmetic { $$ = make_node(NT_LT, $1, $3, null_value()); }
  | comparison '>' arithmetic { $$ = make_node(NT_GT, $1, $3, null_value()); }
  | comparison TLE arithmetic { $$ = make_node(NT_LE, $1, $3, null_value()); }
  | comparison TGE arithmetic { $$ = make_node(NT_GE, $1, $3, null_value()); }
  | arithmetic { $$ = $1; }
;
arithmetic
  : arithmetic '+' term { $$ = make_node(NT_ADD, $1, $3, null_value()); }
  | arithmetic '-' term { $$ = make_node(NT_SUB, $1, $3, null_value()); }
  | arithmetic '&' term { $$ = make_node(NT_SHAND, $1, $3, null_value()); }
  | arithmetic '|' term { $$ = make_node(NT_SHOR, $1, $3, null_value()); }
  | term { $$ = $1; }
;
term
  : term '*' factor { $$ = make_node(NT_MUL, $1, $3, null_value()); }
  | term '/' factor { $$ = make_node(NT_DIV, $1, $3, null_value()); }
  | term '%' factor { $$ = make_node(NT_MOD, $1, $3, null_value()); }
  | factor { $$ = $1; }
;
factor
  : '-' factor { $$ = make_node(NT_UNEG, $2, NULL, null_value()); }
  | '!' factor { $$ = make_node(NT_UNOT, $2, NULL, null_value()); }
  | final { $$ = $1; }
;
final
  : '(' expressions ')' { $$ = $2; }
  | primary { $$ = $1; }
;
function_definition
  : TFUNC TIDENT '(' opt_parameters ')' bodystmt TEND 
  {
     $<node>$ = list2($4, $6);
     $$ = make_node(NT_FUNC, $2, $<node>$, null_value());
  }
;
opt_parameters
  : none { $$ = nil; }
  | declaration_list { $$ = make_node(NT_PARAM, $1, NULL, null_value()); }
  | declaration_list ',' declaration_list { $$ = make_node(NT_PARAM, $1, $3, null_value()); }
;
declaration
  : TVAR declaration_list { $$ = $2; }
;
declaration_list
  : declaration_specifier type_specifier { $$ = make_node(NT_DECL, $1, $2, null_value()); }
;
declaration_specifier
  : TIDENT { $$ = make_node(NT_VAR, $1, NULL, null_value()); }
  | declaration_specifier ',' TIDENT { $$ = list2($1, make_node(NT_VAR, $1, NULL, null_value())); }
;
type_specifier
  : TINT { $$ = make_node(NT_TYPE, NULL, NULL, int_value(0)); }
  | TFLOAT { $$ = make_node(NT_TYPE, NULL, NULL, float_value(0)); }
  | TSTRING { $$ = make_node(NT_TYPE, NULL, NULL, string_value(NULL)); }
  | TBOOL { $$ = make_node(NT_TYPE, NULL, NULL, bool_value(0)); }
  | TNIL { $$ = make_node(NT_TYPE, NULL, NULL, null_value()); }
;
method_call
  : operation arguments { $$ = make_node(NT_CALL, $1, $2, null_value()); }
;
operation
  : TIDENT { $$ = $1; }
;
arguments
  : '(' opt_call_args ')' { $$ = $2; }
;
opt_call_args
  : none { $$ = make_node(NT_ARGS, NULL, NULL, null_value()); }
  | call_args { $$ = $1; }
;
call_args
  : primary { $$ = make_node(NT_ARGS, $1, NULL, null_value()); }
  | call_args ',' primary { $$ = list2($1, make_node(NT_ARGS, $3, NULL, null_value())); }
;
primary
  : TIDENT { $$ = $1; }
  | TINT_CONST { $$ = $1; }
  | TFLOAT_CONST { $$ = $1; }
  | TSTRING_CONST { $$ = $1; }
  | TTRUE { $$ = $1; }
  | TFALSE { $$ = $1; }
;
import
  : TIMPORT TSTRING_CONST { $$ = make_node(NT_IMPORT, $2, NULL, null_value()); }
  | TIMPORT TSTRING_CONST TAS TIDENT { $$ = make_node(NT_IMPORT, $2, $4, null_value()); }
;
newl
  : '\n'
  | ';' { yyerrok; }
;
none 
  :
;
%%

void
yyerror(const char *msg) {
  fprintf(stderr, "%ld: %s\n", yylineno, msg);
}
