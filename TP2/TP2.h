void inicializarPila (Nodo** p){
    (*p) = (Nodo*) malloc(sizeof(Nodo));
    (*p) -> info = '$';
    (*p) -> sig = NULL;
}

void push(Nodo** p, char c){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo -> info = c;
    nuevo -> sig = (*p);
    (*p) = nuevo;
}

void pop (Nodo** p){ 
    if((*p)!=NULL){
        Nodo* aux = *p;
        (*p)=(*p)->sig;
        free(aux);
    }
}

char cimaDePila (Nodo* p){
    if ( p != NULL ){
        return p -> info;
    }
}

void mostrarPila(Nodo* p){
    int i;
    Nodo* aux = p;

    for( i = 0 ; aux != NULL ; i++ ){
        printf ( "\t\t\t\t\t|%c|\n" , aux -> info);
        aux = aux -> sig;
    }
        printf("\t\t\t\t\t---");
}

int pilaVacia (Nodo* p){
    return (*p).info == '$'? 1 : 0;
}