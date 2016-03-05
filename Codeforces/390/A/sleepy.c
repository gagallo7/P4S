#include <stdio.h>

int main ()
{
    int n, a, b, i;
    int h[101], v[101];
    int nv = 0, nh = 0;

    scanf ( " %d", &n );

    for ( i = 0; i < 101; i++ )
    {
        v[i] = 0;
        h[i] = 0;
    }

    for ( i = 0; i < n; i ++ )
    {
        scanf ( " %d %d", &a, &b );
        v[a]++;
        h[b]++;
    }

    for ( i = 0; i < 101; i++ )
    {
        if ( v[i] > 0 )
            nv++;
        if ( h[i] > 0 )
            nh++;
    }

    printf ( "%d\n", nh < nv ? nh : nv );

    return 0;
}
