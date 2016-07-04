//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=347
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define TAM_MAX 1000
int primos[TAM_MAX];
void crivo() {
   for (int i=1; i<TAM_MAX; i++) {
       primos[i] = 1;
   }

   for (int i=2; i<sqrt(TAM_MAX) ; i++){
      for (int j=i*i; j<TAM_MAX; j+=i){
         primos[j] = 0;
       }
    }
    primos[0] = 0;
}

int main(int argc, char const *argv[]) {
  crivo();
  int lista[TAM_MAX];
  int cont,c, n;
  while (scanf("%d %d", &n, &c)!=EOF) {
    cont=0;
    for (size_t i = 0; i <= n; i++) {
      if (primos[i] == 1) {
        lista[cont]=i;
        cont++;

      }
    }
    printf("%d %d:", n, c);
    int first, last;
        if (cont%2==0) {
          first = cont/2 - c;
          last = first + 2*c;
        }
        else{
          first = cont/2 - c+1;
          last = first + 2*c-1;
        }
        first = first < 0 ? 0 : first;
        last = last > cont-1 ? cont : last;
      for (int i = first; i < last; i++) {
        printf(" %d", lista[i]);
      }
    printf("\n\n");
  }
  return 0;
}
