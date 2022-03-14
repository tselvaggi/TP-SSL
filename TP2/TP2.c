#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "TP2.h"

#define N 100

enum estados {
    q0,
    q1,
    q2,
    q3
};

typedef struct nodo
{
    char info;
    struct nodo* sig;
}Nodo;

typedef struct TRANSICION
{
    char simbolosAAgregarEnLaPila[3];
    int siguienteEstado;

}TRANSICION;


TRANSICION matrizTT[2][4][6] = { // Agregar fila y columna de error

{//PILA VACIA
{ {"_",q3} ,{"$",q1} ,{"_",q3} ,{"R$",q0} ,{"_",q3},  {"_",q3} },
{ {"$",q1} ,{"$",q1} ,{"$",q0} ,{"_",q3}  ,{"_",q3},  {"_",q3} },
{ {"_",q3} ,{'_',q3} ,{"$",q0} ,{"_",q3}  ,{"EP",q2}, {"_",q3} },
{ {"_",q3} ,{"_",q3} ,{"_",q3} ,{"_",q3}  ,{"_",q3},  {"_",q3} }
},
{//PILA CON ELEMENTOS
{ {"_",q3} ,{"R",q1} ,{"_",q3} ,{"RR",q0} ,{"_",q3},  {"_",q3} },
{ {"R",q1} ,{"R",q1} ,{"R",q0} ,{"_",q3}  ,{"EP",q2}, {"_",q3} },
{ {"_",q3} ,{"_",q3} ,{"R",q0} ,{"_",q3}  ,{"EP",q2}, {"_",q3} },
{ {"_",q3} ,{"_",q3} ,{"_",q3} ,{"_",q3}  ,{"_",q3},  {"_",q3} }
}
};

int getFila (char* estadoActual)
{
    int fila;
    switch (estadoActual[0])
    {
    case q0: fila = 0;
        break;
    case q1: fila = 1;
        break;
    case q2: fila = 2;
        break;
    default: fila = 3;
        break;
    }
    return fila;
}

int getColumna(char caracterLeido)
{
    int columna;
    switch (caracterLeido)
    {
    case '0':
        columna=0;
        break;
    case '1'...'9':
        columna=1;
        break;
    case '+': case '-': case '*': case '/':
        columna=2;
        break;
    case '(':
        columna=3;
        break;
    case ')':
        columna=4;
        break;
    default:
        columna=5;
        break;
    }
    return columna;
}

TRANSICION evaluar(char caracterLeido, char* estadoActual)
{
    int fila = 0;
    int columna = 0;
    int topePila = 0;
    
    switch (estadoActual[1])
    {
    case '$':
        topePila = 0;
        fila = getFila(estadoActual);
        columna = getColumna(caracterLeido);
        break;
    case 'R':
        topePila = 1;
        fila = getFila(estadoActual);
        columna = getColumna(caracterLeido);
        break;
    default:
        break;
    }
    
    return matrizTT[topePila][fila][columna];
}

void imprimirTransicion(TRANSICION transicion, char caracterLeido, char* estadoActual){
    SetConsoleOutputCP(65001);
    
    switch (estadoActual[0])
    {
    case q0: printf("δ( q0 ,");
        break;
    case q1: printf("δ( q1 ,");
        break;
    default: printf("δ( q2 ,");
        break;
    }

    printf(" %c , %c ) -> ", caracterLeido, estadoActual[1]);

    switch (transicion.siguienteEstado)
    {
    case q0: printf("( q0 ,");
        break;
    case q1: printf("( q1 ,");
        break;
    default: printf("( q2 ,");
        break;
    }
    
    if( strcmp (transicion.simbolosAAgregarEnLaPila, "EP") == 0 )
        printf(" ε )");
    else
        printf(" %s )",transicion.simbolosAAgregarEnLaPila);
}

int main()
{
    char caracterContinuar;
    
    do{
    int i=0, j=0, c;
    char* cadenaSinEspacios = (char*) malloc(N), estadoActual[2];
    char caracterLeido;
    Nodo* p = NULL;
    TRANSICION transicion;

    inicializarPila(&p);
    
    printf("\nIngrese una expresion aritmetica de suma, resta, producto o cociente: ");

    i=0;
    while((c = getc(stdin)) != '\n'){
        if(c != 32){                    //32 es espacio en blanco en ascii
        cadenaSinEspacios[i] = c;
        i++;   
        }
    }

    cadenaSinEspacios[i] = '\0';
    //INICIALIZO TRANSICION
    //estadoActual[0] = EStado
    //estadoActual[1] = Cima de Pila
    caracterLeido = cadenaSinEspacios[0];
    estadoActual[0] = q0;
    estadoActual[1] = cimaDePila(p);
    strcpy (transicion.simbolosAAgregarEnLaPila, "q3");
    transicion.siguienteEstado = q3 ;
    
    j=0;
    while(j<strlen(cadenaSinEspacios)){
        transicion = evaluar (caracterLeido, estadoActual);
        printf ("\nTRANSICION\n");
        imprimirTransicion (transicion, caracterLeido, estadoActual);
        pop(&p);
        if(strcmp(transicion.simbolosAAgregarEnLaPila, "EP") != 0)
        {
            if(strlen(transicion.simbolosAAgregarEnLaPila)==1)
                push( &p, transicion.simbolosAAgregarEnLaPila[0]);
            else{
                push( &p, transicion.simbolosAAgregarEnLaPila[1]);
                push( &p, transicion.simbolosAAgregarEnLaPila[0]);
            }
        }

        printf("\tPILA:\n");
        mostrarPila(p);

        j++;

        estadoActual[0] = transicion.siguienteEstado;
        estadoActual[1] = cimaDePila(p);
        caracterLeido = cadenaSinEspacios[j];
        
    }

    if(pilaVacia(p))
        printf("\nCadena Aceptada: %s", cadenaSinEspacios);
    else
        printf("\nError - Expresion NO Reconocida\n");

    free(cadenaSinEspacios);    

    printf("\n¿Desea continuar? \n\nPulse F para finalizar, otra para continuar.");
    caracterContinuar = getchar();
    fflush(stdin);

    }while(caracterContinuar != 'f' && caracterContinuar != 'F');

    return 0;
}