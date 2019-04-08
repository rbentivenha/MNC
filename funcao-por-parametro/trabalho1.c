#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct termos
{
    int nTermos;
    double *termos;
} TFuncao;

typedef double (fun)(double);
double polinomio_grau_n (double x);

double bissecao(fun * f, double lim_inf, double lim_sup, double erro, int iter);
// saida: valor aproximado e num de iter

int main()
{

    double result = polinomio_grau_n(3);

    printf("f(x) = %.4f\n", result);
    printf("f(x) = %.4f\n", bissecao(polinomio_grau_n, 3, 4, 0, 7));

    return 0;
}

double polinomio_grau_n (double x)
{
    TFuncao *tTermos;
    tTermos = (TFuncao *)malloc(sizeof(TFuncao));
    double resultado = 0;
    int iter = 0;

    printf("Digite o grau da sua função: ");
    scanf("%d", &tTermos->nTermos);
    tTermos->nTermos++;
    tTermos->termos = (double *)malloc(sizeof(double) * tTermos->nTermos);

    do
    {
        if (iter == 0) {
            printf("Digite o termo independente: ");
            scanf("%lf", &tTermos->termos[iter]);
            printf("\n");
        } else {
            printf("Digite o termo x^%d: ", iter);
            scanf("%lf", &tTermos->termos[iter]);
            printf("\n");
        }
        iter++;
    } while (iter < tTermos->nTermos);

    for (int i = 0; i < tTermos->nTermos; i++)
    {
        if (i == 0)
            resultado += tTermos->termos[i];
        else
            resultado += tTermos->termos[i] * pow(x, i);
    }

    free(tTermos->termos);
    free(tTermos);

    return resultado;
}

double bissecao(fun * f, double lim_inf, double lim_sup, double erro, int iter)
{
    return (*f)(lim_inf);
}
