#include <stdlib.h>
#define MAX 100

typedef struct{
    int primeiro,ultimo,itens[MAX];
}fila;


int estaVazia(fila *f);
int retira(fila *f);
int insere(int e, fila *f);
int inicia(fila *f);
int comprimento(fila *f);
void imprime(fila *f);
void ordenar(fila *f);
