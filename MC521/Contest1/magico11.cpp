#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio ( false );
    int m [1000][1000];
    int n;
    bool magic = true;
    int parcial = 0;
    int old;

    //cin >> n;
    scanf ( " %d", &n  );

    long long int S = n*(n*n+1)/2;

    for ( int i = 0; i < n; i++ )
    {
        old = parcial;
        parcial = 0;
        for ( int j = 0; j < n; j++ )
        {
            int aux;
            //cin >> aux;
            scanf ( " %d", &aux );
            if ( aux > n*n )
            {
                //cout << 0 << endl;
                printf ( "0\n" );
                return 0;
            }
            parcial += aux;
            m[i][j] = aux;
        }
        if ( parcial != S)
        {
            //cout << 0 << endl;
                printf ( "0\n" );
            return 0;
        }

        if ( old && old != parcial )
        {
            //cout << 0 << endl;
                printf ( "0\n" );
            return 0;
        }
    }

    int sum = 0;
    int acc = 0;

    for ( int i = 0; i < n; i++ )
    {
        sum += m[i][i];
    }

    for ( int i = 0; i < n; i++ )
    {

        acc = 0;

        for ( int j = 0; j < n; j++ )
        {
            acc += m[j][i];
        }
        if ( acc != sum )
        {
            magic = false;
            break;
        }
    }

    if ( magic == true )
        //cout << sum;
        printf ( "%d", sum );
    else
        //cout << 0;
        printf ( "0" );

    printf ( "\n" );
    return 0;
}
