/*
 * =====================================================================================
 *
 *       Filename:  wavio.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/15/2014 09:49:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guilherme Alcarde Gallo (), 
 *   Organization:  UNICAMP
 *
 * =====================================================================================
 */


#include <cstdio>
#include <iostream>

using namespace std;

int v [ 10001 ];
int main ()
{
    int n;

    while ( scanf ( " %d", &n ) == 1 )
    {
        for ( int i = 0; i < n; ++i )
        {
            scanf ( " %d", &v[i] );
        }

        int inc = 0;
        int dec = 0;
        int maxDec = 0;
        int maxInc = 0;

        for ( int i = 1; i < n; ++i )
        {
            if ( v[i-1] < v[i] )
            {
                ++inc;
                maxInc = max ( inc, maxInc );
            }
            else
            {
                inc = 0;
            }
            /*
  */
            if ( v[n-i] < v [n-i-1] )
            {
                ++dec;
                maxDec = max ( maxDec, dec );
            }
            else
            {
                dec = 0;
            }
            /*
  */
        }

        printf ( "%d %d\n", dec, inc );
        inc = min ( inc, dec );

        printf ( "%d\n", ( inc << 1 ) + 1 );
    }

    return 0;
}
