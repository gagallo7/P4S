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
#include <list>
#include <vector>

using namespace std;

int n;
//int x[101];

vector < int > x;


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

    int piles = 0;
    while ( x.size() > 0 )
    {
        ++piles;
        int elem = x.front() << 1;
        //x.pop_front();
        x.erase ( x.begin() );
        bool searching = false;

        vector < int >::iterator  li = x.begin();
        do
        {
            searching = false;
            li = find_if ( x.begin(), x.end(), 
                    bind2nd ( greater_equal <int > ( ), elem ) );

            elem += *li;
            if ( li != x.end() )
            {
                searching = true;
                x.erase ( li );
            }
        } while ( searching );

        printf ( "%d (%lu): ", piles, x.size() );
        for ( size_t j = 0; j < x.size(); ++j )
        {
            printf ( "%d ", x[j] );
        }
        printf ( "\n " );
        //printf ( "x.size %u   piles %d\n", (unsigned int)x.size(), piles );
    }

    printf ( "%d\n", piles );

    return 0;
}
