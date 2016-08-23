//Created by William Lacerda on 23/08/2016
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4838
#include <bits/stdc++.h>
#define MAXN 510
using namespace std;

int main(int argc, char const *argv[]) {
    int J, R;
    int  maxJ=0, pontos[MAXN], temp=0, aux;
    while (cin>>J>>R) {
        temp=0;
        memset(pontos, 0, sizeof(pontos));
        for (int i = 0; i < J*R; i++) {
            cin>>aux;
            pontos[i%J]+=aux;
            if (pontos[i%J]>=temp) {
                temp = pontos[i%J];
                maxJ = i%J+1;
            }
        }
        cout<<maxJ<<endl;
    }
    return 0;
}
