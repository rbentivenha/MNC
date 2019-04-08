#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//nao ta removendo, mesmo já tendo inserido está dando pilha vazia
//funcao imprime fechando o programa

typedef struct lista{
    int informacao;
    struct lista *proximo;
}node;

int lista_vazia(node *l){
	if(l==NULL)
		return 1;
	else
		return 0;
}

node *inicializa(){
    return NULL;
}

void exibe(node *l){
    node *auxiliar;
    auxiliar = l;

    while (auxiliar != NULL){
    printf("Dado gravado: %d", auxiliar -> informacao);
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
        printf("\nPilha vazia, não há o que excluir.\n");
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


void main(){
    int op;
    setlocale(LC_ALL,"portuguese");
    do{
        printf("\tImplementação de ED: Pilha\n");
        printf("Menu:\n");
        printf("\t1 - Exibir pilha na tela;\n");
        printf("\t2 - Incluir dado na pilha;\n");
        printf("\t3 - Excluir dado da pilha;\n");
        printf("\t4 - Sair");

        do{
		printf("\n\nQual a opção escolhida?\n");
        scanf("%d",&op);
        }while((op<1) || (op>4));

        node *l;
        l = inicializa();

        if(op!=4){
            if(op == 1){
				exibe(l);
			}else if(op==2){
                int num;
                printf("Digite o número que deseja inserir: ");
                scanf("%d", &num);
				l = insere_inicio(l, num);
				printf("\nNúmero %d inserido com sucesso!\n", num);
            }else if(op == 3){
                l = excluir(l);
                printf("\nRemovido com sucesso!\n");
            }

            if(op==1){
				op = 4; //para sair do loop
				printf("\nPrograma encerrado.\n");
			}
			else{
				//limpa a tela antes de exibir o menu novamente
				system("pause");
				system("cls");
			}
		}else{
			printf("\nPrograma encerrado.\n");
		}

    }while(op!= 4);

}
