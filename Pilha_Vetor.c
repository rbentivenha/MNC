#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

    int pilha [5];
    int topo = 0;
    int op;
    int pop;

void insere(int *vetor){
    if (topo > 4){
    printf("Pilha cheia\n");
    }else{
    printf("Digite o valor que quer incluir: ");
    scanf("%d", &pilha[topo]);
    topo++;
    }
}

int remover(){
    int aux;
    if (topo == 0){
    printf("Pilha vazia, não há o que excluir\n");
    }else{
    printf("Retirado o valor %d", pilha[topo-1]);
    topo--;
    return aux;
    }
}

void imprimir(int *vetor){
    int i;
    if (topo == 0){
    printf("Pilha vazia, não há o que imprimir\n");
    }else{
        for(i = 0; i < topo; i ++){
        printf("Pilha[%d]: %d\n", i+1, pilha[i]);
        }
    }
}

void main(){
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

        if(op!=4){
            if(op == 1){
				imprimir(pilha);
			}else if(op==2){
				insere(pilha);
				printf("\nInserido com sucesso!\n");
            }else if(op == 3){
                remover();
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


