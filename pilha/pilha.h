#include <stdlib.h>
#define MAX 100

typedef struct{
	int itens[MAX],topo;
}pilha;

int estaVazia(pilha *f);
int pop(pilha *f);
int push(int val,pilha *f);
void inicia(pilha *f);
void visualizar(pilha *f);
void retira_impares(pilha *f);
void concat_pilhas(pilha *f,pilha *p);
void ordenar(pilha *p);
int tamanho_iguais (pilha *p1, pilha *p2);
int compara_pilhas (pilha *p1, pilha *p2);
int ehprimo(int num);
void imprimenumerosprimos (int n);
void sys_empilha(pilha *p,pilha *p1);
