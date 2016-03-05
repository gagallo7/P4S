#include<stdio.h>
#include<stdlib.h>

int knapsack ( int a[], int K, int m, int** A ) {
    int i, j, x, y;
    /*int A [m] [25000*100];
    for ( i = 0; i < m; i++ ) {
        printf ( "%d ", a[i] );
    }
    */
    


    for ( i = 0; i < m; i++ ) {
        for ( j = 0; j < K*m; j++ ) {
            /*printf ( "%d %d   %d, %d\n", K, m, i, j );*/
            A [i] [j] = 0;
        }
    }
    for ( j = 0; j < m; j++ ) {
        A [ 0 ] [ a[j] ] = 0;
    }

    for ( i = 0; i < m; i++ ) {
        A [1] [ a[i] ] = a[i];
        /*
        printf ( "K %d A[1][%d] = %d \n", K, a[i], A[1][a[i]] );
        */
    }

    for ( i = 1; i <= m; i++ ) {
        for ( j = 0; j <= K; j++ ) {
            x = A[ i-1 ][ j ];
            /*
            printf ( "i:%d j:%d\n", i, j);
            */

            if ( j >= a[i-1] )
                y = A[ i-1 ][ j - a[i-1] ] + a[i-1];
            else
                y = 0;
            
            if ( x > y && x <= K )
                A [i][j] = x;
            else
                A [i][j] = y;

            if ( A[i][j] == K )
                return K;
                /*
            printf ( "K %d A[%d][%d] = %d  x=%d y=%d  \n", K, i, j, A[i][j], x, y );
            */
        }
    }
    /*return A[m-1][K-1] - K;*/
    return A[m][K];
}


int main () {
    int i, j, n, m;
    int a[100];
    int sum, odd, knap;

    int** A = (int **) malloc ( sizeof (int *) * (100+1) );
    for ( j = 0; j < 100+1; j++ ) {
        A [j] = (int *) malloc ( sizeof (int) * 500 * 100 * 100 );
    }

    scanf ( " %d", &n );

    for ( i = 0; i < n; i++ ) {
        scanf ( " %d", &m );

        sum = 0;
        for ( j = 0; j < m; j++ ) {
            scanf ( " %d", &a[j] );
            sum += a[j];
        }

        /*
        for ( j = 0; j < m; j++ ) {
            printf ( "%7d ", a[j] );
        }
        printf ( "sum:%d\n", sum );
        */

        odd = sum&1;
        knap  = knapsack ( a, (sum/2), m, A );
        /*
        if ( knap*2 >= sum )
            sum = abs (knap - sum/2);
        else
            */
        /*printf ( "\nAnswer>> " );
        */
        sum = sum - knap*2;
        printf ( "%d\n", sum);
        /*
        printf ( "sum: %d odd: %d\n", sum, sum&1 );
        */
    }
    return 0;
}
