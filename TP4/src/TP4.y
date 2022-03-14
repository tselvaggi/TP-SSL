%{ 
//Definiciones y declaraciones de C
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

#define YYDEBUG 1

extern FILE* yyin;
extern int yylineno;
int tipo_sentencia=0;
int tipo_declaracion=0;
char* tipo;
char* identificador;

int yylex(void);
int yywrap(){
    return(1);
}

void yyerror (char const *s) {

}

%}

%union {
    char* cadena;
    int entero;
    float real;
    char caracter;
}

%token <cadena> IDENTIFICADOR
%token <cadena> LITERAL_CADENA
%token <cadena> CONTINUE_O_BREAK
%token <entero> CONSTANTE_ENTERA
%token <real> CONSTANTE_REAL
%token <caracter> CONSTANTE_CARACTER
%token <cadena> ESPECIFICADOR_DE_TIPOS
%token <cadena> CALIFICADOR_DE_TIPOS
%token <cadena> ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO
%token <cadena> ESPECIFICADOR_STRUCT_UNION
%token <cadena> OPERADOR_ASIGNACION
%token <cadena> IGUAL_O_DISTINTO
%token <cadena> SIMBOLO_RELACIONAL
%token <cadena> SIMBOLO_CORRIMIENTO
%token <cadena> MAS_MAS_O_MENOS_MENOS
%token <cadena> TRES_PUNTOS
%token <cadena> AND
%token <cadena> OR
%token <cadena> FLECHA
%token <cadena> ENUM WHILE DO FOR SWITCH CASE DEFAULT RETURN IF ELSE
%token <cadena> GOTO
%token <cadena> SIZEOF
%token <cadena> TYPEDEF
%token <cadena> ERROR_LEXICO
//%token <cadena> INCLUDE
//%token <cadena> DEFINE
%%
unidad_de_programa:     // vacio
                        //| INCLUDE unidad_de_programa                                                     
                        //| DEFINE expresion_primaria unidad_de_programa                                           
                        | unidad_de_programa {tipo_declaracion=0;} unidad_de_traduccion
;
unidad_de_traduccion:   declaracion_externa
                        | sentencia
                        | ERROR_LEXICO {imprimirError("[ERROR LEXICO]", $<cadena>1, yylineno);}
                        | error {imprimirError("[ERROR SINTACTICO]", "", yylineno);} unidad_de_traduccion {yyerrok;}
;
declaracion_externa:    definicion_de_funcion
                        | declaracion
;
definicion_de_funcion:  especificadores_de_declaracion declarador lista_de_declaracion {tipo_declaracion=0;} sentencia_compuesta 
                        | declarador lista_de_declaracion {tipo_declaracion=0;}  sentencia_compuesta
                        | especificadores_de_declaracion declarador {tipo_declaracion=0;} sentencia_compuesta
                        | declarador {tipo_declaracion=0;}  sentencia_compuesta
;
declaracion:    especificadores_de_declaracion lista_declaradores_init ';' {imprimirInfo(tipo_declaracion, tipo, identificador, yylineno);}
                | especificadores_de_declaracion ';'
;
lista_de_declaracion:   declaracion 
                        | lista_de_declaracion declaracion 
;
especificadores_de_declaracion: ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO especificadores_de_declaracion_o_vacio
                                | especificador_de_tipo especificadores_de_declaracion_o_vacio
                                | CALIFICADOR_DE_TIPOS especificadores_de_declaracion_o_vacio
;
especificadores_de_declaracion_o_vacio: especificadores_de_declaracion
                                        | //vacio
;
especificador_de_tipo:  ESPECIFICADOR_DE_TIPOS {tipo=strdup($<cadena>1);}
                        |especificador_estructura_o_union
                        |especificador_enum
                        |TYPEDEF // posible cambio
;
especificador_estructura_o_union:       a '{' {tipo=strdup($<cadena>1);} lista_declaraciones_struct '}'
                                        | a {tipo=strdup($<cadena>1);}
;
/*
 especificador_estructura_o_union:      ESPECIFICADOR_STRUCT_UNION IDENTIFICADOR {tipo=strdup($<cadena>1);identificador=strdup($<cadena>2);} '{' lista_declaraciones_struct '}'
                                        | ESPECIFICADOR_STRUCT_UNION '{' lista_declaraciones_struct '}'
                                        | ESPECIFICADOR_STRUCT_UNION IDENTIFICADOR {tipo=strdup($<cadena>2);}
;*/
a:      ESPECIFICADOR_STRUCT_UNION IDENTIFICADOR {tipo=strdup($<cadena>1); identificador=strdup($<cadena>2);}
        | ESPECIFICADOR_STRUCT_UNION {tipo=strdup($<cadena>1);}
;
lista_declaraciones_struct:     declaracion_struct
                                | lista_declaraciones_struct declaracion_struct
;
lista_declaradores_init:        declarador_init 
                                | lista_declaradores_init ',' declarador_init
;
declarador_init: declarador 
                | declarador '=' inicializador                                  
;
declaracion_struct: lista_calificador_especificador lista_declaradores_struct ';'
;
lista_calificador_especificador: especificador_de_tipo lista_calificador_especificador
                                | especificador_de_tipo
                                | CALIFICADOR_DE_TIPOS lista_calificador_especificador
                                | CALIFICADOR_DE_TIPOS
;
lista_declaradores_struct:      declarador_struct
                                | lista_declaradores_struct ',' declarador_struct
;
declarador_struct:      declarador
                        | declarador ':' expresion_condicional
                        | ':' expresion_condicional
;
especificador_enum:     ENUM IDENTIFICADOR '{' lista_de_enumerador '}'
                        | ENUM '{' lista_de_enumerador '}'
                        | ENUM IDENTIFICADOR
;
lista_de_enumerador:    enumerador
                        | lista_de_enumerador ',' enumerador
;
enumerador: IDENTIFICADOR {identificador=strdup($<cadena>1);}
            | IDENTIFICADOR {identificador=strdup($<cadena>1);} '=' expresion_condicional
;
declarador: apuntador declarador_directo
            | declarador_directo
;
declarador_directo:     IDENTIFICADOR {if(tipo_declaracion == 0) identificador = strdup($<cadena>1);} R_declarador_directo
                        | '(' declarador ')' R_declarador_directo
;
R_declarador_directo:   '[' expresion_condicional ']' R_declarador_directo //ARRAYS - chequear
                        |'['  ']' R_declarador_directo //ARRAYS
                        |'(' {tipo_declaracion=1;} lista_tipos_de_parametro ')' R_declarador_directo
                        |'(' {tipo_declaracion=1;} lista_de_identificadores ')' R_declarador_directo
                        |'(' {tipo_declaracion=1;} ')' R_declarador_directo
                        | // vacio

apuntador:      '*' apuntador_aux
;
apuntador_aux:  apuntador apuntador_aux2
                | apuntador_aux2
;
apuntador_aux2: lista_calificadores_de_tipo
                | //vacio
;
lista_calificadores_de_tipo: CALIFICADOR_DE_TIPOS
                           | lista_calificadores_de_tipo CALIFICADOR_DE_TIPOS
;
lista_tipos_de_parametro:  lista_de_parametros
                          | lista_de_parametros ',' TRES_PUNTOS
;
lista_de_parametros: declaracion_de_parametro
                    | lista_de_parametros ',' declaracion_de_parametro
;
declaracion_de_parametro:       especificadores_de_declaracion declarador
                                | especificadores_de_declaracion declarador_abstracto
                                | especificadores_de_declaracion
;
lista_de_identificadores:       IDENTIFICADOR {identificador = strdup($<cadena>1);}
                                | lista_de_identificadores ',' IDENTIFICADOR {identificador = strdup($<cadena>3);}
;
inicializador:  expresion_de_asignacion
                | '{' lista_de_inicializadores'}'
                | '{' lista_de_inicializadores',' '}'
;
lista_de_inicializadores:       inicializador
                                | lista_de_inicializadores ',' inicializador
;
nombre_de_tipo:         lista_calificador_especificador declarador_abstracto
                        | lista_calificador_especificador
;
declarador_abstracto:   apuntador
                        | apuntador declarador_abstracto_directo
                        | declarador_abstracto_directo
;
declarador_abstracto_directo:   '(' declarador_abstracto ')'                                       
                                | declarador_abstracto_directo '[' expresion_condicional ']'                                 
                                | '[' expresion_condicional ']'
                                | declarador_abstracto_directo '[' ']'
                                | '[' ']'
                                | declarador_abstracto_directo '(' lista_tipos_de_parametro ')'
                                | '(' lista_tipos_de_parametro ')'
                                | declarador_abstracto_directo '(' ')'
                                | '(' ')'
;
sentencia:      sentencia_etiquetada
                | sentencia_expresion {imprimirData("Expresion", tipo_sentencia, yylineno); tipo = 0;}
                | sentencia_compuesta // No se hace
                | sentencia_de_seleccion
                | sentencia_de_iteracion
                | sentencia_de_salto
;
sentencia_etiquetada:   IDENTIFICADOR {imprimirData("Etiquetada", tipo_sentencia, yylineno); identificador = strdup($<cadena>1);} ':' sentencia
                        | CASE {imprimirData("Etiquetada", tipo_sentencia, yylineno);} expresion_condicional  ':' sentencia
                        | DEFAULT {imprimirData("Etiquetada", tipo_sentencia, yylineno);} ':' sentencia
;
sentencia_expresion:     expresion ';'
                        | ';'
;
sentencia_compuesta:    '{' X '}'
                        | '{' Z '}'
;

X:      lista_de_declaracion Y
        | //vacio
;
Y:      lista_de_sentencias X
        | //vacio
;
Z:      lista_de_sentencias X
;
lista_de_sentencias:    sentencia
                        | lista_de_sentencias sentencia
;
sentencia_de_seleccion: IF {imprimirData("de Seleccion", tipo_sentencia, yylineno);} '(' expresion ')' sentencia sentencia_de_seleccion_aux
                        | SWITCH {imprimirData("de Seleccion", tipo_sentencia, yylineno);} '(' expresion ')' sentencia
;
sentencia_de_seleccion_aux:     ELSE {imprimirData("de Seleccion", tipo_sentencia, yylineno);} sentencia
                                | //vacio
;
sentencia_de_iteracion:  WHILE {imprimirData("de Iteracion", tipo_sentencia, yylineno);} '(' expresion ')' sentencia
                        | DO {imprimirData("de Iteracion", tipo_sentencia, yylineno);} sentencia WHILE '(' expresion ')' ';'
                        | FOR {imprimirData("de Iteracion", tipo_sentencia, yylineno);} '(' expresion_o_vacio ';' expresion_o_vacio ';' expresion_o_vacio ')' sentencia
;
expresion_o_vacio:  expresion
                    | // vacio
;
sentencia_de_salto:     GOTO IDENTIFICADOR ';' {identificador = strdup($<cadena>2); imprimirData("de Salto", tipo_sentencia, yylineno);} 
                        | CONTINUE_O_BREAK ';' {imprimirData("de Salto", tipo_sentencia, yylineno);}
                        | RETURN {imprimirData("de Salto", tipo_sentencia, yylineno);} expresion ';' //falta
                        | RETURN ';' {imprimirData("de Salto", tipo_sentencia, yylineno);}
;
expresion:      expresion_de_asignacion
                | expresion ',' expresion_de_asignacion
;
expresion_de_asignacion:        expresion_condicional
                                | expresion_unaria operador_de_asignacion expresion_de_asignacion {if(tipo_sentencia<1) tipo_sentencia=1;}
;
operador_de_asignacion:         OPERADOR_ASIGNACION
                                |'='                                     
;
expresion_condicional:  expresion_logica_or
                        | expresion_logica_or '?' expresion ':' expresion_condicional {if(tipo_sentencia<2) tipo_sentencia=2;}
;  
expresion_logica_or:    expresion_logica_and
                        | expresion_logica_or OR expresion_logica_and {if(tipo_sentencia<3) tipo_sentencia=3;}
;
expresion_logica_and:   expresion_or_inclusivo
                        | expresion_logica_and AND expresion_or_inclusivo {if(tipo_sentencia<3) tipo_sentencia=3;}
;
expresion_or_inclusivo: expresion_or_exclusivo
                        | expresion_or_inclusivo '|' expresion_or_exclusivo {if(tipo_sentencia<3) tipo_sentencia=3;}
;
expresion_or_exclusivo: expresion_and
                        | expresion_or_exclusivo '^' expresion_and {if(tipo_sentencia<3) tipo_sentencia=3;}
;
expresion_and: expresion_de_igualdad
                | expresion_and '&' expresion_de_igualdad {if(tipo_sentencia<3) tipo_sentencia=3;}
;
expresion_de_igualdad: expresion_relacional
                        | expresion_de_igualdad IGUAL_O_DISTINTO expresion_relacional {if(tipo_sentencia<4) tipo_sentencia=4;}
;
expresion_relacional:   expresion_de_corrimiento
                        | expresion_relacional SIMBOLO_RELACIONAL expresion_de_corrimiento {if(tipo_sentencia<5) tipo_sentencia=5;}
;
expresion_de_corrimiento:       expresion_aditiva
                                | expresion_de_corrimiento SIMBOLO_CORRIMIENTO expresion_aditiva {if(tipo_sentencia<6) tipo_sentencia=6;}
;
expresion_aditiva:      expresion_multiplicativa
                        | expresion_aditiva '+' expresion_multiplicativa {if(tipo_sentencia<7) tipo_sentencia=7;}
                        | expresion_aditiva '-' expresion_multiplicativa {if(tipo_sentencia<7) tipo_sentencia=7;}
;
expresion_multiplicativa:       expresion_cast
                                | expresion_multiplicativa '*' expresion_cast {if(tipo_sentencia<8) tipo_sentencia=8;}
                                | expresion_multiplicativa '/' expresion_cast {if(tipo_sentencia<8) tipo_sentencia=8;}
                                | expresion_multiplicativa '%' expresion_cast {if(tipo_sentencia<8) tipo_sentencia=8;}
;
expresion_cast: expresion_unaria
                | '(' nombre_de_tipo ')' expresion_cast {if(tipo_sentencia<9) tipo_sentencia=9;}
;
expresion_unaria:       expresion_posfija
                        | MAS_MAS_O_MENOS_MENOS expresion_unaria {if(tipo_sentencia<10) tipo_sentencia=10;}
                        | operador_unario expresion_cast {if(tipo_sentencia<10) tipo_sentencia=10;}
                        | SIZEOF expresion_unaria {if(tipo_sentencia<10) tipo_sentencia=10;}
                        | SIZEOF '(' nombre_de_tipo ')' {if(tipo_sentencia<10) tipo_sentencia=10;}
;
operador_unario:        '&'
                        | '*'
                        | '+'
                        | '-'
                        | '~'
                        | '!'
;
expresion_posfija:      expresion_primaria
                        | expresion_posfija '[' expresion ']' {if(tipo_sentencia<11) tipo_sentencia=11;}
                        | expresion_posfija '(' lista_expresiones_argumento ')' {if(tipo_sentencia<11) tipo_sentencia=11;}
                        | expresion_posfija '(' ')' {if(tipo_sentencia<11) tipo_sentencia=11;}
                        | expresion_posfija '.' IDENTIFICADOR {identificador = strdup($<cadena>3);if(tipo_sentencia<11) tipo_sentencia=11;}
                        | expresion_posfija FLECHA IDENTIFICADOR {identificador = strdup($<cadena>3);if(tipo_sentencia<11) tipo_sentencia=11;}
                        | expresion_posfija MAS_MAS_O_MENOS_MENOS {if(tipo_sentencia<11) tipo_sentencia=11;}
;
expresion_primaria:     IDENTIFICADOR {identificador = strdup($<cadena>1);}
                        | constante
                        | LITERAL_CADENA
                        | '(' expresion ')'
;
lista_expresiones_argumento:    expresion_de_asignacion 
                                | lista_expresiones_argumento ',' expresion_de_asignacion 
;
constante:      CONSTANTE_ENTERA
                | CONSTANTE_CARACTER
                | CONSTANTE_REAL
;
%%
void main (int argc, char *argv[])
{
        yyin = fopen(argv[1], "r");
        /*
#ifdef BISON_DEBUG
        yydebug = 1;
#endif
*/
        printf("||--------------- REPORTE ---------------||");
        yyparse ();
        fclose(yyin);
        printf("\n\n||---------------------------------------||\n");
}