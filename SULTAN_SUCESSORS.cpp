#include <bits/stdc++.h>
#define MAXN 100

int N, tabuleiro[MAXN][MAXN], valores[MAXN][MAXN], soma = 0, maior=-1;

void update(int linha, int coluna, int val)
{
    tabuleiro[linha][coluna] +=val;
    for (int i = -1; i<=1; i++)
    {
        for (int j = -1; j<=1; j++)
        {
            for (int k = 0; k<8; k++)
            {
                int x = linha + k*i;
                int y = coluna + k*j;
                if (x<0 || x>=8 || y<0 || y>= 8)
                    continue;
                tabuleiro[x][y]+=val;
            }
        }
    }

}

void nQueens(int p)
{
    if(p==8)
    {
        if (soma > maior){
          maior = soma;
        }
        return;
    }
    for (int i = 0; i<8; i++)
    {
        if (tabuleiro[p][i] == 0)
        {
            update(p,i,1);
            soma+= valores[p][i];
            nQueens(p+1);
            soma-= valores[p][i];
            update(p,i,-1);
        }
    }
}



int main ()
{
    scanf("%d", &N);
    for(int n = 0; n<N; n++){
      for (int i = 0; i<8; i++)
      {
          for (int j = 0; j<8; j++)
          {
              scanf("%d", &valores[i][j]);
          }
      }
    nQueens(0);
    if (maior <10)
      printf("    %d\n", maior);
    else if(maior <100)
      printf("   %d\n", maior);
    else if (maior < 1000)
      printf("  %d\n", maior);
    else if (maior < 10000)
      printf(" %d\n", maior);
    else
      printf("%d\n", maior);
    maior=-1;
  }

    return 0;
}
