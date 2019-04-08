#include <locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista{
    char informacao;
    struct lista *proximo;
}pilha;

pilha *inicializa(){
    return NULL;
}

int vazia(pilha *p){
	if(p==NULL)
		return 1;
	else
		return 0;
}

pilha *push(pilha *l, char c){
    pilha *p; //ponteiro auxiliar
	p = l; //p recebe o endereço referente ao início da lista

	int aux;
	aux = vazia(p);

	//cada nó a ser inserido na lista é criado dinamicamente, conforme aprendido em alocação dinâmica
	pilha *novo;
	novo = (pilha*) malloc(sizeof(pilha));
	novo->informacao = c;

	//se a lista está vazia
	if(aux){
		//incluindo o primeiro nó da lista
		novo->proximo = NULL;
	}else{
		//se a lista não está vazia
		novo->proximo = l; //aponta para o "antigo primeiro nó"
	}

	//'novo' é o início da lista agora
	return novo;
}

pilha *pop(pilha *l){
	pilha *p; //ponteiro auxiliar
	p = l; //p recebe o endereço referente ao início da lista
	pilha *head; //nó auxiliar para armazenar o início da lista após exclusão
    //o conteúdo armazenado no ponteiro 'prox' do primeiro nó da lista deverá ser o endereço do início da lista após exclusão
    head = p->proximo;
    //o antigo início da lista deve passar a apontar para NULL antes de ser excluído
    p->proximo = NULL;
    free(p);//liberando endereço de memória no qual o primeiro nó estava armazenado
    return head;
}


void main(){
    setlocale(LC_ALL,"portuguese");

    char expressao[1001];
    int i;

    pilha *p = (pilha *) malloc(sizeof(pilha));
    inicializa(p);

    printf("\tPARENTESÊS\n");
    printf("Digite a expressão: \n");
    scanf("%s",&expressao);

        for(i=0; i<strlen(expressao); i++){
            if (expressao[i] == '('){
               p= push(&p, expressao[i]);
            }
            if(expressao[i] == ')'){
                    if(vazia(p)){
                        printf("incorrect\n");
                    }else{
                   p= pop(p);
                    }

            }
        }
        if (vazia(p)){
        printf("correct\n");
        }else{
        printf("incorrect\n");
        }

system("pause");
}





