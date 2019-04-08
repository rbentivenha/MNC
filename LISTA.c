#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int informacao;
    struct lista *proximo;
}node;

node *inicializa(){
    return NULL;
}

int lista_vazia(node *l){
	if(l==NULL)
		return 1;
	else
		return 0;
}

void percorre(node *l){
    node *auxiliar;
    auxiliar = l;

    while (auxiliar != NULL){
    printf("dado gravado: %d", auxiliar -> informacao);
    auxiliar = auxiliar -> proximo;
    }
}

node *insere_inicio(node *l, int num){
    node *auxiliar;
    auxiliar = l;

    int aux;
    aux = lista_vazia(auxiliar);

    node *novo = (node*) malloc(sizeof(node));
    novo -> informacao = num;

    if (aux){
    novo -> proximo = NULL;
    }else{
    novo -> proximo = l;
    }
    return novo; //'novo' é o início da lista agora
}

node *excluir(node *l){
    node *auxiliar;
    auxiliar = l;

    int aux;
    aux = lista_vazia(auxiliar);

    if(aux){
        printf("\nVazia.\n");
		return l;
    }else{
        auxiliar = l; //auxiliar recebe o endereço do início da lista (nó q será excluído)
		node *cabeca; //auxiliar para armazenar o início da lista após exclusão
        cabeca = auxiliar->proximo; //o 'proximo' do 1º nó da lista deverá ser o endereço do início da lista após exclusão
		auxiliar->proximo = NULL; //o antigo início da lista deve passar a apontar para NULL antes excluir
		free(auxiliar); //libera endereço de memória no qual o primeiro nó estava armazenado
		printf("\nNó excluído!\n");

		return cabeca;
    }
}

void main (){
    node *l; //declara lista não inicializada

    l = inicializa();
    l = insere_inicio(l, 2);
    percorre(l);
    l= excluir(l);
    percorre(l);
}
