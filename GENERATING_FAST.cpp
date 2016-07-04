//
//  main.cpp
//  Maratona-Lista 2
//
//  Created by William Sathler Lacerda on 5/17/16.
//  Copyright © 2016 William Sathler Lacerda. All rights reserved.
//
#define tam 128
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 10

int main ()
{
	int N;
	char vetor[MAXN];
	scanf("%d", &N);
	while (N--) {
		scanf("%s", vetor);
		sort(vetor, vetor+strlen(vetor));
		do {
			printf("%s\n", vetor);
		} while (next_permutation(vetor, vetor + strlen(vetor)));
		printf("\n");
	}
	return 0;
}