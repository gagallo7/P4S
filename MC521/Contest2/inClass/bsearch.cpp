#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000

using namespace std;

int v [MAX];
vector < int > qv (MAX);
int a   = 0;

int bsearch ( int val, int n )
{
    int b   = n-1;
    int next = (a+b)>>1;

    if ( val > v[b] )
    {
        return -1;
    }

    if ( val < v[0] )
    {
        return -1;
    }

    while ( v [ next ] != val && a != b )
    {
        if ( val > v [ next ] )
        {
            a = next;
        }
        else
        {
            b = next;
        }
        next = ( (a+b)>>1 );
    }

    if ( v [ next ] == val )
    {
        //cout << " " << next << " ";
        while ( v [ --next ] == val )
        {
        }
        return next + 1;
    }

    return -1;
}    


int main ()
{
    int n, q;
        int val;

    scanf ( " %d %d", &n, &q );

  //  printf ( "%d %d\n", n, q );

    for ( int j = 0; j < n; j++ )
    {
        scanf ( " %d", &v[j] );
    }

    for ( int i = 0; i < q; i++ )
    {
        scanf ( " %d", &qv[i] );
//        printf ( "val= %d\n", val );
    }

    for ( int i = 0; i < q; i++ )
    {
        int pos = bsearch ( val, n );

        printf ( "%d\n\n" , pos );
        printf ( "\n a = %d\n" , a );
        if ( pos != -1 )
        {
            a = pos;
        }
    }
    /*
        scanf ( " %d", &val );
        printf ( "%d\n\n", bsearch ( val, n ) );
        */

    return 0;
}
