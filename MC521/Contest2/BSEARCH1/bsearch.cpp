#include <cstdio>

int v [112345];
int n;

void bsearch ( int num )
{
    int a = 0;
    int b = n;
    int pos = (a+b)/2;

    while ( b - a > 1 )
    {
        if ( num > v[pos] )
        {
            a = pos;           
            pos = (a+b)/2;
        }
        else if ( num < v[pos] )
        {
            b = pos;           
            pos = (a+b)/2;
        }
        else
        {
            while ( v[pos-1] == num )
            {
                pos--;
            }
            printf ( "%d\n\n", pos );
            return;
        }
    }

    if ( v[n-1] == num )
    {
        printf ( "%d\n\n", n-1 );
        return;
    }

    if ( v[0] == num )
    {
        printf ( "0\n\n" );
        return;
    }

    printf ( "-1\n\n" );
    return;
}

int main ()
{
    int q;
    int num;

    scanf ( " %d %d", &n, &q );

    for ( int i = 0; i < n; i++ )
    {
        scanf ( " %d", &v[i] );
    }

    for ( int i = 0; i < q; i++ )
    {
        scanf ( " %d", &num );

        bsearch ( num );
    }

    return 0;
}
