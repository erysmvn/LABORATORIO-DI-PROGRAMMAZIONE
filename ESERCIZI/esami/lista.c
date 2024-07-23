#include <stdio.h>
#include <stdlib.h> // per le liste

struct Nodo * aggiungiNodo(int dato);
void stampaLista(); // non passo la testa alla funzione perchè è dichiarata fuori dal main

struct Nodo { // definisco la struttura
    int dato;
    struct Nodo * next; // chiamata ricorsiva
};

// (struct Nodo = nome del tipo)
struct Nodo * testa = NULL; // creo un puntatore ad un nodo (testa)

int main(){
    for (int i = 0; i < 5; i++)
        aggiungiNodo(i);

    stampaLista();

    return 0;
}

void stampaLista(){
    struct Nodo * current = testa; // cerchiamo sempre di non effettuare operazioni sulla testa

    while (current != NULL){ // finche esiste nodo
        printf("| %d | -> ", current->dato); // stampo il dato nel nodo
        current = current->next; // aggiorno il nodo corrente con quello successivo
    }
    printf("NULL\n");
}

struct Nodo * aggiungiNodo(int dato){
    struct Nodo * new = NULL; // creo un nuovo nodo

    new = (struct Nodo *)malloc(sizeof(struct Nodo)); // alloco il nodo

    if (new == NULL)
        return NULL; // allocamento non riuscito
    
    new->dato = dato; // nuovo nodo -> dato = dato in input 
    if (testa == NULL){
        testa = new; //primo nodo creato
        new->next = NULL;
    } else {
        new->next = testa; // testa già esistente
        testa = new;
    }
    return new;
}