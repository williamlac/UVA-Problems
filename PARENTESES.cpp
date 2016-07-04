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

typedef struct {
	int topo;
	char item[tam];
} PILHA;

void initPilha(PILHA &p){
	p.topo = -1;
}

bool pilhaVazia (PILHA p){
	if (p.topo == -1){
		return true;
	}
	else
		return false;
}

bool pilhaCheia(PILHA p, int n) {
	if (p.topo == n-1)
		return true;
	else
		return false;
}

void push(PILHA &p, char x) {
	p.item[++p.topo]=x;
}

int pop(PILHA &p) {
	return (p.item[p.topo--]);
}

int top(PILHA p) {
	if(pilhaVazia(p))
		return 0;
	else
		return (p.item[p.topo]);
}




int main() {
	
	int N;
	char exp[tam];
	PILHA p;
	scanf("%d", &N);
	getchar();
	while (N--) {
		initPilha(p);
		gets(exp);
		//		if (exp[0]=='\0') {
		//			printf("Yes\n");
		//		}
		for (int j = 0; j < strlen(exp); j++) {
			if (pilhaVazia(p)) {
				push(p, exp[j]);
			}
			else if (exp[j] == ']'){
				if (top(p) == '[') {
					pop(p);
				}
				else
					break;
			}
			else if (exp[j] == ')'){
				if (top(p) == '(') {
					pop(p);
				}
				else
					break;
			}
			else
				push(p, exp[j]);
		}
		if (pilhaVazia(p)) {
			printf("Yes\n");
		}
		else
			printf("No\n");
	}
	
	return 0;
}
