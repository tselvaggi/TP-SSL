%option noyywrap
%option yylineno

%{
#include "TP4.tab.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

extern FILE* yyin;

%}

/*ESPACIO (" ")+
TABULACION (\t)+*/
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
COMENTARIO_MULTILINEA "\/\*"[^(\*\/)]*"\*\/"

/*Operadores y Caracteres de Puntuacion*/
/*CARACTERES_PUNTUACION_OPERADORES "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|"?"|":"|";"|"..."|","|"#"|"##"*/
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
/*"#include" {return INCLUDE;}
"#define" {return DEFINE;}*/

%%
{ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO} {return ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO;}
{ESPECIFICADOR_DE_TIPOS} {yylval.cadena=yytext; return ESPECIFICADOR_DE_TIPOS;}
{CALIFICADOR_DE_TIPOS} {yylval.cadena=yytext; return CALIFICADOR_DE_TIPOS;}
{ESPECIFICADOR_STRUCT_UNION} {yylval.cadena=yytext; return ESPECIFICADOR_STRUCT_UNION;}
{CONTINUE_O_BREAK} {yylval.cadena=yytext; return CONTINUE_O_BREAK;}
{CONSTANTE_REAL} {yylval.entero=atof(yytext); return CONSTANTE_REAL;}
{CONSTANTE_DECIMAL}|{CONSTANTE_OCTAL}|{CONSTANTE_HEXA}|{CONSTANTE_CARACTER} {yylval.entero=atoi(yytext); return CONSTANTE_ENTERA;}
{LITERAL_CADENA} {yylval.cadena=yytext; return LITERAL_CADENA;}
{OPERADOR_ASIGNACION} {yylval.cadena=yytext; return OPERADOR_ASIGNACION;}
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
"["|"]"|"("|")"|"{"|"}"|"&"|"*"|"+"|"-"|"~"|"#"|"!"|"/"|"%"|"|"|"="|"?"|","|":"|";"|"." {return yytext[0];}
"<<"|">>" {yylval.cadena=yytext; return SIMBOLO_CORRIMIENTO;}
"<"|">"|"<="|">=" {yylval.cadena=yytext; return SIMBOLO_RELACIONAL;}
"=="|"!=" {yylval.cadena=yytext; return IGUAL_O_DISTINTO;}
"&&" {return AND;}
"||" {return OR;}
"..." {return TRES_PUNTOS;}
"->" {return FLECHA;}
"++"|"--" {yylval.cadena=yytext; return MAS_MAS_O_MENOS_MENOS;}
{IDENTIFICADOR} {yylval.cadena=yytext; return IDENTIFICADOR;}
{COMENTARIO_SIMPLE} {;}
{COMENTARIO_MULTILINEA} {;}
[\t' '\n] {;}
. {yylval.cadena=yytext; return ERROR_LEXICO;}
%%