//Created by William Lacerda on 12/08/2016
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2724
#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int main(int argc, char const *argv[]) {
    int h1, h2, m1, m2, t1, t2;
    cin >>h1 >> m1 >> h2 >> m2;
    while (h1 != 0 || h2 != 0 || m1 != 0 || m2 != 0) {
        if (h1 < h2) {
            t1 = h1*60 + m1;
            t2 = h2*60 + m2;
            cout << t2-t1<<endl;
        } else if (h1 == h2){
            if (m2>=m1)
                cout << m2-m1<<endl;
            else
                cout << 1440 + (m2-m1)<<endl;
        } else {
            t1 = 1440 - (h1*60 + m1);
            //cout <<"t1 "<<t1<<endl;
            t2 = h2*60 + m2;

            //cout <<"t2 "<<t2<<endl;
            cout << t2+t1<<endl;
        }
        cin >>h1 >> m1 >> h2 >> m2;
    }
    return 0;
}
