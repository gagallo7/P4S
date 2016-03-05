#include<stdio.h>
#define MAX(a,b) a > b ? a : b

/*
   int mSSrow ( int M[][], int* pb ) {
   int x, y;
   x = 0;
   y = 0;
   for ( i = j; i < n; i++ ) {
   if ( y + M [ i ] [ j ] >= 0 ) {
   y += M [ i ] [ j ];
   b = i;
   }
   else {
   y = 0;
   a = i;
   b = i;
   }

   if ( y > x ) {
   x = y;
 *pb = b;
 }
 }
 return x;
 }

 int mSScol ( int M[][], int* pb ) {
 int x, y;
 x = 0;
 y = 0;
 for ( i = j; i < n; i++ ) {
 if ( y + M [ i ] [ j ] >= 0 ) {
 y += M [ i ] [ j ];
 b = i;
 }
 else {
 y = 0;
 a = i;
 b = i;
 }

 if ( y > x ) {
 x = y;
 *pb = b;
 }
 }
 return x;
 }
 */

int max5 ( int a, int b, int c, int d, int e ) {
    int t1, t2;
    t1 = MAX ( a , b );
    t2 = MAX ( d , e );
    t1 = MAX ( t1, t2 );
    return MAX ( t1, c );
}

int max3 ( int a, int b, int c) {
    int t1;
    t1 = MAX ( a , b );
    return MAX ( t1, c );
}

int main () {
    int M [ 100 ] [ 100 ];
    int m [ 100 ] [ 100 ];
    int X [ 100 ] [ 100 ];
    int Y [ 100 ] [ 100 ];
    int n, i, j, k;
    int x, y, a, b, c, d, e, Lx, Ly, g, K;
    int max = -127;

    scanf ( " %d", &n );

    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            scanf ( " %d", & M [ i ] [ j ] );
            m [i][j] = M[i][j];
            X [ i ] [ j ] = i;
            Y [ i ] [ j ] = j;
        }
    }
    /*
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf ("%d ", m[i][j]);
        }
        printf ("\n");
    }
*/
    K = 0;
    for ( g = 0; g < n; g++ ) {
        for ( i = 0; i < n; i++ ) 
            for ( j = 0; j < n; j++ ) {
                /*printf ( "%d %d\n", g, j );*/
                if ( i+K+1 < n)
                    m [i][j] += M[i+K+1][j];
            }
        K++;
        /*
        printf ( "20\n" );
        for ( i = 0; i < n; i++ ) {
            for ( j = 0; j < n; j++ ) {
                printf ("%4d ", m[i][j]);
            }
            printf ("\n");
        }
        */
    for ( i = 0; i < n; i++ ) {
        y = m[i][0];
        x = m[i][0];
        a = 1, b = 1, c = 1, d = 1, y = 0, x = 0;
        

        for ( j = 0; j < n; j++ ) {
          /*          printf ( "%d + %d >= %d\n", y, m[j][i], m[i][0] );*/

            y += m[i][j];

            if ( y < 0 ) {
                y = 0;
            }

            if ( y > x ) {
                x = y;
            }
        }
        max = MAX (max, x);
    }
        /*
        for ( j = 0; j < n; j++ ) {
            x = m[j][0];
            y = m[j][0];
            for ( i = 1; i < n; i++ ) {
                    /*printf ( "%d + %d >= %d\n", y, m[j][i], m[j][0] );*/
        /*
                if ( y + m [ j ] [ i ] >= m[j][0] ) {
                    y += m [ j ] [ i ];
                }
                else {
                    y = m[j][0];
                }

                if ( y > x ) {
                    x = y;
                }
            }
                max = MAX (max, x);
        }
        */
        /*
           for ( k = 0; k < n; k++ ) 
           for ( j = 0; j < n; j++ ) {
           x = m[k][j];
           y = m[k][j];
           for ( i = j+1; i < n; i++ ) {
           if ( y + M [ k ] [ i ] >= m[k][j] ) {
           y += M [ k ] [ i ];
           b = i;
           }
           else {
           y = m[k][j];
           a = i;
           b = i;
           }

           if ( y > x ) {
           x = y;
           Y [ k ] [ j ] = b;
           m [ k ] [ j ] = y;
           max = MAX (max, y);
           }
           }
           }

           for ( j = 0; j < n; j++ ) {
           x = M[j][k];
           y = M[j][k];
           for ( i = j+1; i < n; i++ ) {
           if ( y + M [ i ] [ k ] >= M[j][k] ) {
           y += M [ i ] [ k ];
           b = i;
           }
           else {
           y = M[j][k];
           a = i;
           b = i;
           }

           if ( y > m[j][k] ) {
           x = y;
           X [ j ] [ k ] = b;
           m [ j ] [ k ] = y;
           }
           }
           }
           */
    }
    /*
    printf ( "\n" );
    for ( j = 0; j < n; j++ ) {
        printf ( "%d ", m [ n - 1 ] [ j ] );
    }
    printf ( "\n" );
    for ( j = 0; j < n; j++ ) {
        printf ( "%d ", X [ n - 1 ] [ j ] );
    }
    printf ( "\n" );
    for ( j = 0; j < n; j++ ) {
        printf ( "%d ", Y [ n - 1 ] [ j ] );
    }
    printf ( "\n" );

    printf ( "\n" );
    for ( j = 0; j < n; j++ ) {
        printf ( "%d ", m [ j ] [ n - 1 ] );
    }
    printf ( "\n" );
    for ( j = 0; j < n; j++ ) {
        printf ( "%d ", X [ j ] [ n - 1 ] );
    }
    printf ( "\n" );
    for ( j = 0; j < n; j++ ) {
        printf ( "%d ", Y [ j ] [ n - 1 ] );
    }
    printf ( "\n" );

    */
    printf ( "%d\n", max );

    return 0;
}

