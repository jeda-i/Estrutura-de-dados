#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
//Checa se a pilha que foi passada como argumento esta vazia.
int estaVazia(pilha *f){
    if(f->topo == -1){
        return 1;
    }else{
        return 0;
    }
}
//Inicia a pilha com o valor -1.
void inicia(pilha *f){
    f->topo=-1;
}
//Retira o topo da pilha.
int pop(pilha *f){
    if(estaVazia(f)){
        printf("Erro: Empty stack.");
        exit(1);
    }
    return f->itens[f->topo--];
}
//Insere o valor no topo da pilha.
int push(int val, pilha *f){
    if(f->topo == MAX-1){
        printf("Erro: Stack Overflow.");
    }
    f->itens[++f->topo]=val;
    return 1;
}
//Mostra todos os valores da pilha.
//Função para imprimir os valores empilhados.
void visualizar(pilha *f){
    int valor;
    pilha temp;
    inicia(&temp);
    printf("\nVisualizando pilha...\n");
    while(!estaVazia(f)){
        valor=pop(f);
        printf("%d\n",valor);
        push(valor,&temp);
    }
    while(!estaVazia(&temp)){
        push(pop(&temp),f);
    }
}
/*
1°) Implementar uma função que receba uma pilha como parâmetro e retire todos os elementos ímpares dessa pilha. (Use uma pilha auxiliar).
Protótipo: retira_impares (tppilha *p).
*/
void retira_impares(pilha *f){
    int valor;
    pilha temp;
    inicia(&temp);
    while(!estaVazia(f)){
        valor=pop(f);
        push(valor,&temp);
    }
    while(!estaVazia(&temp)){
        valor = pop(&temp);
        if(valor%2==0){
            push(valor,f);
        }

    }
}

/*
2°) Implementar uma função que receba duas pilhas como parâmetro e retorna 1 caso sejam idênticas ou zero caso contrário.
Protótipo: int compara_pilhas (tppilha *p1, tppilha *p2).
*/
int compara_pilhas (pilha *p1, pilha *p2){
    int num1,num2,check=0,topo=p1->topo+1;
    pilha auxP1,auxP2;
    inicia(&auxP1);
    inicia(&auxP2);
    if(p1->topo==p2->topo){
        while(!estaVazia(p1)){
            num1=pop(p1);
            push(num1,&auxP1);
            num2=pop(p2);
            push(num2,&auxP2);
            if(num1==num2){
                check++;
            }
            if(check==topo){
                while(!estaVazia(&auxP1)){
                    push(pop(&auxP1),p1);
                }
                while(!estaVazia(&auxP2)){
                    push(pop(&auxP2),p2);
                }
                return 1;
            }
        }
    }else{
        return 0;
    }
    return 0;
}
/*
3°) Implementar uma função que receba duas pilhas como parâmetro e empilhe a segunda sobre a primeira. (Use uma pilha auxiliar, além das duas pilhas em questão).
Protótipo: concat_pilhas (tppilha *p1, tppilha *p2).
*/
void concat_pilhas(pilha *f,pilha *p){
	pilha  aux;
	inicia(&aux);
    while(!estaVazia(f)){
        push(pop(f),&aux);
    }
    while(!estaVazia(p)){
        push(pop(p),&aux);
    }
    while(!estaVazia(&aux)){
        push(pop(&aux),f);
    }
}

/*
4°) Construa uma função na pilha para comparar duas pilhas e informar se elas possuem tamanhos iguais ou não.
Protótipo: tamanho_iguais (tppilha *p1, tppilha *p2)
*/
int tamanho_iguais (pilha *p1, pilha *p2){
	if(p1->topo==p2->topo){
		return 1;
	}else{
		return 0;
	}

}
//Ordenar pilha. (BONUS)
/*
Diferença do metodo ordanar da pilha e da fila:
-A pilha começa a inserir no topo, mas quando lê, começa a ler do ultimo inserido.
    EX: 1,2,3,4,5
    Ao imprimir o valor será:
    5,4,3,2,1

-No caso da fila, a ordem que foi inserido sera respeitado pois na leitura se lê o primeiro inserido e não o ultimo.
*/
void ordenar(pilha *p){
    int valor,menor=-2147483647;
    pilha a,b;
    inicia(&a);
    inicia(&b);
    while(!estaVazia(p)){
        push(pop(p),&a);
    }
    while(!estaVazia(&a) || !estaVazia(&b)){
        while(!estaVazia(&a)){
            valor=pop(&a);
            if(valor>=menor){
                menor=valor;
            }
            push(valor,&b);
        }
        while(!estaVazia(&b)){
            valor=pop(&b);
            if(menor==valor){
                push(valor,p);
            }else{
                push(valor,&a);
            }
        }
        menor=-2147483647;
    }
}

/*
5°) Todo número natural é formado pela multiplicação de números primos, ou
seja, ele pode ser decomposto em fatores primos. Para realizar a decomposição
de um número, deveremos encontrar os números primos que dividem o número
a ser decomposto. Isto pode ser feito realizando sucessivas divisões até que o
número se torne igual a 1. Por fim, selecionaremos os divisores de todas as
divisões e escreveremos esses números multiplicados uns pelos outros (do maior
para o menor). Por exemplo, o primeiro número primo que divide 30 é o número
2. Portanto, o primeiro fator primo do número 30 é o número 2. O resultado da
divisão de 30 por 2 é 15. O próximo número primo que divide 15 é o número 3,
cujo resto da divisão é o número 5. O próximo número primo que divide 5 é o
número 5. Portanto, os fatores primos do número 30 são 5, 3 e 2. Em outras
palavras, ao multiplicar 5*3*2 obtém-se o número 30. Escreva uma função na TAD
(pilha.c) com o seguinte protótipo: void imprimenumerosprimos (int n); Esse
método deve imprimir a multiplicação dos fatores primos deste número (n) do
maior para o menor. Por exemplo, ao receber o número 10, o método deve
imprimir 5*2. Outro exemplo, ao receber o número 3960, deverá ser impresso 11
* 5 * 3 * 3 * 2 * 2 * 2. Para a correta implementação desse método, Utilize uma
pilha para armazenar os fatores primos; assuma que a TAD Pilha está
implementada e segue o protótipo descrito na próxima página.
*/
int ehPrimo(int num){
	int i,contador=0;
	for(i=2;i<=num;i++){
		if(num%i==0){
			contador++;
		}
	}
	if(contador==1){
		return 1;
	}else{
		return 0;
	}
}

void imprimenumerosprimos (int n){
	pilha p;
	int aux=n,i;
	for(i=2;i<=n;i++){
		if(ehPrimo(i)==1){
			push(i,&p);
		}
	}

}

/*
6°) Crie um programa em C que utilize a TAD construída para solucionar um
problema com pilha. Um exemplo de problema que pode ser resolvido com pilha
é um sistema de controle de pilhas de caixas de embalagens de produtos.


Sistema para empilhar e desempilhar caixas
*/

void sys_empilha(pilha *p,pilha *p1){
	system("cls");
	int menu,*aux,pilha=0;
	printf("Bem vindo:\nSistema para empilhar/desempilhar caixas\nPilha 1 possui: %d caixas empilhadas\nPilha 2 possui: %d\n\nEscolha a pilha: 1 ou 2\n",p->topo+1,p1->topo+1);
	scanf("%d",&pilha);
	if(pilha !=1 && pilha != 2){
		printf("Por favor informe uma das duas pilhas, tente novamente...");
		system("pause");
		sys_empilha(p,p1);
	}else if(pilha==1){
		aux=p;
	}else if(pilha==2){
		aux=p1;
	}
	printf("\n\nAcao:\n(1)-Empilhar\n(2)-Desempilhar\n(3)-Sair\n");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			push(0,aux);
			sys_empilha(p,p1);
			break;
		case 2:
			pop(aux);
			sys_empilha(p,p1);
			break;
		case 3:
			exit(1);
			break;
		default:
			printf("Valor invalido tente novamente: \n");
			system("pause");
			sys_empilha(p,p1);
			break;
	}
}
int main(){
    int i;
    pilha p,p1;
    inicia(&p);
    inicia(&p1);
    push(1,&p);
    push(2,&p);
    push(3,&p);
    push(4,&p);
    push(5,&p);
    /*push(1,&p1);
    push(2,&p1);
    push(3,&p1);
    push(4,&p1);
    push(5,&p1);
    visualizar(&p);
    visualizar(&p1);
    printf("\nResultado:%d",compara_pilhas(&p,&p1));
    concat_pilhas(&p,&p1);
    visualizar(&p);*/
    /*retira_impares(&p);
    printf("\nRemovendo os impares...");
    visualizar(&p);
    ordenar(&p);
    printf("\nOrdenando pilha...");
    visualizar(&p);*/
    sys_empilha(&p,&p1);
    return 0;
}

