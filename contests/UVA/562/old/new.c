#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SUB(x,y) x < y ? y-x : x - y
static int cmp ( const void *p1, const void *p2 ) {
    long long int a = (long long int) *(long long int *const) p1;
    long long int b = (long long int) *(long long int *const) p2;
    if ( a > b ) {
        return -1;
    }
    else if ( a < b ) {
        return 1;
    }
    else
        return 0;
}

int main () {
    int i, j, n, m, map[100];
    long long int a[100];
    long long int acc, x, y;
    int sum, aux;

    scanf ( " %d", &n );

    for ( i = 0; i < n; i++ ) {
        scanf ( " %d", &m );
        /*printf ("\n--------------- m = %d\n", m);*/

        for ( j = 0; j < m; j++ ) {
            scanf ( " %lld", &a[j] );
        }

        qsort (a, m, sizeof (long long int), cmp);

        for ( j = 0; j < m; j++ ) {
            printf ( "%7d ", a[j] );
        }
            printf ( "\n" );
        /*
        */
        acc = 0;
        sum = 0;
        for ( j = 0; j < m; j++ ) {
            x = SUB( acc, a[j] );
            y = acc + a[j];
          sum += a[j];
            map [j] = 0;
            
            if ( x < y ) {
                acc = acc - a[j];
                printf ( "%7d ", -1 );
                map [j] = 1; 
            }
            else {
                acc = y;
                printf ( "%7d ", 1 );
            }
            /*
            printf ( "%d\n", acc );
            */
        }
        aux = 0;
        
            printf ( "\n" );
        for ( j = 0; j < m; j++ ) {
            if ( map [j] ) {
                printf ( "%d ", a[j] );
                aux += a[j];
            }
        }
            printf ( "\ts: %d\n", aux );
        printf ( "%d  average: %d+%d\n", abs(acc), sum/2, sum&1 );
        printf ( "%lld\n", llabs(acc) );

    }
    return 0;
}


