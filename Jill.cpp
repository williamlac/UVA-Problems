#include <bits/stdc++.h>
using namespace std;

struct Somas {
  long long int soma;
  int inicio;
  int fim;
};
bool acompare(Somas lhs, Somas rhs) { return lhs.soma > rhs.soma; }
int main(int argc, char const *argv[]) {
  Somas f[20001];
  int b, s, maiorSoma = 0, rota = 1;
  long long int valor;
  scanf("%d\n", &b);
  for (size_t k = 0; k < b; k++) {
    scanf("%d\n", &s);
    for (int i = 0; i <= s; i++) {
      f[i].soma=-INT_MAX;
      f[i].inicio=-1;
      f[i].fim = -1;
    }
    for (int i = 1; i < s; i++) {
      scanf("%lld\n", &valor);
      f[i].soma = max(valor, f[i-1].soma + valor);
      if (f[i-1].soma != 0){
        f[i].inicio = f[i].soma == valor ? i : f[i-1].inicio;
      }
      else {
        f[i].inicio = f[i-1].inicio;
      }
      f[i].fim = i+1;
    }
    sort(f, f+s, acompare);
    maiorSoma = 0;
    for (int i = 1; f[i].soma==f[maiorSoma].soma ; i++) {
      if ((f[i].fim - f[i].inicio) > (f[maiorSoma].fim - f[maiorSoma].inicio)) {
        maiorSoma = i;
      }
      else if ((f[i].fim - f[i].inicio) == (f[maiorSoma].fim - f[maiorSoma].inicio)) {
        if (f[i].inicio < f[maiorSoma].inicio){
          maiorSoma = i;
        }
      }
    }
    if (f[maiorSoma].soma >=0) {
        printf("The nicest part of route %d is between stops %d and %d\n", rota, f[maiorSoma].inicio, f[maiorSoma].fim );
    }else{
      printf("Route %d has no nice parts\n", rota );
    }
    rota++;
  }
  return 0;
}
