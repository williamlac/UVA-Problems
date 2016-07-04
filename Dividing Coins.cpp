#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }


// int knapSack(int W, int wt[], int val[], int n)
// {
//    int i, w;
//    int K[n+1][W+1];
//
//    // Build table K[][] in bottom up manner
//    for (i = 0; i <= n; i++)
//    {
//        for (w = 0; w <= W; w++)
//        {
//            if (i==0 || w==0)
//                K[i][w] = 0;
//            else if (wt[i-1] <= w)
//                  K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
//            else
//                  K[i][w] = K[i-1][w];
//        }
//    }
//
//    return K[n][W];
// }

int knapsack(int m, int capacidade, int moedas[100])
{
   int pd[m+1][capacidade+1];
   for (int i = 0; i <= m; i++)
   {
       for (int j = 0; j <= capacidade; j++)
       {
           if (i==0 || j==0)
               pd[i][j] = 0;
           else if (moedas[i] <= j)
                 pd[i][j] = max(
                              moedas[i] + pd[i-1][j - moedas[i]],
                              pd[i-1][j]);
           else
                 pd[i][j] = pd[i-1][j];
       }
   }
   //printf("MAIOR VALOR %d\n",  pd[m][capacidade] );
   return pd[m][capacidade];
}

int main(int argc, char const *argv[]) {
  int n, m, soma=0, maiorValor, dif;
  int moedas[100];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &m );
    soma = 0;
    for (int j = 1; j <= m; j++) {
      scanf("%d", &moedas[j]);
      soma+=moedas[j];
    }
    dif = knapsack(m, soma/2, moedas);
    dif = soma - dif*2;
    printf("%d\n", dif);
  }
  return 0;
}
