#include<bits/stdc++.h>
using namespace std;


int min(int a, int b) {

    return a < b ? a : b;
}
int distancia[81][81], step, deleted, insert;
char path[81][81];

int editDistance(char *word1, char *word2, int m, int n) {

    int insert, replace, deleted;

    for ( int i = 1; i <= m; i++) {
        distancia[i][0] = i;
        path[i][0] = 'd';
    }

    for ( int j = 1; j <= n; j++) {
        distancia[0][j] = j;
        path[0][j] = 'i';
    }
    for ( int i = 1; i <= m; i++)
        for ( int j = 1; j <= n; j++) {

            deleted = distancia[i - 1][j] + 1;
            insert = distancia[i][j - 1] + 1;
            replace = distancia[i - 1][j - 1] + (word1[i] != word2[j]);

            distancia[i][j] = min(min(insert, deleted), replace);

            if (deleted == distancia[i][j])
                path[i][j] = 'd';

            else if (insert == distancia[i][j])
                    path[i][j] = 'i';

            else if (word1[i] != word2[j])
                path[i][j] = 'r';
            else
                path[i][j] = '0';

        }
    return distancia[m][n];
}



void printPath(char *word1, char *word2, int i, int j) {

    if (path[i][j] == '0'){
        printPath(word1, word2, i - 1, j - 1);
    }

    else if (path[i][j] == 'd') {
        printPath(word1, word2, i - 1, j);
        printf("%d Delete %d\n", step++, i + insert - deleted);
        deleted++;
    }

    else if (path[i][j] == 'i') {
        printPath(word1, word2, i, j - 1);
        printf("%d Insert %d,%c\n", step++, j, word2[j]);
        insert++;
    }

    else if (path[i][j] == 'r') {
        printPath(word1, word2, i - 1, j - 1);
        printf("%d Replace %d,%c\n", step++, i + insert - deleted, word2[j]);
    }
}

int main(int argc, char const *argv[]) {

   char word1[82], word2[82];
   int m, n, first = 1;

   while (gets(word1 + 1)) {
       gets(word2 + 1);

       if (!first)
           printf("\n");
       first = 0;

       m = (int) strlen(word1 + 1);
       n = (int) strlen(word2 + 1);

       printf("%d\n", editDistance(word1, word2, m, n));

       step = 1;
       deleted = 0;
       insert = 0;

       printPath(word1, word2, m, n);
   }
   return 0;
}
