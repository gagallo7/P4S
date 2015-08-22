/*
 * =====================================================================================
 *
 *       Filename:  marbles.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/06/2014 10:02:44 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <cmath>

using namespace std;

typedef pair < int, int > ii;

inline ii eucExt ( int a, int b )
{
    if ( b == 0 )
    {
        return ii ( 1, 0 );
    }

    ii u = eucExt ( b, b%a );

    return ii ( u.second, u.first - (a/b)*u.second );
}

int main ()
{
    int n1, n2, c1, c2, C;

    while ( cin >> C )
    {
        if ( C == 0 )
        {
            break;
        }

        cin >> c1 >> n1 >> c2 >> n2;

        const int g = __gcd ( n1, n2 );

        if ( C % g != 0 )
        {
            cout << "failed\n";
            break;
        }

        ii xx = eucExt ( n1, n2 );

        const int tmp = C / g;
        const int x1 = xx.first * tmp;
        const int x2 = xx.second * tmp;


        const int tmp2 = (c2*n1 - c1*n2) / g;
        const int tmp3 = tmp2 * k1;
        const int tmp4 = tmp2 * k2;

        int res = -1;

        for ( int i = -1; i <= 1; ++i )
        {
            int k1 = (x1 + i)*g/n2;
            int k2 = (-x2 + i)*g/n1;



        }

        //int fk = c1*x1 + c2*x2 + min ( tmp3, tmp4 );

        /*
        int a = max ( n1, n2 );
        int b = min ( n1, n2 );

        int c = a / b;
        int d = a % b;

        int v = C % b;
        
        if ( d > 0 )
        {
            if ( v % d != 0 )
            {
            }

            v /= d;
        }

        int u = C / b - v*c;
  */
        cout << u << " " << v << "\n";

        //cout << gcd ( c1, c2 ) << endl;
    }

    return 0;
}
