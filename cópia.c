#include <stdio.h>
#include <math.h>

#define log10(x) log(x)/log(10);

float f(float x) {
   return pow(x,2)-4; // Função cuja raiz deve ser determinada
}

// Implementação do Método da Bissecção para zeros de funções
// Autor: Renan Birck
// Disciplina: Métodos Numéricos e Computacionais
// Curso: Eng. Elétrica - Universidade Federal de Santa Maria
// Santa Maria, maio de 2010.

int main() {

   // eps: erro
   // a0 e b0: pontos iniciais
   // tam: tamanho do intervlao
   // pm: ponto médio
   // it: número de iterações

   float eps, a0, b0, tam, pm, it;
   int bolzano_ok = 0; // flag do teorema de Bolzano

   printf("Digite a precisão requerida: \n");
   scanf("%f",&eps);

   printf("Digite o intervalo onde deve se buscar a raiz (ex. [0;5] = digite 0 5): \n");
   scanf("%f %f",&a0,&b0);

   // O teorema de Bolzano (valor intermediário) foi satisfeito?
   // f(a0) * f(b0) < 0 -> existe troca de sinal no intervalo dado e, portanto
   // existe raiz nele.
    bolzano_ok = (f(a0)*f(b0) > 0?0:1);

   // Não, então pedir um novo intervalo inicial.
   while(bolzano_ok == 0) {
      printf("\nIntervalo [%f;%f] não satisfaz as condições do teorema de Bolzano. Tente outro.\n Intervalo: ",a0,b0);
      scanf("%f %f", &a0, &b0);
      bolzano_ok = (f(a0)*f(b0) > 0?0:1);
   }

   // Iteraçõs necessárias

   it = log10(b0 - a0);
   it -= log10(eps);
   it /= log(2);

   printf("Serão necessárias %.0f iterações.\n",ceil(it));

   // Um dos extremos do intervalo é a raiz
   if(f(a0) == 0 || f(b0) == 0)  {
      printf("O valor %f é zero da expressão. \n", f(a0)==0?a0:b0);
      return 0;
   }

   // Implementação do método da bisecção


   while(tam > eps) {
      tam = b0-a0;
      pm = (a0+b0)/2;
      if(f(pm) == 0) {
         printf("SOLUÇÃO EXATA ENCONTRADA!! x = %f\n",pm);
         return 0;
      }

      if(f(a0)*f(pm) < 0)  b0 = pm; // a solução está a esquerda
       else a0 = pm;  // a solução está a direita

   }

   printf("Intervalo final: [%f,%f]\n Solução aproximada: %f",a0,b0,(a0+b0)/2);

   return 0;
}
