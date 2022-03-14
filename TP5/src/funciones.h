#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct lista_parametros
{
    char *nombre_param;
    int dim_puntero;
    char *tipo_param;
    struct lista_parametros *sgte;

} lista_parametros;

typedef struct tabla_simbolos
{
    char *identificador;
    int dim_puntero;
    int var_o_func; // 'F' SI ES FUNCION 'V' SI ES VARIABLE
    char *tipo;
    int definido;
    int usado;
    //int cant_parametros;
    struct lista_parametros *inicio_lp;
    struct tabla_simbolos *sgte;

} tabla_simbolos;

typedef struct lista_errores
{
    char *error;
    char tipo;
    int linea;
    char *string;
    struct lista_errores *sgte;

} lista_errores;

int salvavidas;
int tipoCorrecto(char *, int, char *, tabla_simbolos **);
int cantParams(tabla_simbolos **, char *);
void insertarTS(struct tabla_simbolos **, struct tabla_simbolos *);
void insertarListaParametros(struct tabla_simbolos **, struct lista_parametros *);
int validarOperacionBinaria(struct tabla_simbolos **, char *, char *);
int validarDeclaracion(tabla_simbolos **, char *);
char *devolverTipo(tabla_simbolos **, char *);
int esFuncion(tabla_simbolos **, char *);
void insertarEnLista_ts(struct tabla_simbolos **, void *);
void insertarTipo_ts(tabla_simbolos **, char *, char *, int);
void insertarVoF_ts(tabla_simbolos **, int);
void insertarListaParametros_ts(tabla_simbolos *, char *, char *, int);
void insertarIDHermano_ts(tabla_simbolos **, char *, int);
void mostrarTS(tabla_simbolos *);
void insertarDimensionTS(tabla_simbolos *, int);
void mostrarErrores(lista_errores *);
void insertarError(lista_errores **, char *, char *, char, int);
int definido(tabla_simbolos **, char *);
void invocar(tabla_simbolos **, char *);
void definir(tabla_simbolos **, char *);
void validarInvocaciones(tabla_simbolos **);
bool validarDeclaracionNEW(tabla_simbolos **, char *, int);
void eliminarNodo(tabla_simbolos **, tabla_simbolos *);
bool compararParametros(tabla_simbolos *, tabla_simbolos *, int);
bool compararCantidadParametros(tabla_simbolos *, tabla_simbolos *, int);
void declararParametros(tabla_simbolos **);
char *intToString(int);
char *stringConcatenate(char *, char *);

struct tabla_simbolos *listaTS;
struct lista_errores *listaErrores;

#endif