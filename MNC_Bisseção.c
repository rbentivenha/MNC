// Implementação do Método da Bissecção
// Giovanna Simioni
// Disciplina: Métodos Numéricos e Computacionais

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double epson, a, b, fa, fb, raiz, pontoMedio, fPontoMedio;
int k=0;

double funcao (double x){
    double y;
    //y = (3*(powf(x, 2)))-1;
    //y = (powf(x, 3) - (4 * powf(x, 2)) + x + 6);
    return y;
}

double bissecao(double a, double b, double epson){

    fa = funcao(a);
    fb = funcao(b);
    fPontoMedio = funcao(pontoMedio);

    while((fabs(b-a)> epson) && (fabs(funcao(pontoMedio))> epson)){ //erro de critério de parada

        pontoMedio = (a+b)/2;
        printf("Ponto médio = %lf\n", pontoMedio);
        fPontoMedio = funcao(pontoMedio);
        printf("f(ponto médio) = %lf\n\n", fPontoMedio);

        if ((funcao(a)*funcao(pontoMedio))<0){
            b = pontoMedio;
            printf("b = %lf\n", b);
            fb = fPontoMedio;
            printf("f(b) = %lf\n\n", fb);
        }else if ((funcao(a)*funcao(pontoMedio))>0){
            a = pontoMedio;
            printf("a = %lf\n", a);
            fa = fPontoMedio;
            printf("f(a) = %lf\n\n", fa);
            }
            k++;
}

    return pontoMedio;
}
void main(){
    setlocale(LC_ALL,"portuguese");

    printf("\tMNC: Método da Bisseção\n");
    printf("Digite a precisão: \n");
    scanf("%lf", &epson);
    printf("Entre com o primeiro número do intervalo: \n");
    scanf("%lf", &a);
    printf("Entre com o segundo número do intervalo: \n");
    scanf("%lf", &b);
    system("cls");
    printf("Seu intervalo é [%lf ; %lf]\n", a, b);
    fa = funcao(a);
    printf("f(a) = %lf\n", fa);
    fb = funcao(b);
    printf("f(b) = %lf\n", fb);
    printf("\n");
    printf("\n");

    //verificar se fa e fb tem sinais opostos, se bolzano é satisfeito
    if (fa*fb > 0){
        printf("O método da bisseção não pode ser utilizado, pois não é satisfeito o Teorema de Bolzano nesse intervalo. :( \n");
    }else if (fabs(funcao(a)) < epson){ //verificar se |f(a)| < epson, ou seja, f(a) já é raiz
        printf("F(a) já é a raíz, ou seja, |f(%lf)| < precisão requerida de %lf.\n", a, epson);
         printf("|f(%lf)| = %lf < precisão de %lf.\n", a, fabs(funcao(a)), epson);
         printf("\n");
    }else if (fabs(funcao(b)) < epson){ //verificar se |f(b)| < epson, ou seja, f(b) já é raiz
        printf("F(b) já é a raíz, ou seja, |f(%lf)| < precisão requerida de %lf.\n", b, epson);
        printf("|f(%lf)| = %lf < precisão de %lf.\n", b, fabs(funcao(b)), epson);
        printf("\n");
    }else{
        pontoMedio = bissecao(a, b, epson);
        printf("Raiz aproximada = %lf e |f(%lf)|= %lf\n\n", pontoMedio, pontoMedio, fabs(funcao(pontoMedio)));
        printf("Número de iterações feitas: %d\n", k);
    }

    system("pause");
}
