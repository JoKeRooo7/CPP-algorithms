#include <iostream>
#include <stdlib.h>

using namespace std;

int heads() {
    return rand() < RAND_MAX/2;
}

int main(int argc, char *argv[]){
    if (argc == 1) return 0;
    int i, j, cnt;
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int *f = new int[N + 1];
    for (j = 0; j <= N; j++) f[j] = 0;
    for (i = 0; i < M; i++, f[cnt]++) {
        for (cnt = 0, j = 0; j <= N; j++)
            if (heads()) cnt++;                     //if true or 1
    }
    for (j = 1; j <= N; j++) {
        if (f[j] == 0) cout << ".";
        for (i = 0; i < f[j]; i+=10) cout << "*";
        cout << endl;
    }
}
