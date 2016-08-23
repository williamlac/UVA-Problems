//Created by William Lacerda and Thiago Henrique on 23/08/2016
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4836
#include <bits/stdc++.h>
#define MAXN 3010
using namespace std;

bool pairCompare(const pair<int, int>& firstElem, const pair<int, int>& secondElem) {
  return firstElem.first < secondElem.first;
}

int main(int argc, char const *argv[]) {
    int N, x, y, minimo, maximo;
    std::vector<pair<int, int> > v;
    bool possib;
    while (cin>>N) {
        int total = 0;
        v.clear();
        for (int i = 0; i < N; i++) {
            cin>>x>>y;
            v.push_back(make_pair(x, y));
        }
        sort(v.begin(), v.end(), pairCompare);


        // TLE:
        // for (int i = 0; i < N-1; i++) {
        //     for (int j = i+1; j < N; j++) {
        //         possib=true;
        //         if (v[i].first != v[j].first && v[i].second != v[j].second){
        //             for (int k = i+1; k < j; k++) {
        //                 if (v[k].first == v[i].first || v[k].first == v[j].first) {
        //                     possib = false;
        //                     break;
        //                 }
        //                 else if (v[k].second == v[i].second || v[k].second == v[j].second){
        //                     possib = false;
        //                     break;
        //                 }
        //                 else if (v[i].second > v[j].second){
        //                     if (v[k].second > v[j].second && v[k].second < v[i].second) {
        //                         possib = false;
        //                         break;
        //                     }
        //                 }
        //                 else if (v[i].second < v[j].second){
        //                     if (v[k].second < v[j].second && v[k].second > v[i].second) {
        //                         possib = false;
        //                         break;
        //                     }
        //                 }
        //             }
        //             if (possib == true){
        //                 total++;
        //             }
        //         }
        //     }
        // }
        // cout <<total<<endl;

        //ACCEPTED - by Thiago Henrique
        for (int i = 0; i < N-1; i++) {
			minimo=200000000;
			maximo=-200000000;
            for (int j = i+1; j < N; j++) {
                if(v[j].second>v[i].second){
					if(v[j].second<minimo){
						total++;
						minimo=v[j].second;
					}
				}
				if(v[j].second<v[i].second){
					if(v[j].second>maximo){
						total++;
						maximo=v[j].second;
					}
				}
            }
        }
        cout <<total<<endl;
    }
    return 0;
}
