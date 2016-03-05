#include <stdio.h>

int main () {
    int niceV [ 20000 ], nice;

    // X (c -> d) is the optimum maximal subsequence of nice
    // Y (a -> b) is the last positive subsequence
    // Induction: X (n+1) = X (n) if and only if Y (n) + nice[n] < X (n).
    // Else X (n+1) = Y (n+1) = Y (n) + nice [n]
    int a = 1, b = 1, c = 1, d = 1, Y = 0, X = 0;

    int r, s, i, j, k;

    scanf ( " %d", &r );
    
    for ( k = 0; k < r; k++ ) {
        scanf ( " %d", &s );
    for ( i = 0; i < s; i++ ) {
        a = 1, b = 1, c = 1, d = 1, Y = 0, X = 0;
        

        for ( j = 0; j < s; j++ ) {
            scanf ( " %d", &nice );

            Y += nice;
            b = j + 2;

            if ( Y < 0 ) {
                Y = 0;
                //b = j + 2;
                a = b;
            }

            if ( Y > X ) {
                X = Y;
                c = a;
                d = b;
            }

            if ( Y == X && ( b-a ) > ( d-c ) ) {
                X = Y;
                c = a;
                d = b;
            }
        }
        /*
        if ( c != d )
            printf ( "The nicest part of route %d is between stops %d and %d\n", i, c, d );
        else
            printf ( "Route %d has no nice parts\n", i );
            */
        printf ( "%d\n", X );
    }

    }

    return 0;
}

            
