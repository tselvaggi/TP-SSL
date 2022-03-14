%{ 
//Definiciones y declaraciones de C
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "funciones.h"

extern FILE* yyin;
extern int yylineno;
int tipo_declaracion=0;
char* tipo;
char* nombre_ppal;
char* nombreFuncion;
char* identificador;
int dimensiones=0;
int cant_corchetes=0;
int contador_parametros=0;
char* auxiliar;
int hay_llaves=0;
int cantidad_valores=0;
int es_puntero=0;

int yylex(void);
int yywrap(){ return(1); }

int yyerror (char* msg) {
        insertarError(&listaErrores, msg, "",'Z', yylineno);
        return 0;
}
%}
%debug
%error-verbose
%union {
        struct yylval_struct {
                char* cadena;
                int entero;
                float real;
                char* tipo;
                char simbolo;
                char* identificador;
                char funcion;
        }myStruct;
}

%token <myStruct> IDENTIFICADOR
%token <myStruct> LITERAL_CADENA
%token <myStruct> CONTINUE_O_BREAK
%token <myStruct> CONSTANTE_ENTERA
%token <myStruct> CONSTANTE_REAL
%token <myStruct> CONSTANTE_CARACTER
%token <myStruct> ESPECIFICADOR_DE_TIPOS
%token <myStruct> CALIFICADOR_DE_TIPOS
%token <myStruct> ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO
%token <myStruct> ESPECIFICADOR_STRUCT_UNION
%token <myStruct> OPERADOR_ASIGNACION
%token <myStruct> IGUAL_O_DISTINTO
%token <myStruct> SIMBOLO_RELACIONAL
%token <myStruct> SIMBOLO_CORRIMIENTO
%token <myStruct> MAS_MAS_O_MENOS_MENOS
%token <myStruct> TRES_PUNTOS
%token <myStruct> AND
%token <myStruct> OR
%token <myStruct> FLECHA
%token <myStruct> ENUM WHILE DO FOR SWITCH CASE DEFAULT RETURN IF ELSE
%token <myStruct> GOTO
%token <myStruct> SIZEOF
%token <myStruct> TYPEDEF
%%
unidad_de_programa:     // vacio
                        | unidad_de_programa {tipo_declaracion = 0;} unidad_de_traduccion
;
unidad_de_traduccion:   declaracion_externa
                        | sentencia
;
declaracion_externa:    definicion_de_funcion
                        | declaracion
;
definicion_de_funcion:  especificadores_de_declaracion declarador lista_de_declaracion {tipo_declaracion = 0;} sentencia_compuesta // DECLARADA Y DEFINIDA
                        | declarador lista_de_declaracion {tipo_declaracion = 0;} sentencia_compuesta // DECLARADA Y DEFINIDA
                        | especificadores_de_declaracion declarador {
                                declararParametros(&listaTS);
                                //if(listaTS->sgte)
                                        if(validarDeclaracionNEW(&listaTS, nombre_ppal, yylineno)){
                                                if(definido(&listaTS, nombre_ppal)) {
                                                        insertarError(&listaErrores, "Funcion ya definida: ", nombre_ppal, 'S', yylineno);
                                                }else{

                                                        definir(&listaTS, nombre_ppal);
                                                }
                                        }else if(definido(&listaTS, nombre_ppal)){
                                                insertarError(&listaErrores, "Funcion ya definida: ", nombre_ppal, 'S', yylineno);
                                        }
                                tipo_declaracion = 0;
                                dimensiones=0;
                        } sentencia_compuesta // DECLARADA Y DEFINIDA
                        | declarador {tipo_declaracion = 0;} sentencia_compuesta // DECLARADA Y DEFINIDA
;
declaracion:    especificadores_de_declaracion lista_declaradores_init ';' {
                                //if(listaTS->sgte)
                                        validarDeclaracionNEW(&listaTS, nombre_ppal, yylineno);
                                dimensiones=0;
                } //ACA SABES QUE ES DECLARACION
                | especificadores_de_declaracion ';'
                | error ';' {yyerrok;} 
;
lista_de_declaracion:   declaracion
                        | lista_de_declaracion declaracion
;
especificadores_de_declaracion: ESPECIFICADOR_CLASE_DE_ALMACENAMIENTO especificadores_de_declaracion_o_vacio
                                | especificador_de_tipo
                                | CALIFICADOR_DE_TIPOS especificadores_de_declaracion_o_vacio
;
especificadores_de_declaracion_o_vacio: especificadores_de_declaracion
                                        | //vacio
;
especificador_de_tipo:  ESPECIFICADOR_DE_TIPOS {tipo = strdup($<myStruct>1.tipo);}
                        |especificador_estructura_o_union
                        |especificador_enum
                        |TYPEDEF
;
especificador_estructura_o_union:      ESPECIFICADOR_STRUCT_UNION IDENTIFICADOR '{' lista_declaraciones_struct '}'
                                        | ESPECIFICADOR_STRUCT_UNION '{' lista_declaraciones_struct '}'
                                        | ESPECIFICADOR_STRUCT_UNION IDENTIFICADOR
;
lista_declaraciones_struct:     declaracion_struct
                                | lista_declaraciones_struct declaracion_struct
;
lista_declaradores_init:        declarador_init 
                                | lista_declaradores_init {tipo_declaracion = 2;} ','  declarador_init  {tipo_declaracion = 0;}
;
declarador_init: declarador {es_puntero=0;}
                | declarador '=' inicializador {
                        if(!es_puntero){
                                if(strcmp($<myStruct>1.tipo, $<myStruct>3.tipo)){
                                                insertarError(&listaErrores, "Asignacion de distinto tipo a: ",$<myStruct>1.identificador, 'S', yylineno);
                        }
                        }
                        
                  }
                        {
                        if(es_puntero && !hay_llaves){
                                insertarError(&listaErrores, "syntax error - Inicializacion de array incorrecta", "", 'Z', yylineno);
                  }
                  es_puntero=0;
                        }
;
declaracion_struct:     lista_calificador_especificador lista_declaradores_struct ';'
                        | error ';' {yyerrok;}
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
enumerador: IDENTIFICADOR
            | IDENTIFICADOR '=' expresion_condicional
;
declarador: apuntador declarador_directo
            | declarador_directo
;
declarador_directo:     IDENTIFICADOR { 
                                {$<myStruct>$.tipo = tipo;}
                                identificador = strdup($<myStruct>1.identificador);
                                if(tipo_declaracion == 0){nombre_ppal = strdup(identificador); insertarTipo_ts(&listaTS, tipo, identificador, dimensiones);}
                                if(tipo_declaracion == 1){insertarListaParametros_ts(listaTS, tipo, identificador, dimensiones); dimensiones=0;}
                                if(tipo_declaracion == 2) {insertarIDHermano_ts(&listaTS, identificador, dimensiones);  validarDeclaracionNEW(&listaTS, identificador, yylineno);}
                                } R_declarador_directo {
                                if(tipo_declaracion == 1){
                                        insertarVoF_ts(&listaTS, 'F');
                                }

                                insertarDimensionTS(listaTS, cant_corchetes);

                                if(dimensiones || cant_corchetes){
                                        es_puntero=1;
                                        dimensiones=0;
                                        cant_corchetes=0;
                                }
                                
                        
                        }       //TENGO SI ES V O F, CANTIDAD DE PARAMETROS Y TIPO EN CASO DE SER F (NO SE SABE SI ES DEFINICION Y/O DECLARACION)
                        | '(' declarador ')' R_declarador_directo
;
R_declarador_directo:   '[' expresion_condicional ']'{cant_corchetes++;} R_declarador_directo
                        |'[' ']' {cant_corchetes++;} R_declarador_directo 
                        |'(' {tipo_declaracion = 1; dimensiones=0; } lista_tipos_de_parametro ')' R_declarador_directo // DECLARADA PERO NO DEFINIDA
                        |'(' {tipo_declaracion = 1;dimensiones=0; } lista_de_identificadores ')' R_declarador_directo // DECLARADA PERO NO DEFINIDA
                        |'(' {tipo_declaracion = 1;dimensiones=0; } ')' R_declarador_directo // DECLARADA PERO NO DEFINIDA
                        | // vacio
;
apuntador:      '*' {dimensiones++;} apuntador
                |'*' {dimensiones++;}
;
lista_tipos_de_parametro:  lista_de_parametros
                          | lista_de_parametros ',' TRES_PUNTOS
;
lista_de_parametros: declaracion_de_parametro
                    | lista_de_parametros ',' declaracion_de_parametro
;
declaracion_de_parametro:       especificadores_de_declaracion declarador
                                | especificadores_de_declaracion declarador_abstracto {insertarListaParametros_ts(listaTS, tipo, "", dimensiones); dimensiones=0;}
                                | especificadores_de_declaracion {insertarListaParametros_ts(listaTS, tipo, "", dimensiones); dimensiones=0;}
;
lista_de_identificadores:       IDENTIFICADOR {identificador = strdup($<myStruct>1.identificador);}
                                | lista_de_identificadores ',' IDENTIFICADOR {identificador = strdup($<myStruct>3.identificador);}
;
inicializador:  expresion_de_asignacion {cantidad_valores++;{$<myStruct>$.tipo = strdup($<myStruct>1.tipo);}}
                | '{' lista_de_inicializadores '}' {hay_llaves++;}
                | '{' lista_de_inicializadores',' '}' {hay_llaves++;}
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
                | sentencia_expresion
                | sentencia_compuesta
                | sentencia_de_seleccion
                | sentencia_de_iteracion
                | sentencia_de_salto
                | error ';' {yyerrok;}
;
sentencia_etiquetada:   IDENTIFICADOR ':' sentencia
                        | CASE expresion_condicional  ':' sentencia
                        | DEFAULT ':' sentencia
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
sentencia_de_seleccion: IF '(' expresion ')' sentencia sentencia_de_seleccion_aux
                        | SWITCH '(' expresion ')' sentencia
;
sentencia_de_seleccion_aux:     ELSE  sentencia
                                | //vacio
;
sentencia_de_iteracion:  WHILE '(' expresion ')' sentencia
                        | DO sentencia WHILE '(' expresion ')' ';'
                        | FOR '(' expresion_o_vacio ';' expresion_o_vacio ';' expresion_o_vacio ')' sentencia
;
expresion_o_vacio:  expresion
                    | // vacio
;
sentencia_de_salto:     GOTO IDENTIFICADOR ';'
                        | CONTINUE_O_BREAK ';'
                        | RETURN  expresion ';'
                        | RETURN ';'
;
expresion:      expresion_de_asignacion 
                | expresion ',' expresion_de_asignacion
;
expresion_de_asignacion:        expresion_condicional {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);}
                                | expresion_unaria operador_de_asignacion expresion_de_asignacion {
                                       
                                        if($<myStruct>1.funcion!='V'){
                                                insertarError(&listaErrores, "syntax error - ValorL no modificable", "", 'Z', yylineno);
                                        }else if(strcmp($<myStruct>1.tipo, $<myStruct>3.tipo)){
                                                insertarError(&listaErrores, "Asignacion de distinto tipo a: ",$<myStruct>1.identificador, 'S', yylineno);
                                        }
                                }
;
operador_de_asignacion:         OPERADOR_ASIGNACION
                                |'='                                     
;
expresion_condicional:  expresion_logica_or {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                        | expresion_logica_or '?' expresion ':' expresion_condicional
;  
expresion_logica_or:    expresion_logica_and {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                        | expresion_logica_or OR expresion_logica_and
;
expresion_logica_and:   expresion_or_inclusivo {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                        | expresion_logica_and AND expresion_or_inclusivo
;
expresion_or_inclusivo: expresion_or_exclusivo {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                        | expresion_or_inclusivo '|' expresion_or_exclusivo
;
expresion_or_exclusivo: expresion_and {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                        | expresion_or_exclusivo '^' expresion_and
;
expresion_and: expresion_de_igualdad {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                | expresion_and '&' expresion_de_igualdad
;
expresion_de_igualdad: expresion_relacional {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                        | expresion_de_igualdad IGUAL_O_DISTINTO expresion_relacional
;
expresion_relacional:   expresion_de_corrimiento {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                        | expresion_relacional SIMBOLO_RELACIONAL expresion_de_corrimiento
;
expresion_de_corrimiento:       expresion_aditiva {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                                | expresion_de_corrimiento SIMBOLO_CORRIMIENTO expresion_aditiva
;
expresion_aditiva:      expresion_multiplicativa {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                        | expresion_aditiva '+' expresion_multiplicativa {
                                $<myStruct>$.funcion='C';
                                if(validarOperacionBinaria(&listaTS, $<myStruct>1.tipo, $<myStruct>3.tipo) == 1){
                                        $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                                        $<myStruct>$.real = $<myStruct>1.real+$<myStruct>3.real;
                                }
                                else if(validarOperacionBinaria(&listaTS, $<myStruct>1.tipo, $<myStruct>3.tipo) == 0){
                                        $<myStruct>$.tipo = "float";
                                        insertarError(&listaErrores, "Operandos de distinto tipo", "", 'S', yylineno);
                                        $<myStruct>$.real = $<myStruct>1.real+$<myStruct>3.real;
                                }
                                else{
                                        $<myStruct>$.tipo = "NULL";
                                        insertarError(&listaErrores, "Operandos no pueden sumarse", "", 'S', yylineno);
                                }}
                        | expresion_aditiva '-' expresion_multiplicativa{
                                $<myStruct>$.funcion='C';
                                if(validarOperacionBinaria(&listaTS, $<myStruct>1.tipo, $<myStruct>3.tipo) == 1){
                                        $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                                        $<myStruct>$.real = $<myStruct>1.real-$<myStruct>3.real;
                                }
                                else if(validarOperacionBinaria(&listaTS, $<myStruct>1.tipo, $<myStruct>3.tipo) == 0){
                                        $<myStruct>$.tipo = "float";
                                        insertarError(&listaErrores, "Operandos de distinto tipo", "", 'S', yylineno);
                                        $<myStruct>$.real = $<myStruct>1.real-$<myStruct>3.real;
                                }
                                else{
                                        $<myStruct>$.tipo = "NULL";
                                        insertarError(&listaErrores, "Operandos no pueden restarse", "", 'S', yylineno);
                                }}
;
expresion_multiplicativa:       expresion_cast {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.funcion=$<myStruct>1.funcion;}
                                | expresion_multiplicativa '*' expresion_cast{
                                        $<myStruct>$.funcion='C';
                                        if(validarOperacionBinaria(&listaTS, $<myStruct>1.tipo, $<myStruct>3.tipo) == 1){
                                                $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                                                $<myStruct>$.real = $<myStruct>1.real*$<myStruct>3.real;
                                        }
                                        else if(validarOperacionBinaria(&listaTS, $<myStruct>1.tipo, $<myStruct>3.tipo) == 0){
                                                $<myStruct>$.tipo = "float";
                                                insertarError(&listaErrores, "Operandos de distinto tipo", "", 'S', yylineno);
                                                $<myStruct>$.real = $<myStruct>1.real*$<myStruct>3.real;
                                        }
                                        else{
                                                $<myStruct>$.tipo = "NULL";
                                                insertarError(&listaErrores, "Operandos no pueden multiplicarse", "", 'S', yylineno);
                                        }}
                                | expresion_multiplicativa '/' expresion_cast {
                                        $<myStruct>$.funcion='C';
                                        if(validarOperacionBinaria(&listaTS, $<myStruct>1.tipo, $<myStruct>3.tipo) == 1){
                                                $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                                                if($<myStruct>3.real == 0){
                                                        insertarError(&listaErrores, "NUNCA DIVIDAS POR 0 - Asignamos 0 mientras tanto :P", "", 'S', yylineno);
                                                        $<myStruct>$.real = 0;
                                                }else{
                                                        $<myStruct>$.real =$<myStruct>1.real/$<myStruct>3.real;
                                                }
                                        }
                                        else if(validarOperacionBinaria(&listaTS, $<myStruct>1.tipo, $<myStruct>3.tipo) == 0){
                                                if($<myStruct>3.real == 0){
                                                        insertarError(&listaErrores, "NUNCA DIVIDAS POR 0 - Asignamos 0 mientras tanto :P", "", 'S', yylineno);
                                                        $<myStruct>$.real = 0;
                                                }else{
                                                        $<myStruct>$.real =$<myStruct>1.real/$<myStruct>3.real;
                                                }
                                                $<myStruct>$.tipo = "float";
                                                insertarError(&listaErrores, "Operandos de distinto tipo", "", 'S', yylineno);
                                        }
                                        else{
                                                $<myStruct>$.tipo = "NULL";
                                                insertarError(&listaErrores, "Operandos no pueden dividirse", "", 'S', yylineno);
                                }}
                                | expresion_multiplicativa '%' expresion_cast
;
expresion_cast: expresion_unaria {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.real =$<myStruct>1.real;$<myStruct>$.funcion=$<myStruct>1.funcion;}
                | '(' nombre_de_tipo ')' expresion_cast
;
expresion_unaria:       expresion_posfija {$<myStruct>$.tipo = strdup($<myStruct>1.tipo);$<myStruct>$.identificador = strdup($<myStruct>1.identificador);$<myStruct>$.real =$<myStruct>1.real;$<myStruct>$.funcion=$<myStruct>1.funcion;}
                        | MAS_MAS_O_MENOS_MENOS expresion_unaria
                        | operador_unario expresion_cast
                        | SIZEOF expresion_unaria
                        | SIZEOF '(' nombre_de_tipo ')'
;
operador_unario:        '&'
                        | '*'
                        | '+'
                        | '-'
                        | '~'
                        | '!'
;
expresion_posfija:      expresion_primaria {
                        $<myStruct>$.funcion=$<myStruct>1.funcion;
                        $<myStruct>$.real =$<myStruct>1.real;
                        $<myStruct>$.identificador = strdup($<myStruct>1.identificador);
                        if($<myStruct>1.funcion =='F'){
                                $<myStruct>$.tipo = "NULL";
                                insertarError(&listaErrores, "Funcion utilizada como variable: ", identificador,'S', yylineno);
                        }else{
                                $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                        }}
                        | expresion_posfija '[' expresion ']'
                        | id {
                                contador_parametros=0;
                                $<myStruct>$.identificador = strdup($<myStruct>1.identificador);
                                if($<myStruct>1.funcion=='F'){
                                        $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                                }else{
                                        $<myStruct>$.tipo = "NULL";
                                        insertarError(&listaErrores, "Variable utilizada como funcion: ", identificador,'S', yylineno);
                        }} '(' lista_expresiones_argumento_o_vacio ')'{
                                if($<myStruct>1.funcion=='F'){
                                        if(cantParams(&listaTS, nombreFuncion) != contador_parametros){
                                                insertarError(&listaErrores, "Cantidad de Parametros Erronea de: ", nombreFuncion,'S', yylineno);
                                        }
                                }
                        }
                        | expresion_posfija '.' IDENTIFICADOR
                        | expresion_posfija FLECHA IDENTIFICADOR
                        | expresion_posfija MAS_MAS_O_MENOS_MENOS
;
expresion_primaria:     id {$<myStruct>$.funcion = $<myStruct>1.funcion;}
                        |constante {
                                $<myStruct>$.real = $<myStruct>1.real;
                                $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                                $<myStruct>$.funcion = 'C';
                        }
                        | LITERAL_CADENA {
                                $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                                $<myStruct>$.funcion = 'C';
                        }	
                        | '(' expresion ')' {
                                $<myStruct>$.real =$<myStruct>2.real;
                                $<myStruct>$.tipo = strdup($<myStruct>2.tipo);
                                $<myStruct>$.funcion = 'C';
                        }
;
id:     IDENTIFICADOR {
        identificador = strdup($<myStruct>1.identificador);
        if(validarDeclaracion(&listaTS, identificador) == 0){
                insertarError(&listaErrores, "Variable no declarada ", identificador,'S', yylineno);
                $<myStruct>$.funcion =  'N';
                $<myStruct>$.tipo = "NULL";
        }else{
                if(esFuncion(&listaTS, $<myStruct>1.identificador)){
                        $<myStruct>$.funcion =  'F';
                        invocar(&listaTS, identificador);
                        nombreFuncion=identificador;
                }else
                        $<myStruct>$.funcion =  'V';
                
                $<myStruct>$.tipo = devolverTipo(&listaTS, identificador);
        }}
;
lista_expresiones_argumento_o_vacio:    lista_expresiones_argumento
                                        | /*vacio*/ 
;
lista_expresiones_argumento: expresion_de_asignacion {contador_parametros++;
        if(tipoCorrecto(nombreFuncion,contador_parametros,$<myStruct>1.tipo,&listaTS)!=1){
                auxiliar = strdup("Parametro N ");
                auxiliar = stringConcatenate(auxiliar, intToString(contador_parametros));
                auxiliar = stringConcatenate(auxiliar,  " es de tipo erroneo en invocacion de: ");
                insertarError(&listaErrores, auxiliar, nombreFuncion, 'S', yylineno);
        }} r_r
;
r_r: ',' expresion_de_asignacion r_r {contador_parametros++;
                if(tipoCorrecto(nombreFuncion, contador_parametros, $<myStruct>1.tipo, &listaTS) != 1){
                        auxiliar = strdup("Parametro N ");
                        auxiliar = stringConcatenate(auxiliar, intToString(contador_parametros));
                        auxiliar = stringConcatenate(auxiliar, " es de tipo erroneo en invocacion de: ");
                        insertarError(&listaErrores, auxiliar, nombreFuncion, 'S', yylineno); 
                }
        }
        |//vacio 
;

constante:      CONSTANTE_ENTERA {
                        $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                        $<myStruct>$.real = $<myStruct>1.entero;
                }
                | CONSTANTE_CARACTER {
                        $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                        $<myStruct>$.real = $<myStruct>1.simbolo;
                }
                | CONSTANTE_REAL {
                        $<myStruct>$.tipo = strdup($<myStruct>1.tipo);
                        $<myStruct>$.real = $<myStruct>1.real;
                }
;
%%
void main (int argc, char *argv[]){
        salvavidas = 0;
        yyin = fopen(argv[1], "r");
        yydebug = 0;
        yyparse ();
        fclose(yyin);
        validarInvocaciones(&listaTS);
        mostrarTS(listaTS);
        mostrarErrores(listaErrores);
}