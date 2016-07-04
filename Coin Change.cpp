#include <bits/stdc++.h>


int main(int argc, char const *argv[]) {

  int moedas[5] = {1,5,10,25,50};
  int f[7489];
  int V, N = 5;

  while (scanf("%d\n", &V)!= EOF) {
    for (int j = 1; j <=V; j++){
    	f[j] = 0;
    }
    f[0]=1;

    for (int i = 0; i <N; i++){
    	for (int j = 1; j <=V; j++){
    		if (moedas[i] <= j){
    			f[j] += f[ (j - moedas[i])];
        }
      }
    }
    printf("%d\n", f[V]);
  }

  return 0;
}
