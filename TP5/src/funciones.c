#include "funciones.h"

void insertarTS(struct tabla_simbolos **start, struct tabla_simbolos *nuevo)
{
    struct tabla_simbolos *anterior = NULL;
    struct tabla_simbolos *aux = *start;

    while (aux != NULL)
    {
        anterior = aux;
        aux = aux->sgte;
    }

    nuevo->sgte = aux;

    if (aux != *start)
        anterior->sgte = nuevo;
    else
        *start = nuevo;
}

void insertarListaParametros(struct tabla_simbolos **final, struct lista_parametros *nuevo)
{
    struct lista_parametros *anterior = NULL;
    struct lista_parametros *aux = (*final)->inicio_lp;

    while (aux != NULL)
    {
        anterior = aux;
        aux = aux->sgte;
    }

    nuevo->sgte = aux;

    if (aux != (*final)->inicio_lp)
        anterior->sgte = nuevo;
    else
        (*final)->inicio_lp = nuevo;
}

int esSumable(char *tipo)
{
    if ((strcmp("char", tipo) == 0) || strcmp("int", tipo) == 0 || strcmp("float", tipo) == 0)
        return 1;
    else
        return 0;
}

int validarOperacionBinaria(struct tabla_simbolos **tabla, char *tipo1, char *tipo2)
{
    if (esSumable(tipo1) && esSumable(tipo2))
    {
        if (strcmp(tipo1, tipo2) != 0)
            return 0;
        else
            return 1;
    }
    else
    {
        return 2;
    }
    return 0;
}

int validarDeclaracion(tabla_simbolos **inicio, char *ID)
{
    tabla_simbolos *aux = *inicio;
    int encontro = 0;

    while (aux != NULL && !encontro)
    {
        if (strcmp(ID, aux->identificador) == 0)
        {
            encontro = 1;
            return encontro;
        }
        if (aux->var_o_func == 'F')
        {
            lista_parametros *aux2 = aux->inicio_lp;
            while (aux2 != NULL && !encontro)
            {
                if (strcmp(ID, aux2->nombre_param) == 0)
                {
                    encontro = 1;
                    return encontro;
                }
                else
                    aux2 = aux2->sgte;
            }
        }
        aux = aux->sgte;
    }

    return encontro;
}

char *devolverTipo(tabla_simbolos **inicio, char *ID)
{
    tabla_simbolos *aux = *inicio;
    int encontro = 0;

    while (aux != NULL && !encontro)
    {
        if (strcmp(ID, aux->identificador) == 0)
        {
            encontro = 1;
            return aux->tipo;
        }
        if (aux->var_o_func == 'F')
        {
            lista_parametros *aux2 = aux->inicio_lp;
            while (aux2 != NULL && !encontro)
            {
                if (strcmp(ID, aux2->nombre_param) == 0)
                {
                    encontro = 1;
                    return aux2->tipo_param;
                }
                else
                    aux2 = aux2->sgte;
            }
        }
        aux = aux->sgte;
    }
    return aux->tipo;
}

int esFuncion(tabla_simbolos **inicio, char *ID)
{
    tabla_simbolos *aux = *inicio;
    int encontro = 0;

    while (aux != NULL && !encontro)
    {
        if (strcmp(ID, aux->identificador) == 0)
        {
            encontro = 1;
            if (aux->var_o_func == 'F')
                return 1;
            else
                return 0;
        }
        aux = aux->sgte;
    }
    return 0;
}

void insertarEnLista_ts(struct tabla_simbolos **start, void *data)
{
    struct tabla_simbolos *nuevo = (struct tabla_simbolos *)malloc(sizeof(struct tabla_simbolos));
    insertarTS(start, nuevo);
}

void insertarTipo_ts(tabla_simbolos **inicio, char *tipo, char *ID, int dimension)
{
    tabla_simbolos *nuevo = (tabla_simbolos *)malloc(sizeof(tabla_simbolos));
    nuevo->tipo = strdup(tipo);
    nuevo->identificador = strdup(ID);
    nuevo->dim_puntero = dimension;
    nuevo->definido = 0;
    nuevo->usado = 0;
    nuevo->var_o_func = 'V';
    nuevo->inicio_lp = NULL;
    nuevo->sgte = NULL;
    insertarTS(inicio, nuevo);
    //printf("\nID: %s ; TIPO: %s", ID, tipo);
    //free(ID);
    free(tipo);
}

void insertarVoF_ts(tabla_simbolos **inicio, int VoF)
{
    tabla_simbolos *aux;
    aux = *inicio;

    while (aux->sgte)
    {
        aux = aux->sgte;
    }
    aux->var_o_func = VoF;
}

void insertarListaParametros_ts(tabla_simbolos *inicio, char *tipo, char *ID, int dimension)
{
    lista_parametros *nuevo = (lista_parametros *)malloc(sizeof(lista_parametros));
    nuevo->tipo_param = strdup(tipo);
    nuevo->nombre_param = strdup(ID);
    nuevo->dim_puntero = dimension;
    nuevo->sgte = NULL;
    tabla_simbolos *aux;
    aux = inicio;

    while (aux->sgte)
    {
        aux = aux->sgte;
    }

    insertarListaParametros(&aux, nuevo);

    //free(ID);
    free(tipo);
}

void insertarIDHermano_ts(tabla_simbolos **inicio, char *ID, int dimension)
{
    tabla_simbolos *aux = *inicio;
    while (aux->sgte)
    {
        aux = aux->sgte;
    }
    tabla_simbolos *nuevo = (tabla_simbolos *)malloc(sizeof(tabla_simbolos));
    nuevo->tipo = strdup(aux->tipo);
    nuevo->identificador = strdup(ID);
    nuevo->dim_puntero = dimension;
    nuevo->var_o_func = 'V';
    nuevo->inicio_lp = NULL;
    nuevo->sgte = NULL;
    //printf("\nIdentificador %s agregado a Lista", ID);
    insertarTS(inicio, nuevo);
}

void mostrarTS(tabla_simbolos *inicio)
{
    tabla_simbolos *aux = inicio;
    lista_parametros *aux_lp;
    int contador = 0;

    printf("\n||------------------------- REPORTE -------------------------||\n");

    while (aux)
    {
        contador = 0;
        switch (aux->var_o_func)
        {
        case 'V':
            printf("\n<<----------------------------------------------------------->>\n");
            printf("\nVariable");
            break;
        case 'F':
            printf("\n<<----------------------------------------------------------->>\n");
            printf("\nFuncion");
            break;
        default:
            printf("\nNO SE LE ASIGNO VoF");
            break;
        }
        printf("\nTipo: %s\nIdentificador: %s\n", aux->tipo, aux->identificador);
        if (aux->dim_puntero != 0)
            printf("Puntero - Dimension: %d\n", aux->dim_puntero);
        if (aux->inicio_lp || aux->var_o_func == 'F')
        {
            aux_lp = aux->inicio_lp;
            if (aux_lp)
                printf("\nLista de Parametros:\n");
            while (aux_lp)
            {
                printf("\n\t%d- Tipo: %s\n", contador + 1, aux_lp->tipo_param);
                if (aux_lp->dim_puntero != 0)
                    printf("\tPuntero - Dimension: %d\n", aux_lp->dim_puntero);
                aux_lp = aux_lp->sgte;
                contador++;
            }
            printf("\nCantidad de Parametros: %d\n", contador);
        }

        aux = aux->sgte;
    }
}

void insertarDimensionTS(tabla_simbolos *inicio, int dimension)
{
    tabla_simbolos *aux = inicio;
    while (aux->sgte)
    {
        aux = aux->sgte;
    }
    aux->dim_puntero += dimension;
}

void mostrarErrores(lista_errores *inicio)
{
    lista_errores *aux = inicio;

    printf("\n||------------------------- Errores -------------------------||\n");

    while (aux)
    {
        switch (aux->tipo)
        {
        case 'L':
            printf("\nError Lexico");
            break;
        case 'S':
            printf("\nError Semantico");
            break;
        default:
            printf("");
            break;
        }
        if(aux->linea == -1){
            printf("\nError: %s%s\n", aux->error, aux->string);
            aux->tipo = 'S';
        }else if (aux->tipo != 'Z')
            printf("\nError: %s%s\nNumero de Linea: %d\n", aux->error, aux->string, aux->linea);
        else
            printf("\n%s\nNumero de Linea: %d\n", aux->error, aux->linea);
        aux = aux->sgte;
    }
    printf("\n||-----------------------------------------------------------||\n");
}

void insertarError(lista_errores **inicio, char *mensajeError, char *str, char tipo, int linea)
{
    lista_errores *nuevo = (lista_errores *)malloc(sizeof(lista_errores));
    nuevo->error = strdup(mensajeError);
    nuevo->tipo = tipo;
    nuevo->linea = linea;
    nuevo->string = strdup(str);
    nuevo->sgte = NULL;
    
    if(salvavidas){
        printf("\nINSERTE EL ERROR %s %d \n", nuevo->error,nuevo->linea);
    }

    struct lista_errores *anterior = NULL;
    struct lista_errores *aux = *inicio;

    while (aux != NULL)
    {
        anterior = aux;
        aux = aux->sgte;
    }

    nuevo->sgte = aux;

    if (aux != *inicio)
        anterior->sgte = nuevo;
    else
        *inicio = nuevo;
}

int definido(tabla_simbolos **inicio, char *ID)
{
    tabla_simbolos *aux = *inicio;
    int encontro = 0;

    while (aux != NULL && !encontro)
    {
        if (strcmp(ID, aux->identificador) == 0)
        {
            return aux->definido;
        }
        aux = aux->sgte;
    }
    return 0;
}

void definir(tabla_simbolos **inicio, char *ID)
{
    tabla_simbolos *aux = *inicio;
    int encontro = 0;

    while (aux != NULL && !encontro)
    {
        if (strcmp(ID, aux->identificador) == 0)
        {
            aux->definido = 1;
        }
        aux = aux->sgte;
    }
}

void invocar(tabla_simbolos **inicio, char *ID)
{
    tabla_simbolos *aux = *inicio;
    int encontro = 0;

    while (aux != NULL && !encontro)
    {
        if (strcmp(ID, aux->identificador) == 0)
        {
            aux->usado = 1;
            return;
        }
        aux = aux->sgte;
    }

    return;
}

void validarInvocaciones(tabla_simbolos **inicio)
{
    tabla_simbolos *aux = *inicio;
    while (aux != NULL)
    {
        if (aux->usado && aux->var_o_func == 'F')
        {
            if (aux->definido == 0)
            {
                insertarError(&listaErrores, "Funcion Invocada No Definida: ", aux->identificador, 'S', -1);
            }
        }
        aux = aux->sgte;
    }
    return;
}

bool validarDeclaracionNEW(tabla_simbolos **inicio, char *identificador, int nro_linea)
{
    tabla_simbolos *aux = *inicio;
    tabla_simbolos *encontrado;
    tabla_simbolos *declarado;
    lista_parametros *encontrado_param = NULL;
    int doble_decla = 0;
    int VoF_declarado = 0, VoF_repetido = 0;
    int correcto = 1;
    do
    {
        if (strcmp(aux->identificador, identificador) == 0)
        {
            doble_decla++;
            if (doble_decla == 1)
            {
                declarado = aux;
                VoF_declarado = aux->var_o_func;
            }
        }
        encontrado = aux;
        aux = aux->sgte;

    } while (aux && doble_decla < 2);
    if (doble_decla == 2 && VoF_declarado)
    {
        if (encontrado->var_o_func == 'V' || VoF_declarado != encontrado->var_o_func)
        {
            insertarError(&listaErrores, "Doble declaracion de: ", identificador, 'S', nro_linea);
            correcto = 0;
        }
        else
        {   // F y F
            if (!compararParametros(declarado, encontrado, nro_linea))
            {
                correcto = 0;
            }
        }
        eliminarNodo(inicio, encontrado);
    }

    free(identificador);
    return correcto;
}

void eliminarNodo(tabla_simbolos **inicio, tabla_simbolos *a_eliminar)
{
    tabla_simbolos *aux = *inicio;
    tabla_simbolos *anterior;

    while (aux != a_eliminar)
    {
        anterior = aux;
        aux = aux->sgte;
    }
    if (aux)
    {
        anterior->sgte = aux->sgte;
        if (aux->inicio_lp)
        {
            //HABRIA Q ELIMINAR PARAMETROS
        }
        free(aux->identificador);
        free(aux->tipo);
        free(aux);
    }
}

bool compararParametros(tabla_simbolos *declarado, tabla_simbolos *encontrado, int nro_linea)
{
    lista_parametros *param_declarado = declarado->inicio_lp;
    lista_parametros *param_encontrado = encontrado->inicio_lp;
    if (compararCantidadParametros(declarado, encontrado, nro_linea))
    {
        if (strcmp(declarado->tipo, encontrado->tipo) || declarado->dim_puntero!=encontrado->dim_puntero)
        {
            insertarError(&listaErrores, "Funcion ya declarada con distinto tipo: ", encontrado->identificador, 'S', nro_linea);
            return false;
        }
        while (param_declarado && param_encontrado)
        {
            if (strcmp(param_declarado->tipo_param, param_encontrado->tipo_param) || param_declarado->dim_puntero!=param_encontrado->dim_puntero)
            {
                insertarError(&listaErrores, "Funcion ya declarada con distintos tipos de parametros: ", encontrado->identificador, 'S', nro_linea);
                return false;
            }
            param_encontrado = param_encontrado->sgte;
            param_declarado = param_declarado->sgte;
        }
    }
    else{
        return false;
    }
    return true;
}

bool compararCantidadParametros(tabla_simbolos *declarado, tabla_simbolos *encontrado, int nro_linea)
{

    lista_parametros *aux_decla = declarado->inicio_lp;
    lista_parametros *aux_encontrado = encontrado->inicio_lp;

    int long_decla = 0, long_encontrado = 0;

    while (aux_decla)
    {
        aux_decla = aux_decla->sgte;
        long_decla++;
    }
    while (aux_encontrado)
    {
        aux_encontrado = aux_encontrado->sgte;
        long_encontrado++;
    }
    if (long_decla == long_encontrado)
    {
        return true;
    }
    if (long_encontrado > long_decla)
    {
        insertarError(&listaErrores, "Funcion ya declarada (con menos parametros): ", encontrado->identificador, 'S', nro_linea);
        return false;
    }
    else if (long_encontrado < long_decla)
    {
        insertarError(&listaErrores, "Funcion ya declarada (con mas parametros): ", encontrado->identificador, 'S', nro_linea);
        return false;
    }
}

int cantParams(tabla_simbolos **inicio, char *ID)
{
    tabla_simbolos *aux = *inicio;
    int encontro = 0;
    int contador = 0;

    while (aux != NULL && !encontro)
    {
        if (strcmp(ID, aux->identificador) == 0)
        {
            lista_parametros *aux2 = aux->inicio_lp;
            while (aux2 != NULL)
            {
                contador++;
                aux2 = aux2->sgte;
            }
            return contador;
        }
        aux = aux->sgte;
    }

    return contador;
}

int tipoCorrecto(char *funcion, int contador, char *tipo, tabla_simbolos **inicio)
{

    tabla_simbolos *aux = *inicio;
    int i = 1;
    while (aux != NULL)
    {
        if (strcmp(funcion, aux->identificador) == 0 && aux->var_o_func == 'F')
        {

            lista_parametros *aux2 = aux->inicio_lp;

            //printf("\nA comparar %s",aux2->tipo_param);

            while (i < contador && aux2 != NULL)
            {
                aux2 = aux2->sgte;
                i++;
                //printf("\nA comparar %s",aux2->tipo_param);
            }
            if (aux2 != NULL)
            {
                return (strcmp(aux2->tipo_param, tipo) == 0);
            }
            else
            {
                return 1;
            }
        }

        aux = aux->sgte;
    }

    return 3;
}

void declararParametros(tabla_simbolos **inicio)
{
    tabla_simbolos *aux = *inicio;

    while (aux->sgte)
    {
        aux = aux->sgte;
    }
    if (aux->inicio_lp)
    {
        lista_parametros *aux_lp = aux->inicio_lp;
        while (aux_lp)
        {
            insertarTipo_ts(inicio, aux_lp->tipo_param, aux_lp->nombre_param, 0); //VER TEMA DIMENSION
            aux_lp = aux_lp->sgte;
        }
    }
}

char *intToString(int num)
{
    char *str = malloc(sizeof(char) * 10);
    sprintf(str, "%d", num);
    return str;
}

char *stringConcatenate(char *str1, char *str2)
{
    char *str = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    strcpy(str, str1);
    strcat(str, str2);
    return str;
}