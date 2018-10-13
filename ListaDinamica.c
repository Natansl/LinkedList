#include "ListaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void flvazia(tipoLista *lista){
    lista->prim = (apontador)malloc (sizeof(celula));
    lista->prim->prox = NULL;
    lista->ult = lista->prim;
}
int vazia (tipoLista lista){
    return (lista.prim == lista.ult);
}

void insereItem (tipoItem x, tipoLista *lista){
    lista->ult->prox = (apontador)malloc(sizeof(celula));
    lista->ult = lista->ult->prox;
    lista->ult->item = x;
    lista->ult->prox = NULL;
}

void removeItem (tipoItem *x, int chave, tipoLista *lista){
    if (vazia(*lista)){
        printf("Lista vazia.");
        return;
    }
    apontador aux = lista->prim;
    apontador aux2=NULL;
    while (aux != NULL){
        if (aux->item.chave == chave){
            *x = aux->item;
            aux2->prox = aux->prox;
            free(aux);
            return;
        }
        else{
            aux2 = aux;
            aux = aux->prox;
        }
    }
}

void imprimeLista (tipoLista lista){
    if (vazia(lista)){
        printf("Lista vazia.");
        return;
    }
    printf("\nImpressao iniciada: \n");
    apontador aux = lista.prim->prox;
    while (aux != NULL){
        printf("%d ", aux->item.chave);
        aux = aux->prox;
    }
    printf("\nImpressao finalizada.\n");
}

void primeiroParaUltimo (tipoLista *lista){
    apontador aux = lista->prim->prox;

    lista->prim->prox = lista->prim->prox->prox;
    lista->ult->prox = aux;
    aux->prox = NULL;
}

void inverteLista(tipoLista *lista){
    apontador aux = lista->prim;
    apontador aux2=lista->prim->prox;
    lista->ult = aux2;

    while(aux2 ->prox != NULL){
        apontador f = aux;
        aux = aux2;
        aux2 = aux2->prox;
        aux->prox = f;
    }
    aux2 -> prox = aux;
    lista->prim->prox = aux2;
    lista->ult->prox = NULL;
}
int ultRecursivo(apontador aux, tipoLista *lista){
    if (aux->prox == lista->ult){
        int i = lista->ult->item.chave;
        apontador p = lista->ult;
        lista->ult = aux;
        free(p);
        lista->ult->prox = NULL;
        return i;
    }
    return ultRecursivo(aux->prox, lista);
}
void somaExtremos(tipoLista *lista){
    apontador aux = lista->prim->prox;
    while (aux != NULL){
        aux->item.chave += ultRecursivo(aux, lista);
        aux = aux->prox;
    }

}
