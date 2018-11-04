#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

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

/*void ordenar(fila *f){
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
}*/

int trocaPosicao(fila *f,int valorA,int valorB){
	fila temp,recovery;
	int aux,contA=-1,contB=-1,i=0,j=0,valA=0,valB=0;
	inicia(&temp);
	inicia(&recovery);
	while(!estaVazia(f)){
		aux = retira(f);
		if(aux == valorA){
			valA=aux;
			contA=i;
		}else if(aux == valorB){
			valB=aux;
			contB=i;
		}else{
			insere(aux,&temp);
		}
		insere(aux,&recovery);
		i++;
	}
	if(contA==-1 || contB==-1){
		while(!estaVazia(&recovery)){
			insere(retira(&recovery),f);
		}
		printf("Algum dos valores eh inexistente");
		return 0;
	}else if(contA == contB){
		while(!estaVazia(&recovery)){
			insere(retira(&recovery),f);
		}
		printf("Os valores informados correspondem ao mesmo valor");
		return 0;
	}
	
	while(j<i){
		if(contA==j){
			insere(valB,f);
		}else if(contB == j){
			insere(valA,f);
		}else{
			insere(retira(&temp),f);
		}
		j++;		
	}
	printf("valor A: %d\nValor B: %d\nI: %d", valA,valB,i);
	return 1;
}

int qtdPares(fila *f){
	fila temp;
	int qtdPares=0,aux=0;
	inicia(&temp);
	while(!estaVazia(f)){
		aux = retira(f);
		if(aux%2==0){
			qtdPares++;
		}
		insere(aux,&temp);
	}
	
	while(!estaVazia(&temp)){
		insere(retira(&temp),f);
	}
	return qtdPares;
}

fila filtraPares(fila *f){
	fila temp,pares;
	int qtdPares=0,aux=0;
	inicia(&temp);
	inicia(&pares);
	while(!estaVazia(f)){
		aux = retira(f);
		if(aux%2==0){
			qtdPares++;
			insere(aux,&pares);
		}
		insere(aux,&temp);
	}
	
	while(!estaVazia(&temp)){
		insere(retira(&temp),f);
	}
	return pares;
}

float mediaFila(fila *f){
	fila temp;
	int aux=0,soma=0,contador=0;
	float media=0;
	inicia(&temp);
	while(!estaVazia(f)){
		aux = retira(f);
		soma+=aux;
		insere(aux,&temp);
		contador++;
	}
	
	while(!estaVazia(&temp)){
		insere(retira(&temp),f);
	}
	media=soma/contador;
	return media;
}

int main(){
    fila f,pares;
    inicia(&pares);
	inicia(&f);
	insere(1,&f);
	insere(2,&f);
	insere(3,&f);
	insere(4,&f);
	insere(5,&f);
	insere(6,&f);
	insere(7,&f);
	insere(8,&f);
	insere(9,&f);
	insere(10,&f);
	insere(11,&f);
	insere(12,&f);
	imprime(&f);
	pares=filtraPares(&f);
	imprime(&pares);
	printf("\nQuantidade de numeros pares: %d",qtdPares(&f));
	printf("\nMedia de f: %2.f\nMedia de pares: %2.f\n\n\n",mediaFila(&f),mediaFila(&pares));
    return 0;
}
