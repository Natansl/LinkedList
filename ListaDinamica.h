#ifndef LISTADINAMICA_H_INCLUDED
#define LISTADINAMICA_H_INCLUDED

typedef struct {
    int chave;
} tipoItem;

typedef struct celula *apontador;
typedef struct celula {
  tipoItem item;
  apontador prox;
} celula;

typedef struct{
    apontador prim, ult;
}tipoLista;

void flvazia(tipoLista *lista);
int vazia (tipoLista lista);
void insereItem (tipoItem x, tipoLista *lista);
void removeItem (tipoItem *x, int chave, tipoLista *lista);
void imprimeLista (tipoLista lista);
void primeiroParaUltimo (tipoLista *lista);
void inverteLista (tipoLista *lista);
void somaExtremos (tipoLista *lista);


#endif // LISTADINAMICA_H_INCLUDED
