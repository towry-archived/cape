%{
#include "intern.h"
#include "y.tab.h"
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HAVE_UNISTD_H
# define YY_NO_UNISTD_H
#endif

#ifndef FLEX_SCANNER
#undef input
#endif

#define yyterminate() return -1
#define YY_USER_INIT yylloc.first_line = yylloc.first_column

static void lex_skip_comment();
static char* cstr(const char *);
%}


%option outfile="lex.c"
%option noyywrap
%option case-insensitive
%option yylineno

DIGIT     [0-9]
HEX       [0-9A-Fa-f]
IDENT     [a-zA-Z_]
WHITE     [ \t\v\r\f]

%%

"var"      { return(TVAR); }
"import"   { return(TIMPORT); }
"module"   { return(TMODULE); }
"as"       { return(TAS); }
"self"     { return(TSELF); }
"if"       { return(TIF); }
"else"     { return(TELSE); }
"elif"     { return(TELIF); }
"break"    { return(TBREAK); }
"continue" { return(TCONTINUE); }
"for"      { return(TFOR); }
"while"    { return(TWHILE); }
"in"       { return(TIN); }
"nil"      { return(TNIL); }
"int"      { return(TINT); }
"float"    { return(TFLOAT); }
"string"   { return(TSTRING); }
"bool"     { return(TBOOL); }
"true"     { return(TTRUE); }
"false"    { return(TFALSE); }
"ret"      { return(TRET); }
"func"     { return(TFUNC); }
"end"      { return(TEND); }
"not"      { return(TNOT); }
"and"      { return(TAND); }
"or"       { return(TOR); }
"++"       { return(TINC); }
"--"       { return(TDEC); }
"**"       { return(TPOW); }
"=="       { return(TEQ); }
"<>"       { return(TNE); }
"<="       { return(TLE); }
">="       { return(TGE); }
":="       { return(TASSIGN); }

"+"        { return('+'); }
"-"        { return('-'); }
"*"        { return('*'); }
"/"        { return('/'); }
"("        { return('('); }
")"        { return(')'); }
"["        { return('['); }
"]"        { return(']'); }
"{"        { return('{'); }
"}"        { return('}'); }
">"        { return('>'); }
"<"        { return('<'); }
"&"        { return('&'); }
"|"        { return('|'); }
"%"        { return('&'); }
"."        { return('.'); }
","        { return(','); }
":"        { return(':'); }
"?"        { return('?'); }
"="        { return('='); }
"^"        { return('^'); }
"!"        { return('!'); }
"~"        { return('~'); }


{IDENT}({DIGIT}|{IDENT})* { yylval.node = const_ident_node(yytext); return(TIDENT); }

'(''|[^'])*'              { yylval.node = const_string_node(cstr(yytext)); return(TSTRING_CONST); }

\"(\"\"|[^"])*\"          { yylval.node = const_string_node(cstr(yytext)); return(TSTRING_CONST); }

{DIGIT}+"."{DIGIT}+       { yylval.node = const_float_node(atof(yytext)); return(TFLOAT_CONST); }

{DIGIT}+                  { yylval.node = const_int_node(atoi(yytext)); return(TINT_CONST); }

{WHITE}+                  { }

\n                        { return('\n'); }

"#"                       { lex_skip_comment(); }

<<EOF>>                   { return(-1); }
.                         { log_err("Unknown token %s", yytext); return(-1); }

%%

static char * cstr(const char *text) 
{
    int quote = *text++;
    char *str = (char *)malloc(strlen(text));
    char *temp;

    if (!str) {
        fprintf(stderr, "Out of memory\n");
        exit(-1);
    }

    temp = str;
    while(*text != '\0') {
        if (text[0] == quote && text[1] == quote) {
            *temp++ = (char)quote;
            text += 2;
        } else if (text[0] == quote) {
            break;
        } else {
            *temp++ = *text++;
        }
    }
    *temp = '\0';
    return str;
}

static void 
lex_skip_comment() 
{
    int ch;

    for (;;) {
        ch = input();
        if (ch == EOF) { break; }
        else if (ch == '\n') { break; }
    }
}

void 
lex_init(char *s)
{
    yyin = fopen(s, "rb");
    if (yyin == NULL) {
        log_err("Failed to lexing %s", s);
        exit(-1);
    }
}
