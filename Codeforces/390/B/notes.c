#include<stdio.h>

int main () {
    int n, b[100000], x[100000], i;
    long long int tmp, joy;

    scanf ( " %d", &n );

    for ( i = 0; i < n; i++ ) 
    {
        scanf ( " %d", &x[i] );
    }

    for ( i = 0; i < n; i++ ) 
    {
        scanf ( " %d", &b[i] );
    }

    joy = 0;
    for ( i = 0; i < n; i++ ) 
    {
        if ( x[i] * 2 < b[i] || b[i] == 1 )
        {
            joy--;
        }

        else
        {
            //tmp = b[i] >> 1;
            tmp = b[i];
            joy += tmp * tmp;
            if ( b[i] & 1 )
            {
                joy--;
            }
        }
        //printf ( "i=%d joy=%d\n", i, joy );
    }

    printf ( "%lli\n", joy >> 2 );


    return 0;
}
