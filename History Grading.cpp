#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }

int lcs( int events[20], int student[20], int m, int n )
{
   int L[m+1][n+1];
   int i, j;
   for (i=0; i<=m; i++){
     for (j=0; j<=n; j++){
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (events[i-1] == student[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}


int main(int argc, char const *argv[]) {
  int n, events[20], student[20], res, x;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    events[x-1] = i;
  }
  while (scanf("%d", &x) != EOF) {
    student[x-1]=0;
    for (int i = 1; i < n; i++) {
      scanf("%d", &x);
      student[x-1] = i;
    }
    printf("%d\n",lcs(events, student, n, n));
  }
  return 0;
}
