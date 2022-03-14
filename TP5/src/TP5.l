%option noyywrap
%option yylineno

%{
#include "TP5.tab.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

extern FILE* yyin;

char* auxiliar;

%}
DIGITO_DECIMAL [0-9]
DIGITO_OCTAL [0-7]
DIGITO_HEXADECIMAL [a-fA-F0-9]
PARTE_EXPONENTE [eE](\+|\-)?{DIGITO_DECIMAL}+
LETRA [a-zA-Z]
ESPECIFICADOR_STRUCT_UNION struct|union
ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO typedef|static|auto|register|extern
ESPECIFICADOR_DE_TIPOS void|char|short|int|long|float|double|signed|unsigned
CALIFICADOR_DE_TIPOS const|volatile
IDENTIFICADOR ({LETRA}|"_")({LETRA}|{DIGITO_DECIMAL}|"_")*

/*Constantes*/
CONSTANTE_DECIMAL [1-9]{DIGITO_DECIMAL}*
CONSTANTE_OCTAL 0{DIGITO_OCTAL}*
CONSTANTE_HEXA 0[xX]{DIGITO_HEXADECIMAL}+
CONSTANTE_CARACTER \'{CARACTER}+\'
CONSTANTE_REAL ({DIGITO_DECIMAL}*\.{DIGITO_DECIMAL}+|{DIGITO_DECIMAL}+\.){PARTE_EXPONENTE}?

/*Comentarios*/
COMENTARIO_SIMPLE  "//"[^"\n"]*
COMENTARIO_MULTILINEA "/*"((\*+[^/*])|([^*]))*\**"*/"

/*Operadores y Caracteres de Puntuacion*/
OPERADOR_ASIGNACION "*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|=" 

/*Literal Cadena*/
SECUENCIA_DE_ESCAPE_HEXADECIMAL \\x{DIGITO_HEXADECIMAL}{1,2}
SECUENCIA_DE_ESCAPE_OCTAL \\({DIGITO_OCTAL}|{DIGITO_OCTAL}{1,3})
SECUENCIA_DE_ESCAPE_SIMPLE \\(\'|\"|\?|\\|a|b|f|n|r|t|v)
SECUENCIA_DE_ESCAPE {SECUENCIA_DE_ESCAPE_SIMPLE}|{SECUENCIA_DE_ESCAPE_OCTAL}|{SECUENCIA_DE_ESCAPE_HEXADECIMAL}
CUALQUIER_CARACTER_EXCEPTO_COMILLAS_O_BARRA_INVERTIDA [^'"\\]
CARACTER {CUALQUIER_CARACTER_EXCEPTO_COMILLAS_O_BARRA_INVERTIDA}|{SECUENCIA_DE_ESCAPE}
SECUENCIA_DE_CARACTERES {CARACTER}*
LITERAL_CADENA \"{SECUENCIA_DE_CARACTERES}\"
CONTINUE_O_BREAK continue|break
%%
{ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO} {return ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO;}
{ESPECIFICADOR_DE_TIPOS} {free(yylval.myStruct.tipo); yylval.myStruct.tipo = strdup(yytext); return ESPECIFICADOR_DE_TIPOS;}
{CALIFICADOR_DE_TIPOS} {free(yylval.myStruct.cadena); yylval.myStruct.cadena = strdup(yytext); return CALIFICADOR_DE_TIPOS;}
{ESPECIFICADOR_STRUCT_UNION} {free(yylval.myStruct.cadena); yylval.myStruct.cadena = strdup(yytext); return ESPECIFICADOR_STRUCT_UNION;}
{CONTINUE_O_BREAK} {free(yylval.myStruct.cadena); yylval.myStruct.cadena = strdup(yytext); return CONTINUE_O_BREAK;}
{CONSTANTE_REAL} {free(yylval.myStruct.tipo); yylval.myStruct.entero = atof(yytext); yylval.myStruct.tipo = strdup("float"); return CONSTANTE_REAL;}
{CONSTANTE_DECIMAL}|{CONSTANTE_OCTAL}|{CONSTANTE_HEXA} {free(yylval.myStruct.tipo); yylval.myStruct.entero = atoi(yytext); yylval.myStruct.tipo = strdup("int"); return CONSTANTE_ENTERA;}
{CONSTANTE_CARACTER} {yylval.myStruct.simbolo = yytext[0]; yylval.myStruct.tipo = strdup("char"); return CONSTANTE_CARACTER;}
{LITERAL_CADENA} {free(yylval.myStruct.cadena); yylval.myStruct.cadena = strdup(yytext); yylval.myStruct.tipo = strdup("char*"); return LITERAL_CADENA;}
{OPERADOR_ASIGNACION} {free(yylval.myStruct.cadena); yylval.myStruct.cadena = strdup(yytext); return OPERADOR_ASIGNACION;}
"enum" {return ENUM;}
"while" {return WHILE;}
"do" {return DO;}
"for" {return FOR;}
"if" {return IF;}
"else" {return ELSE;}
"switch" {return SWITCH;}
"case" {return CASE;}
"default" {return DEFAULT;}
"return" {return RETURN;}
"goto" {return GOTO;}
"sizeof" {return SIZEOF;}
"typedef" {return TYPEDEF;}
"["|"]"|"("|")"|"{"|"}"|"&"|"*"|"+"|"-"|"~"|"#"|"!"|"/"|"%"|"|"|"="|"?"|","|":"|";"|"." {yylval.myStruct.simbolo = yytext[0];return yytext[0];}
"<<"|">>" {free(yylval.myStruct.cadena); yylval.myStruct.cadena = strdup(yytext); return SIMBOLO_CORRIMIENTO;}
"<"|">"|"<="|">=" {free(yylval.myStruct.cadena); yylval.myStruct.cadena = strdup(yytext); return SIMBOLO_RELACIONAL;}
"=="|"!=" {free(yylval.myStruct.cadena); yylval.myStruct.cadena = strdup(yytext); return IGUAL_O_DISTINTO;}
"&&" {return AND;}
"||" {return OR;}
"..." {return TRES_PUNTOS;}
"->" {return FLECHA;}
"++"|"--" {free(yylval.myStruct.cadena); yylval.myStruct.cadena = strdup(yytext); return MAS_MAS_O_MENOS_MENOS;}
{IDENTIFICADOR} {free(yylval.myStruct.identificador); yylval.myStruct.identificador = strdup(yytext); return IDENTIFICADOR;}
{COMENTARIO_SIMPLE} {;}
{COMENTARIO_MULTILINEA} {;}
[\t' '\n] {;}
. {free(auxiliar); auxiliar = strdup(yytext); insertarError(&listaErrores, "", auxiliar,'L', yylineno);}
%%