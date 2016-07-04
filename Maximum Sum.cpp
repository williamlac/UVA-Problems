#include <bits/stdc++.h>
#define maxN 100
using namespace std;

int pd[maxN][maxN];

int biggestSum (int matriz[maxN][maxN], int N){
    int aux[N];
    memset(aux, 0, sizeof(aux));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pd[i][j] = INT_MIN;
        }
    }
    int lin=1, maxSoma = INT_MIN;
    while (lin <= N){
        for (int i = 0; i <= N-lin; i++) {
            for (int j = 0; j < lin; j++) {
                for (int k = 0; k < N; k++) {
                    aux[k]+= matriz[i+j][k];
                    if (k != 0 && j == lin-1) {
                        //pd of a certain pos will always be either what was already there, because the max sum could have
                        //happened with another number of lines; or the sum of that column + the max sum of the previous one
                        //with this number of lines ; or the sum of that column with the current number of lines
                        pd[j+i][k]=max(max(pd[j+i][k], aux[k-1] + aux[k]), aux[k]);
                        maxSoma = max(maxSoma, pd[i+j][k]);
                        //aux is the sum of the column, after aux[k] is used, transform it into the value of
                        //the largest sum possible
                        aux[k] = max(aux[k],aux[k]+aux[k-1]);
                    }
                    else if (k == 0 && j == lin-1){
                        pd[i+j][k]=max(pd[i+j][k], aux[k]);
                        maxSoma = max(maxSoma, pd[i+j][k]);
                    }
                }
            }
            memset(aux, 0, sizeof(aux));
        }
        lin++;
    }
    return maxSoma;
}

int main(int argc, char const *argv[]) {
    int N, matriz[maxN][maxN];
    while (cin >> N){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matriz[i][j];
            }
        }
        cout << biggestSum(matriz, N) << endl;
    }
  return 0;
}
