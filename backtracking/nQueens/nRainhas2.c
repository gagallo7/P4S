#include<stdio.h>
#include<stdlib.h>

#define n 8

int count = 0;

void imprimeSol (int r[]) {
    int i, j;

    for (i=0; i < n; i++) {
        for (j=0; j<n; j++) {
            if (r[i]==j) {
                printf(" R ");
            }
            else
                printf (" - ");
        }
        printf("\n");
    }    
    for (i=0; i < n; i++) 
        printf("___");
    printf("\n");
    printf("\n");
}

int viavel (int r[], int k) {
    int i=0, c1, c2;

    c1 = k - r[k];
    c2 = k + r[k];
    for (i=0; i<k; i++) {
        if (c1 == i-r[i])
            return 0;
        if (c2 == i+r[i])
            return 0;
        if (r[k] == r[i])
            return 0;
    }
    return 1;
}

void nRainhas (int r[], int l, int k) {
    int i;

    if ( k == n ) {
        imprimeSol(r);
        count++;
    }

    for ( i = 0; i < n; i++ ) {
        r[k] = i;

        if ( viavel(r, k) ) {
            nRainhas (r, i, k+1);
        }
    }
}

int main () {
    int j, i;
    int rainhas[n];

    for (i = 0; i < n; i++) {
        rainhas[i] = 0;
    }

    nRainhas (rainhas, 0, 0);

    //	imprimeSol (rainhas);

    printf("\nTotal: %d\n", count);

    return 0;
}
