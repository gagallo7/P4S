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
    while ( x.size() - piles > 0 )
    {
        int size = 0;
        //int elem = x.front();
        //x.pop_front();
        //x.erase ( x.begin() );

        while ( true )
        {
            vector < int >::iterator li = find_if ( x.begin()+1+piles, x.end(), 
                    bind2nd ( greater <int > ( ), size ) );

            if ( li == x.end() )
            {
                ++piles;
                break;
            }
            else
            {
                x.erase ( li );
                ++size;
            }
        //printf ( "x.size %u   piles %d\n", (unsigned int)x.size(), piles );
        }
    }

    printf ( "%d\n", piles );

    return 0;
}
