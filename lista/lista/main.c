#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int estaVazia(fila *f){
    if(f->ultimo == f->primeiro){
        return 1;
    }else{
        return 0;
    }
}

int inicia(fila *f){
    f->ultimo =MAX-1;
    f->primeiro=-1;
    return 1;
}

int retira(fila *f){
    if(estaVazia(f)){
       printf("Error: Empty Queue.");
       exit(1);
    }

    if(f->primeiro == MAX-1){
        f->primeiro=0;
    }else{
        f->primeiro++;
    }
    return f->itens[f->primeiro];
}

int insere(int e, fila *f){
    if(f->ultimo+1==f->primeiro){
        printf("Error: Queue Overflow.");
        exit(1);
    }

    if(f->ultimo == MAX-1){
        f->ultimo=0;
    }else{
        f->ultimo++;
    }
    f->itens[f->ultimo]=e;
    return 1;
}

void imprime(fila *f){
    fila tmp;
    inicia(&tmp);
    int valor;
    printf("\nVisualizando fila...\n");
    while(!estaVazia(f)){
        valor=retira(f);
        printf("%d\n",valor);
        insere(valor,&tmp);
    }
    while(!estaVazia(&tmp)){
        insere(retira(&tmp),f);
    }
}

void ordenar(fila *f){
    fila a,b;
    int valor,menor=2147483647;
    inicia(&a);
    inicia(&b);
    while(!estaVazia(f)){
        insere(retira(f),&a);
    }
    while(!estaVazia(&a) || !estaVazia(&b)){
        while(!estaVazia(&a)){
            valor=retira(&a);
            if(valor<=menor){
                menor=valor;
            }
            insere(valor,&b);
        }
        while(!estaVazia(&b)){
            valor=retira(&b);
            if(valor==menor){
                insere(valor,f);
            }else{
                insere(valor,&a);
            }
        }
        menor=2147483647;
    }
}
int main(){
    fila f;
    inicia(&f);
    insere(100,&f);
    insere(1823,&f);
    insere(9,&f);
    insere(531,&f);
    insere(55,&f);
    imprime(&f);
    ordenar(&f);
    imprime(&f);
    return 0;
}
