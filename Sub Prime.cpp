//Created by William Lacerda on 12/08/2016
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2726
#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int main(int argc, char const *argv[]) {
    int B, N, d, c, v;
    int money[22];
    cin >>B >> N;
    while (B != 0 || N != 0) {
        for (int i = 1; i <= B; i++) {
            cin >> money[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> d >> c >> v;
            money[d]-=v;
            money[c]+=v;
        }
        for (int i = 1; i <= B; i++) {
            //cout << money[i] << " ";
            if (money[i] <0) {
                cout << 'N'<<endl;
                break;
            }
            else if (i == B){
                cout << 'S'<<endl;
            }
        }
        cin >>B >> N;
    }
    return 0;
}
