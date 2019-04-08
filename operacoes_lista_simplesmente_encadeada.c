#include<stdio.h>
#include<stdlib.h>

//struct que representa um nó da lista
typedef struct Node_{
	int elem;
	struct Node_ *prox;
}Node;

//FUNÇÕES

//Uma lista é considerada vazia se o endereço do seu primeiro nó é NULL
Node *inicializa_lista(){
	return NULL;
}

//Função para verificar se a lista está vazia
int verifica_lista_vazia(Node *l){
	if(l==NULL)
		return 1;
	else
		return 0;
}

//Função para imprimir na tela o conteúdo da lista
void imprime_lista(Node *l){
	Node *p; //ponteiro auxiliar
	p = l; //p recebe o endereço referente ao início da lista
	
	int aux = 0;
	
	aux = verifica_lista_vazia(p);
	
	if(aux){
		printf("\nA lista está vazia.\n");
	}else{
		printf("\nA lista contém os seguintes nós:\n\n");
		
		p = l;
		
		//esse while percorre toda lista
		while(p!=NULL){
			printf("%d -> ",p->elem);
			p = p->prox;
		}
		printf(" NULL\n"); //para imprimir o conteúdo da lista na tela com o NULL no final
	}
}

//Função para buscar determinado nó na lista
//Retorna o endereço no nó procurado

Node *busca_determinado_no(Node *l, int valor){
	Node *p; //ponteiro auxiliar
	p = l; //p recebe o endereço referente ao início da lista
	
	int achou;
	
	achou = 0;
	
	Node *procurado;
	procurado = NULL; //se o nó não estiver na lista, será retornado NULL
	

	while((p!=NULL) && !achou){
		if(p->elem == valor){
			achou = 1;
			procurado = p; //se o nó estiver na lista, será retornado seu endereço
		}
		
		p = p->prox;
	}
	
	return procurado;
}

//Função para inserir um nó no início da lista
//Retorna o endereço do início da lista após inclusão

Node *insere_no_inicio_lista(Node *l, int valor){
	
	/*Sabemos que nenhum nó aponta para o primeiro nó da lista;
	
	Assim, se a lista estiver vazia, precisamos incluir o novo nó e fazer o seu ponteiro 'prox' apontar para NULL;
	Se a lista não estiver vazia, precisamos fazer o ponteiro 'prox' do novo nó apontar para o "antigo primeiro nó"*/
	
	Node *p; //ponteiro auxiliar
	p = l; //p recebe o endereço referente ao início da lista
	
	int aux;
	aux = verifica_lista_vazia(p);
	
	//cada nó a ser inserido na lista é criado dinamicamente, conforme aprendido em alocação dinâmica
	Node *novo;
	novo = (Node*) malloc(sizeof(Node));
	novo->elem = valor;
	
	//se a lista está vazia
	if(aux){
		//incluindo o primeiro nó da lista
		novo->prox = NULL;
	}else{
		//se a lista não está vazia
		novo->prox = l; //aponta para o "antigo primeiro nó"
	}
	
	//'novo' é o início da lista agora
	return novo;
}

//Função para inserir nó no fim da lista
//Retorna o endereço do início da lista

Node *insere_no_fim_lista(Node *l, int valor){
	Node *p; //ponteiro auxiliar
	p = l; //p recebe o endereço referente ao início da lista
	
	int aux;
	aux = verifica_lista_vazia(p);
	
	//se a lista está vazia
	if(aux){
		l = insere_no_inicio_lista(l,valor);
	}else{
		//cada nó a ser inserido na lista é criado dinamicamente, conforme aprendido em alocação dinâmica
		Node *novo;
		novo = (Node*) malloc(sizeof(Node));
		novo->elem = valor;
	
		Node *ultimo;//variável auxiliar para armazenar o endereço do último nó
		
		p = l;
		
		//percorre toda a lista para que o nó seja inserido no final
		while(p!=NULL){
			ultimo = p;
			p = p->prox;
		}
		
		//'ultimo' contém o endereço do último nó da lista
		//o último nó deve passar a apontar para o novo nó
		//e o novo nó deve apontar para NULL
		
		ultimo->prox = novo;
		novo->prox = NULL;
	}
	
	return l;
}

//Função para inserir um novo nó após um determinado nó
//O endereço do nó que antecede o novo nó a ser inserido é recebido por referência em 'determinado'

void insere_apos_determinado_no(Node *determinado, int valor){
	
	//cada nó a ser inserido na lista é criado dinamicamente, conforme aprendido em alocação dinâmica
	Node *novo;
	novo = (Node*) malloc(sizeof(Node));
	novo->elem = valor;
	
	Node *antigo_prox;
	
	//o 'determinado' nó deixará de apontar para o seu "atual próximo" e passará a apontar para o novo nó
	antigo_prox = determinado->prox;
	
	determinado->prox = novo;
	
	// o novo nó, por sua vez, passará a apontar para o "antigo próximo" do 'determinado' nó
	novo->prox = antigo_prox;
}

//Função para excluir o primeiro nó da lista
//Retorna o endereço do início da lista após exclusão

Node *excluir_no_inicio_lista(Node *l){
	Node *p; //ponteiro auxiliar
	p = l; //p recebe o endereço referente ao início da lista
	
	int aux;
	aux = verifica_lista_vazia(p);
	
	//se a lista está vazia
	if(aux){
		printf("\nA lista está vazia. Não há nó para ser excluído.\n");
		return l;
		
	}else{
		
		p = l; //p recebe o endereço referente ao início da lista (do nó que será excluído)
		
		Node *head; //nó auxiliar para armazenar o início da lista após exclusão
		
		//o conteúdo armazenado no ponteiro 'prox' do primeiro nó da lista deverá ser o endereço do início da lista após exclusão
		head = p->prox;
		
		//o antigo início da lista deve passar a apontar para NULL antes de ser excluído
		p->prox = NULL;
		
		free(p);//liberando endereço de memória no qual o primeiro nó estava armazenado
		
		printf("\nO nó foi excluído com sucesso!\n");
		
		return head;
	}
}

//Função para excluir o último nó da lista
//Retorna o endereço do início da lista após exclusão

Node *excluir_no_fim_lista(Node *l){
	Node *p; //ponteiro auxiliar
	p = l; //p recebe o endereço referente ao início da lista
	
	int aux;
	aux = verifica_lista_vazia(p);
	
	//se a lista está vazia
	if(aux){
		printf("\nA lista está vazia. Não há nó para ser excluído.\n");
		return l;
		
	}else{
		Node *anterior; //variável auxiliar para armazenar o endereço do nó anterior ao que será excluído
		
		anterior = NULL;
		
		//while para percorrer toda a lista
		//se existe apenas um nó na lista, não chega a entrar no while, uma vez que p->prox == NULL
		
		while(p->prox!=NULL){
			anterior = p;
			p = p->prox;
		}
		
		if(anterior == NULL){//Se anterior == NULL, então não entrou no while, ou seja, p->prox == NULL
			//se (p->prox == NULL) sem entrar no while, então existe apenas um nó na lista
			
			free(p);
			
			l = NULL; //ao excluir o único nó da lista, a lista passa a conter NULL
		}else{
			anterior->prox = NULL; //o nó anterior passa a apontar para NULL porque agora ele é o último nó da lista
		
			free(p); //libera o endereço que armazenava o antigo último nó
		}
	}
	printf("\nO nó foi excluído com sucesso!\n");
	
	return l;
}

//Função para excluir um determinado nó da lista
//Retorna o endereço do início da lista após exclusão

Node *excluir_determinado_no(Node *l){
	int aux;
	
	Node *p; //ponteiro auxiliar
	p = l; //p recebe o endereço referente ao início da lista
	
	aux = verifica_lista_vazia(p);
	
	//se a lista está vazia
	if(aux){
		printf("\nA lista está vazia. Não há nó para ser excluído.\n");
		return l;
		
	}else{
		int valor, achou;
	
		printf("\nQual o valor do nó que deverá ser excluído?\n");
		scanf("%d",&valor);
	
		p = l; //l contém o endereço do início da lista
		
		Node *anterior;
		anterior = NULL;
		
		achou = 0;
		
		//percorre a lista até o fim ou até encontrar o valor
		while((p!= NULL) && (!achou)){
			if(p->elem == valor)
				achou = 1;
			else{
				anterior = p;
				p = p->prox;
			}
		}
		
		if(anterior == NULL){ //anterior == NULL quando o elemento a ser excluído é o primeiro da lista
			Node *novo_inicio;
			
			novo_inicio = p->prox;
			
			p->prox = NULL;
			
			free(p); //libera o endereço em que o nó estava armazenado
			
			printf("\nO nó foi excluído com sucesso!\n");
			
			l = novo_inicio; //l recebe o endereço do nó que inicia a lista
		}else{
			if(!achou){
				printf("\nO valor %d não existe na lista.\n", valor);
			}else{
				anterior->prox = p->prox;
				
				p->prox = NULL;
				free(p);
				
				printf("\nO nó foi excluído com sucesso!\n");
			}
		}
	}
	return l;
}

void imprime_menu(){
	printf("\t\nLISTA SIMPLESMENTE ENCADEADA\n\n");
	printf("Menu:\n");
	printf("\t1 - Exibir lista na tela;\n");
	printf("\t2 - Buscar determinado nó na lista;\n");
	printf("\t3 - Incluir nó no início da lista;\n");
	printf("\t4 - Incluir nó no fim da lista;\n");
	printf("\t5 - Incluir nó após determinado nó;\n");
	printf("\t6 - Excluir nó no início da lista;\n");
	printf("\t7 - Excluir nó no fim da lista;\n");
	printf("\t8 - Excluir determinado nó;\n");
	printf("\t9 - Sair");
}


/********MAIN************/

void main(){
	/*O endereço de uma lista encadeada é o endereço do seu primeiro nó;
	
	Se l contém o endereço de uma lista, pode-se dizer, para simplificação, que l é uma lista
	
	Se l contém o endereço de um nó, então l->elem contém o conteúdo (campo de dados) do nó e l->prox o endereço do próximo
	nó na lista encadeada. Lembrando que, se l contém o endereço do último nó da lista, então l->prox == NULL.*/
	
	//l é um ponteiro para o tipo nó, ou seja, l conterá o endereço no qual um nó está armazenado
	//neste programa l armazenará o início da lista
	Node *l; 
	
	int op; //variável para armazenar a opção escolhida no menu a seguir
	int valor;
	
	//sempre inicializamos a lista antes de realizar qualquer operação nela (busca, inserção ou remoção)
	l = inicializa_lista();
	
	//o conteúdo do laço do-while é repetido enquanto o usuário não escolher a opção referente a "sair"
	do{	
		
		imprime_menu();
		
		do{
			printf("\n\nQual a opção escolhida?\n");
			scanf("%d",&op);
		}while((op<1) || (op>9));
		
		if(op!=9){//se o usuário não deseja sair do programa
			if(op == 1){
				//exibir lista na tela
				
				imprime_lista(l);
				
			}else if(op == 2){
				//buscar determinado nó na lista
				
				Node *p;
				p = l;
				
				int aux = 0;
	
				aux = verifica_lista_vazia(p);
	
				if(aux){
					printf("\nA lista está vazia.\n");
				}else{
					printf("Qual o valor (campo de dados) do nó que você deseja buscar?\n");
					scanf("%d",&valor);
					
					Node *n_aux;
					
					n_aux = busca_determinado_no(l, valor);
					
					if(n_aux != NULL)
						printf("\nO valor %d está armazenado na lista.\n",valor);
					else
						printf("\nO valor %d não está armazenado na lista.\n",valor);
				}	
			}else if(op==3){
				//incluir nó no início da lista
				
				printf("Qual o valor (campo de dados) do nó que você deseja inserir no início da lista?\n");
				scanf("%d",&valor);
				l = insere_no_inicio_lista(l, valor); //l recebe o endereço do nó do início da lista após inclusão
				printf("\nO nó foi inserido com sucesso!\n");
				
			}else if(op == 4){
				//incluir nó no fim da lista
				
				printf("Qual o valor (campo de dados) do nó que você deseja inserir no fim da lista?\n");
				scanf("%d",&valor);
				l = insere_no_fim_lista(l, valor); //l recebe o endereço do nó do início da lista após inclusão
				printf("\nO nó foi inserido com sucesso!\n");
				
			}else if(op == 5){
				Node *p;
				p = l;
				
				int aux = 0;
	
				aux = verifica_lista_vazia(p);
	
				if(aux){
					printf("\nA lista está vazia.\n");
				}else{
					//incluir nó após determinado nó
					
					printf("\nPor favor, informe qual o valor (campo de dados) do nó que antecederá o que você deseja inserir?\n");
					scanf("%d",&valor);
					
					Node *determinado;
					determinado = busca_determinado_no(l, valor); //recebe endereço do nó que antecederá o novo nó
					
					//se o nó procurado existe na lista
					if(determinado != NULL){
						
						printf("\nQual o valor do novo nó?\n");
						scanf("%d",&valor);
						
						//incluindo novo nó após o determinado nó
						insere_apos_determinado_no(determinado, valor);
						
						printf("\nO nó foi inserido com sucesso!\n");
						
					}else
						printf("\nO nó de valor %d não está armazenado na lista. Não será possível incluir um novo nó após ele.\n",valor);
				}
				
			}else if(op == 6){
				//excluir nó do início da lista
				l = excluir_no_inicio_lista(l); //l receberá o endereço do início da lista após exclusão
				
			}else if(op == 7){
				//excluir nó do fim da lista
				l = excluir_no_fim_lista(l); //l receberá o endereço do início da lista após exclusão
				
			}else if(op == 8){
				//excluir um nó em específico
				l = excluir_determinado_no(l); //l receberá o endereço do início da lista após exclusão
			}
			
			do{
				printf("\nDeseja encerrar o programa? (1 para sim e 0 para não)?\n");
				scanf("%d",&op);
			}while((op<0) || (op>1));
			
			if(op==1){
				op = 9; //para sair do loop
				printf("\nPrograma encerrado.\n");
			}
			else{
				//limpa a tela antes de exibir o menu novamente
				system("clear");
			}
		}else{
			printf("\nPrograma encerrado.\n");
		}
	}while(op != 9);	
}