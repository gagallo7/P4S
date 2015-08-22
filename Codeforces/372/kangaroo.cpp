/*
 * =====================================================================================
 *
 *       Filename:  foxBox.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/10/2014 11:20:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guilherme Alcarde Gallo (), 
 *   Organization:  UNICAMP
 *
 * =====================================================================================
 */

#include <cstdio>
#include <algorithm>
#include <functional>
#include <set>
#include <vector>

using namespace std;

typedef pair <int,int> ii;
int n;
//int x[101];

vector < ii > x;

set <int> held;

bool cmp ( const ii& a, const ii& b )
{
    //return a <= b && held.find(b) != held.end();
    return a.first < b.first && !b.second;
}

int main ()
{
    scanf ( " %d", &n );

    for ( int i = 0; i < n; ++i )
    {
        //scanf ( " %d", &x[i] );
        int tmp;
        scanf ( " %d", &tmp );
        x.push_back ( ii (tmp, false) );
    }

    sort ( x.begin(), x.end(), cmp );

    size_t size = x.size()/2;

    //vector < int > first ( x.begin(), x.begin() + x.size()/2 );
    vector < ii > second ( x.begin(), x.begin( ) + size );
    vector < ii >::iterator fi = x.begin() + size;
    const vector < ii >::iterator ff = x.end();


    //held.resize ( second.size(), false );

    size_t counter = x.size();
    //printf ( "%lu \n", counter );
    while ( fi != ff && counter >= size )
    {
        const ii elem = ii( (fi->first >> 1) + 1,false);
        ++fi;
        //x.erase ( x.begin() );

        const vector < ii >::iterator li = lower_bound ( second.begin(), second.end(), elem, cmp );

        if ( li != second.end() )
        {
            //second.erase ( li );
            //held [ li - second.begin() ] = true;
            //held.insert ( *li );
            //printf ( "%lu\n", li - second.begin() );
            li->second = true;
            --counter;
        }

    }

    //printf ( "%lu %lu\n", size , counter );
    printf ( "%lu\n", counter );

    return 0;
}
