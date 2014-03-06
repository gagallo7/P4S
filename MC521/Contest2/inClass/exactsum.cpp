#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector < int > v ( 10000, 1000002 );

int main ()
{
    int n, m;
    int a = -1, b = 1000002;

    while ( scanf ( " %d", &n ) != EOF ) {
        a = -1;
        b = 1000002;

        for ( int i = 0; i < n; i++ )
        {
            scanf ( " %d", &v[i] );
        }

        sort ( v.begin(), v.begin()+n );
/*
        printf ( "\n" );
        for ( int i = 0; i < n; i++ )
        {
            printf ( "%d ", v[i] );
        }


        printf ( "\n\nSorted\n" );
        for ( int i = 0; i < n; i++ )
        {
            printf ( "%d ", v[i] );
        }
        printf ( "\n" );
        */

        scanf ( " %d", &m );

        int ii = 0;
        int k = 0;
        for ( int i = 0; i < n && a < 0; i++ )
        {
            ii = 0;
            k++;
            for ( int j = ii+k; j < n && v[j] + v[ii] <= m ; j++ )
            {
                //printf ( "i+v[j] %d\n", v[i] + v[j] );
                //printf ( "\n %d %d \n", ii, j );
                //if ( v[i] + v[j] == m && v[j]-v[i] < b-a )
                if ( v[ii] + v[j] == m )
                {
                    /*
                    if ( v[i] < v[j] )
                    {
                    }
                    else
                    {
                        b = v[i];
                        a = v[j];
                    }
                    */
                        a = v[ii];
                        b = v[j];
                }
                ii++;

            }
        }
        printf ( "Peter should buy books whose prices are %d and %d.\n\n", a, b );
    }

    return 0;
}

