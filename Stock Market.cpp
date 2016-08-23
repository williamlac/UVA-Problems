//Created by William Lacerda on 23/08/2016
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4830
#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

bool pairCompare(const pair<int, int>& firstElem, const pair<int, int>& secondElem) {
  return firstElem.first < secondElem.first;

}

int main(int argc, char const *argv[]) {
    int N, C, v;
    int pd[MAXN][2];
    vector< int > valores;
    while (cin >> N >> C) {
        valores.clear();
        memset(pd, 0, sizeof(pd));
        for (int i = 0; i < N; i++) {
            cin>>v;
            valores.push_back(v);
        }
        pd[N][0] = pd[N][1] = 0;

        for (int i = N-1; i >= 0; i--) {
            pd[i][0] = max(pd[i+1][0], pd[i+1][1] - C - valores[i]);
            pd[i][1] = max(pd[i+1][1], pd[i+1][0] + valores[i]);
        }
        cout << pd[0][0] << endl;
    }
    return 0;
}
