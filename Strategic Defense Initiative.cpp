#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }
int pd[10000];
int aux[10000];
int missiles[10000];
int LIS (int size, int *final){
  int max = -12;
  for (int i = 1; i < size; i++) {
    pd[i]=1;
    aux[i]=-1;
  }
  pd[0]=1;
  aux[0]=-1;
  for (int i = 1; i < size; i++) {
    for (int j=i-1;j>=0;j--) {
      if (missiles[i]>missiles[j] && pd[i] < pd[j]+1) {
        pd[i] = pd[j]+1;
        aux[i]=j;
      }
    }
  }
  for (int i = 0; i < size; i++) {
    if (max < pd[i]) {
      max = pd[i];
      *final = i;
    }
  }
  return max;
}

void print(int i){
  if (aux[i]==-1) {
    printf("%d\n", missiles[i]);
    return;
  }
  else{
    print(aux[i]);
    printf("%d\n", missiles[i]);
  }
}

int main(int argc, char const *argv[]) {
  int n, hits, final;
  char s[100],eat;
  scanf("%d", &n);
  scanf("%c",&eat);
  gets(s);
  while (n-- ) {
    int ind = 0;
    while(gets(s)){
        if(strcmp(s,"")==0)    break;
        sscanf(s," %d",&missiles[ind++]);
    }
    hits = LIS(ind, &final);
    printf("Max hits: %d\n", hits );
    print(final);
    if (n!=0) {
      printf("\n" );
    }

  }
  return 0;
}
