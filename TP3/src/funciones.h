#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

enum tipoToken {identificadores = 1, literalesCadena = 2, palabraReservada = 3, operadores = 4, constanteOctal = 5, constanteHexadecimal = 6, 
constanteDecimal = 7, constanteReales = 8, constanteCaracter = 9, comentarios = 10, comentariosMultilinea = 11, noReconocidos = 12};
typedef struct Nodo
{
    char *info;
    enum tipoToken token; //CAMBIO
    int numeroLinea;
    struct Nodo *siguiente;
} Nodo;

struct Nodo *listaElementos=NULL;

// Transformacion de constantes

int baseToDecimal(char *string, int n)
{
    int valor;
    valor = strtol(string, NULL, n);
    return valor;
}

void indicarEnteroYMantisa(char *valor)
{
    double value;
    char *aux;
    value = strtod(valor, &aux);
    double mantisa, parteEntera;
    mantisa = modf(value, &parteEntera);
    printf("Parte Entera: %g ; Mantisa: %g \n",parteEntera, mantisa);
}

void insertarNodo(struct Nodo **start, struct Nodo *nuevo){

    struct Nodo *anterior = NULL;
    struct Nodo *aux = *start;
    while (aux != NULL){
        anterior = aux;
        aux = aux -> siguiente;
    }
    
    nuevo -> siguiente = aux;
    
    if ( aux != *start ){
       anterior -> siguiente = nuevo;
    }else{
       *start = nuevo;
    }
}

void insertarEnLista(struct Nodo **start, char *data, int token, int numeroLinea)
{

    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo -> info = strdup(data);
    nuevo -> numeroLinea = numeroLinea;
    nuevo -> token = token;

    insertarNodo(start, nuevo);
    
}

void ciclo(struct Nodo *lista, int base)
{
    struct Nodo *aux;
    aux = lista;
    while (aux != NULL)
    {
        int n = baseToDecimal(aux->info, base);
        printf("\'%s\' ; Decimal: %d \n", aux->info, n);
        aux = aux->siguiente;
    }
}

int length(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
    }
    return i;
}

int cantidadEspacios(char *string)
{
    int i, cont = 0;
    for (i = 0; i < length(string); i++)
    {
        if (string[i] == '\n')
            cont++;
    }
    return cont;
}

bool criterioToken(struct Nodo *unNodo, struct Nodo *otroNodo){
    return unNodo->token > otroNodo->token;
}

bool criterioAlfabetico(struct Nodo *unNodo, struct Nodo *otroNodo){
    return strcmp(otroNodo->info, unNodo->info) < 0;
}

bool criterioLongitud(struct Nodo *unNodo, struct Nodo *otroNodo){
    return sizeof(unNodo->info) < sizeof(unNodo->info);
}

void ordenarNodos(struct Nodo **inicio, bool (*unCriterio)(struct Nodo *unNodo, struct Nodo *otroNodo)){

    struct Nodo *aux=NULL, *aux2=NULL, *anterior=NULL, *finalOrdenado=NULL;

    aux = *inicio;
    anterior = aux;

        int cambio=0;
        do
        {
            cambio=0;
            aux = *inicio;
            anterior = *inicio;

            while (aux && aux->siguiente)
            {
            if(unCriterio(aux, aux->siguiente)){
                if(aux==anterior)
                {
                    aux2=aux->siguiente->siguiente;
                    *inicio=aux->siguiente;
                    (*inicio)->siguiente=aux;
                    aux->siguiente=aux2;
                }
                else
                {
                    aux2=aux->siguiente->siguiente;
                    anterior->siguiente=aux->siguiente;
                    aux->siguiente->siguiente=aux;
                    aux->siguiente=aux2;
                }
                cambio++;
            }
            anterior=aux;
            aux=aux->siguiente;
            }

        } while (cambio);

}

void liberarLista(struct Nodo *lista){
    struct Nodo *anterior=NULL;

    if(lista){
        while(lista){
            anterior = lista;
            lista = lista -> siguiente;
            free(anterior);
        }
    }
}

void mostrarTodo(struct Nodo *lista){
    struct Nodo *aux=NULL;
    aux=lista;
    
    while (aux)
    {
        printf("Token: %s \n Tipo token: %d \n Numero linea: %d \n\n", aux->info, aux->token, aux->numeroLinea);
        aux=aux->siguiente;
    }
    
}

Nodo* filtrarLista(struct Nodo *lista, int token){

    struct Nodo *nuevaLista = NULL, *aux = NULL;
    aux = lista;

    while (aux)
    {
        if(aux->token == token){
            insertarEnLista(&nuevaLista, aux->info, aux->token, aux->numeroLinea);
        }
        aux = aux->siguiente;
    }
    
    return nuevaLista;

}

void mostrarNormal(struct Nodo *lista){
    
    while (lista)
            {
                printf("%s \n", lista->info);
                lista=lista->siguiente;
            }
}

void mostrarEnumeradas(struct Nodo *lista){
    
    int cont = 1;

    while (lista)
            {
                printf("%d-%s \n", cont, lista->info);
                cont++;
                lista=lista->siguiente;
            }
}

void mostrarConCantidad(struct Nodo *lista){
    while (lista)
            {
                int contador=0;
                char *mostrado;
                printf("%s \n", lista->info);
                mostrado = strdup(lista->info);
                do
                {
                    lista=lista->siguiente;
                    contador++;
                } while (lista && strcmp(lista->info, mostrado)==0);
                printf("Cantidad de veces que aparece: %d \n\n", contador);
            }

}

void mostrarConFuncion(struct Nodo *lista, void(*unaFuncion)(struct Nodo *elementoLista)){
    while (lista)
            {
                printf("%s\n", lista->info);
                unaFuncion(lista);
                lista=lista->siguiente;
            }
}

void mostrarConLongitud(struct Nodo *lista){
        printf("Longitud: %d \n", length(lista->info)-1);      
}


void mostrarEnteroYMantisa(struct Nodo *lista){
                indicarEnteroYMantisa(lista->info);
}

void mostrarConValorDecimal(struct Nodo *lista){
    if(lista->token==constanteHexadecimal)
        printf("Valor decimal: %d\n", baseToDecimal(lista->info, 16));
    else if(lista->token==constanteOctal)
        printf("Valor decimal: %d\n", baseToDecimal(lista->info, 8));

}

void mostrarConNroLinea(struct Nodo *lista){
    printf("En la linea: %d \n", lista->numeroLinea);           
}

int sumaTotal(struct Nodo *lista){

    int acumulador=0;
    while (lista)
    {
        acumulador+=atoi(lista->info);
        lista=lista->siguiente;
    }

    return acumulador;
    
}

void mostrarLista(struct Nodo *lista){

    struct Nodo *aux = NULL, *trabajarCon = NULL;
    int i;
    int base;
    for(i = identificadores; i <= noReconocidos; i++){
        aux = NULL;
        trabajarCon = filtrarLista(lista, i);
        aux = trabajarCon;
        //mostrarTodo(aux);
        switch (i)
        {
        case identificadores:
            
            printf("\n- [ Identificadores ] -\n\n");

            ordenarNodos(&aux, &criterioAlfabetico);
            mostrarConCantidad(aux);

            break;
        case literalesCadena:

            printf("\n- [ Literales Cadena ] -\n\n");

            ordenarNodos(&aux, &criterioLongitud);
            mostrarConFuncion(aux, &mostrarConLongitud);

            break;
        case palabraReservada:
            printf("\n- [ Palabras reservadas ] -\n\n");
            mostrarNormal(aux);
            break;
        case operadores:
            printf("\n- [ Operadores y Caracteres de Puntuacion ] -\n\n");
            ordenarNodos(&aux, &criterioAlfabetico);
            mostrarConCantidad(aux);
            break;
        case constanteOctal:
        case constanteHexadecimal:
        if(i==constanteHexadecimal){
            printf("\n- [ Constantes Hexadecimal ] -\n\n");
        }
        else if(i==constanteOctal){
            printf("\n- [ Constantes Octal] -\n\n");
        }
            mostrarConFuncion(aux, &mostrarConValorDecimal);
            break;
        case constanteDecimal:
            printf("\n- [ Constantes Decimal ] -\n\n");
            mostrarNormal(aux);
            printf("\nSUMA TOTAL: %d\n", sumaTotal(aux));
            break;
        case constanteReales:
            printf("\n- [ Constantes Reales ] -\n\n");
            mostrarConFuncion(aux, &mostrarEnteroYMantisa);
            break;
        case constanteCaracter:
            printf("\n- [ Constantes Caracter ] -\n\n");
            mostrarEnumeradas(aux);
            break;
        case comentarios:
            printf("\n- [ Comentarios Simple ] -\n\n");
            mostrarNormal(aux);
            break;
        case comentariosMultilinea:
            printf("\n- [ Comentarios Multilinea ] -\n\n");
            mostrarNormal(aux);
            break;
        case noReconocidos:
            printf("\n- [ NO Reconocidos ] -\n\n");
            mostrarConFuncion(aux, &mostrarConNroLinea);
            break;
        default:
            break;
        }

        liberarLista(trabajarCon);
        trabajarCon=NULL;
    }
  
}