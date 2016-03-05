/*
 * =====================================================================================
 *
 *       Filename:  shoemaker.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/15/2014 04:38:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guilherme Alcarde Gallo (), 
 *   Organization:  UNICAMP
 *
 * =====================================================================================
 */

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair < int, int > ii;
typedef pair < ii, int > ii3;
typedef vector < ii > vii;

bool comp ( ii3 a, ii3 b )
{
    return a.first.first < b.first.first;
}

bool comp3 ( ii3 a, ii3 b )
{
    return a.first.first * b.first.second < b.first.first * a.first.second;
    //return a.first.first / a.first.second < b.first.first / b.first.second;
}

bool stableComp ( ii3 a, ii3 b )
{
    return (a.first.second - a.first.first) > ( b.first.second - b.first.first );
}

int main ()
{
    int cases;

    
    scanf ( " %d", &cases );

    while ( cases-- > 0 )
    {
        int n;

        scanf ( " %d", &n );

        vector < ii3 > v;
        for ( int i = 1; i <= n; ++i )
        {
            int t, s;
            scanf ( " %d %d", &t, &s );

            v.push_back ( ii3 ( ii ( t, s ), i ) );
        }

        stable_sort ( v.begin(), v.end(), comp3 );
        //stable_sort ( v.begin(), v.end(), stableComp );

        printf ( "%d", v[0].second );
        for ( int i = 1; i < n; ++i )
        {
            printf ( " %d", v[i].second );
        }
        printf ( "\n" );
        if ( cases > 0 )
        {
            printf ( "\n" );
        }
        /*
  */
    }
}
