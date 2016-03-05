#include<stdio.h>
#include<stdlib.h>

int count = 0;

void imprimeSol (int r[]) {
    int i, j;

    for (i=0; i < 14; i++) {
        for (j=0; j< 14; j++) {
            if (r[i]==j) {
                printf(" R ");
            }
            else
                printf (" - ");
        }
        printf("\n");
    }    
    for (i=0; i < 14; i++) 
        printf("___");
    printf("\n");
    printf("\n");
}

int viavel (int r[], int k, int rk) {
    int i=0, c1, c2;

    c1 = k - rk;
    c2 = k + rk;
    for (i=0; i<k; i++) {
        if (rk == r[i])
            return 0;
        if (c1 == i-r[i])
            return 0;
        if (c2 == i+r[i])
            return 0;
    }
    return 1;
}

void nRainhas (/*int r[],*/ int l, int k, char M[][14], int n, int da, int db, int dv) {
    int i;
    for ( i = 0; i < n; i++ ) {
        if (M[k][ i ] == '*' || ( 1 << i ) & dv || da & (1 << (i+k)) ) {
            continue;
        }

        int a = 1 << (i+k);
        int b = 1 << (i-k + 13);

        /*
        if ( k == 0 ) {
            printf ( " da: %d db: %d i+k: %d i-k: %d\n", da, db, a, b );
        }
        */
        if (   !( da & (a) )    &&
               !( db & (b) )        ) {
           /* printf ("OK\n");*/
/*            r[k] = i;*/
            if ( k == n-1 ) {
                count++;
                return;
            }
            nRainhas (/*r,*/ i, k+1, M, n, da|a, db|b, dv|(1<<i));
        }

/*
        int Viavel = viavel ( r, k, r[k] );

        if ( k == n-1 && Viavel ) {
            count++;
        }
        */
    }
}

int main () {
    int j, i, caso = 0;
    int Case = 1;
    char M[14][14];
    /*int rainhas[14];*/
    char item;

    /*
    for (i = 0; i < 14; i++) {
        rainhas[i] = 0;
    }
    */

    scanf ( " %d", &caso );
    while ( caso > 0 ) {
        count = 0;
        for ( i = 0; i < caso; i++ ) {
            for ( j = 0; j < caso; j++ ) {
                scanf ( " %c", &M[i][j] );
            }
        }
        nRainhas (/*rainhas,*/ 0, 0, M, caso, 0, 0, 0);
        printf("Case %d: %d\n", Case++, count);
        scanf ( " %d", &caso );
    }

    return 0;
}
