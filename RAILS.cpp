#include<bits/stdc++.h>
#define tam 1000
typedef struct {
	int topo;
	int item[tam];
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

void push(PILHA &p, int x) {
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

int main(){
	PILHA p;
	int n, n2 = 1, num=-1, pushed = 0, limite = 0;
	initPilha(p);
	scanf("%d", &n);
	while(n!=0){
		PILHA trem;
		while (n2!=0 ){
			initPilha(trem);
			initPilha(p);
			limite = 0;
			num = -1;
			push(p, 1);
			pushed = 1;
			for (int i =0; i<n; i++){
				scanf("%d", &num);
				if (num != 0){
					push(trem, num);
					if(limite==0){
						for (int j = top(p); j<=n; j++){
							if(!pilhaVazia (p) && !pilhaVazia(trem)){
								if (top(trem) == top(p)){
									pop(trem);
									pop(p);
									if (!pilhaVazia(p))
										j = top(p);
									else if (j<n && i<n-1 && pushed<n){
										push(p, ++pushed);
										break;
									}
								}
								else if(pushed == n){
									limite = 1;
									break;
								}
								else if (!pilhaCheia(p, n) && j<n && pushed < n){
									push(p, ++pushed);
									
								}
							}
						}
					}
				}
				else{
					n2 = 0;
					i = n+1;
				}
			}
			if (n2!=0){
				if (pilhaVazia(p) && pilhaVazia(trem))
					printf("Yes\n");
				else{
					printf("No\n");
				}
			}
		}
		scanf("%d", &n);
		n2=1;
		printf("\n");
	}
	return 0;
}
