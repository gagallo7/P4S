#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000

using namespace std;

int v [MAX];
vector < vector < int > > qv;
int a   = 0;
int b;

int bsearch ( int val, int n )
{

    if ( val > v[b] )
    {
        return -1;
    }

    if ( val < v[0] )
    {
        return -1;
    }

    if ( val == v[0] )
        return 0;

    if ( val == v[n-1] )
        return n-1;

    int next = (a+b)>>1;

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

bool comp ( vector < int > a, vector < int > b )
{
    return ( a[1] < b[1] );
}

bool comp2 ( vector < int > a, vector < int > b )
{
    return ( a[0] < b[0] );
}

int main ()
{
    int n, q;
        int val;

    scanf ( " %d %d", &n, &q );

    b = n-1;

  //  printf ( "%d %d\n", n, q );

    for ( int j = 0; j < n; j++ )
    {
        scanf ( " %d", &v[j] );
    }

    /*
*/
    for ( int i = 0; i < q; i++ )
    {
        int aux;
        scanf ( " %d", &aux );
        vector < int > auxv;
        auxv.push_back ( i );
        auxv.push_back ( aux );
        qv.push_back ( auxv );
//        printf ( "val= %d\n", val );
    }


    make_heap ( qv.begin(), qv.end(), comp );

    int pos = n-1;
    for ( int i = 0; i < q; i++ )
    {
        //printf ( "%d\n", qv[0].at(1) );
        pos = bsearch ( qv[0].at(1), n );
        //printf ( "b = %d  pos%d %d\n", b, qv[0].at(1), pos );
        qv[0][1] = pos;
        pop_heap ( qv.begin(), qv.end()-i, comp );

        if ( pos >= 0 )
        {
            b = pos;
        }

    }

    sort ( qv.begin(), qv.end(), comp2 );

    for ( int i = 0; i < q; i++ )
    {
        printf ( "%d\n\n", qv[i].at(1) );
    }

/*
    int old = 2000000000;
    for ( int i = 0; i < q; i++ )
    {
        scanf ( " %d", &val );
        if ( val < old )
        {
            a = 0;
            if ( pos >= 0 )
                b = pos;
        }
        else if ( val > old )
        {
            if ( pos >= 0 )
                a = pos;
            b = n-1;
        }
        else
        {
            printf ( "%d\n\n" , pos );
            continue;
        }


        pos = bsearch ( val, n );
        printf ( "%d\n\n" , pos );
        
        old = val;
    }
    */
    /*
        scanf ( " %d", &val );
        printf ( "%d\n\n", bsearch ( val, n ) );
        */

    return 0;
}
