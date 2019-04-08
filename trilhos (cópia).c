#include <stdio.h>
#include <stdlib.h>

struct elementos{
    char valor;
    struct elementos *prox;
};
typedef struct elementos Node;

struct pilha{
    int contador;
    struct elementos *topo;
};
typedef struct pilha Pilha;

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    pi->contador = 0;
    pi->topo = NULL;
    return pi;
}

void insere_pilha(Pilha* pi, char valor){
    Node *no=(Node*)malloc(sizeof(Node));
    no->valor = valor;
    no->prox = pi->topo;
    pi->topo = no;
    pi->contador++;
}

void remove_pilha(Pilha* pi){
   Node *no;
   no = pi->topo;
   pi->topo = no->prox;
   free(no);
   pi->contador--;
}

int main()
{
    Pilha *pi1,*pi2;
    pi1 = cria_pilha();
    pi2 = cria_pilha();
    int i,m,w,n,x,k;
    char c,g[26];
    while(1){
        scanf("%d",&n);
        if(n==0){
            return 0;
        }
        for(i=0;i<n;i++){
            scanf(" %c",&g[i]);
        }
        m=0;
        w=0;
        x=0;
        k=0;
        while(m==0){
            scanf(" %c",&c);
            insere_pilha(pi1,c);
            if(x==1){
                m=1;
            }
            if(x==0){
                if(pi2->topo == NULL){
                    insere_pilha(pi2,g[w]);
                    w++;
                    printf("I");
                }
                while(pi1->topo->valor != pi2->topo->valor && k==0){
                    if(w < n){
                        insere_pilha(pi2,g[w]);
                        w++;
                        printf("I");
                    }else{
                        k=1;
                    }

                }
                if(pi1->topo->valor == pi2->topo->valor){
                    remove_pilha(pi2);
                    printf("R");
                }
                if(k==1){
                    printf(" Impossible\n");
                    x=1;
                }
                if(pi2->topo == NULL){
                    m=1;
                }

            }
        }
        if(pi2->contador == 0){
            printf("\n");
        }
    }

    return 0;
}
