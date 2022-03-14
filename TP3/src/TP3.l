%option noyywrap
%option yylineno

%{
#include "funciones.h"
%}

ESPACIO (" ")+
TABULACION (\t)+

DIGITO_DECIMAL [0-9]
DIGITO_OCTAL [0-7]
DIGITO_HEXADECIMAL [a-fA-F0-9]
PARTE_EXPONENTE [eE](\+|\-)?{DIGITO_DECIMAL}+
LETRA [a-zA-Z]
PALABRA_RESERVADA auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
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

CARACTERES_PUNTUACION_OPERADORES "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"="|"?"|":"|";"|"..."|","|"#"|"##"

/*Literal Cadena*/

SECUENCIA_DE_ESCAPE_HEXADECIMAL \\x{DIGITO_HEXADECIMAL}{1,2}
SECUENCIA_DE_ESCAPE_OCTAL \\({DIGITO_OCTAL}|{DIGITO_OCTAL}{1,3})
SECUENCIA_DE_ESCAPE_SIMPLE \\(\'|\"|\?|\\|a|b|f|n|r|t|v)
SECUENCIA_DE_ESCAPE {SECUENCIA_DE_ESCAPE_SIMPLE}|{SECUENCIA_DE_ESCAPE_OCTAL}|{SECUENCIA_DE_ESCAPE_HEXADECIMAL}
CUALQUIER_CARACTER_EXCEPTO_COMILLAS_O_BARRA_INVERTIDA [^'"\\]
CARACTER {CUALQUIER_CARACTER_EXCEPTO_COMILLAS_O_BARRA_INVERTIDA}|{SECUENCIA_DE_ESCAPE}
SECUENCIA_DE_CARACTERES {CARACTER}+
LITERAL_CADENA \"{SECUENCIA_DE_CARACTERES}\"

%%
{ESPACIO}|{TABULACION} {;}
("\n") {;}
{PALABRA_RESERVADA} { insertarEnLista(&listaElementos, yytext, palabraReservada, yylineno);}
{CONSTANTE_REAL} { insertarEnLista(&listaElementos, yytext, constanteReales, yylineno) ;}
{CONSTANTE_DECIMAL} {insertarEnLista(&listaElementos, yytext, constanteDecimal, yylineno);}
{CONSTANTE_OCTAL} {insertarEnLista(&listaElementos, yytext, constanteOctal, yylineno) ;}
{CONSTANTE_HEXA} {insertarEnLista(&listaElementos, yytext, constanteHexadecimal, yylineno);}
{CONSTANTE_CARACTER} {insertarEnLista(&listaElementos, yytext, constanteCaracter, yylineno);}
{IDENTIFICADOR} { insertarEnLista(&listaElementos, yytext, identificadores, yylineno) ;}
{LITERAL_CADENA} { insertarEnLista(&listaElementos, yytext, literalesCadena, yylineno) ;}
{CARACTERES_PUNTUACION_OPERADORES} { insertarEnLista(&listaElementos, yytext, operadores, yylineno) ;}
{COMENTARIO_SIMPLE} { insertarEnLista(&listaElementos, yytext, comentarios, yylineno) ;}
{COMENTARIO_MULTILINEA} { insertarEnLista(&listaElementos, yytext, comentariosMultilinea, yylineno) ;}
. { insertarEnLista(&listaElementos, yytext, noReconocidos, yylineno) ;}
%%



int main()
{
    //MOSTAR SOLO CUANDO HAY
    yyin = fopen("entrada.c","r+");

    yylex();
    
    mostrarLista(listaElementos);

    liberarLista(listaElementos);

    return 0;
}
