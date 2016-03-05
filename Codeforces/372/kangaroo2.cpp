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

int n;
//int x[101];

vector < int > x;

set <int> held;

bool cmp ( const int& a, const int& b )
{
    return a <= b && held.find(b) != held.end();
}

int main ()
{
    scanf ( " %d", &n );

    for ( int i = 0; i < n; ++i )
    {
        //scanf ( " %d", &x[i] );
        int tmp;
        scanf ( " %d", &tmp );
        x.push_back ( tmp );
    }

    sort ( x.begin(), x.end() );

    size_t size = x.size()/2;

    //vector < int > first ( x.begin(), x.begin() + x.size()/2 );
    vector < int > second ( x.begin( ) + size , x.end() );
    vector < int >::iterator fi = x.begin();
    const vector < int >::iterator ff = x.begin() + size;


    //held.resize ( second.size(), false );

    size_t counter = second.size();
    //printf ( "%lu \n", counter );
    while ( fi != ff && counter > 0 )
    {
        const int elem = *fi << 1;
        ++fi;
        //x.erase ( x.begin() );

        const vector < int >::iterator li = lower_bound ( second.begin(), second.end(), elem );

        if ( li != second.end() )
        {
            //second.erase ( li );
            //held [ li - second.begin() ] = true;
            held.insert ( *li );
            //printf ( "%lu\n", li - second.begin() );
            --counter;
        }

    }

    //printf ( "%lu %lu\n", size , counter );
    printf ( "%lu\n", size + counter );

    return 0;
}
