//
//  main.cpp
//  Maratona-Lista 2
//
//  Created by William Sathler Lacerda on 5/17/16.
//  Copyright © 2016 William Sathler Lacerda. All rights reserved.
//
#define tam 10000
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstring>
using namespace std;

struct Queries {
	int valor;
	bool found;
	int pos;
};

int main() {
	int N, Q, mar[tam], caso = 1;
	Queries que[tam];
	scanf("%d %d", &N, &Q);
	
	while (N!=0 && Q!=0) {
		for (int i = 0; i<N; i++) {
			scanf("%d", &mar[i]);
		}
		sort(mar, mar+N);
		for (int i = 0; i<Q; i++) {
			scanf("%d", &que[i].valor);
			que[i].found = false;
			que[i].pos = -1;
			for (int j = 0; j<N; j++) {
				if (que[i].valor == mar[j] && que[i].found == false) {
					que[i].found = true;
					que[i].pos = j;
				}
			}
		}
		printf("CASE# %d:\n", caso);
		for (int i = 0; i<Q; i++) {
			if (que[i].found) {
				printf("%d found at %d\n", que[i].valor, que[i].pos+1);
			}
			else
				printf("%d not found\n", que[i].valor);
		}
		scanf("%d %d", &N, &Q);
		caso++;
		
	}
	
	return 0;
}
