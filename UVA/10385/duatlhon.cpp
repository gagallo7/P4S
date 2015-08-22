/*
 * =====================================================================================
 *
 *       Filename:  duatlhon.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/15/2014 07:00:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guilherme Alcarde Gallo (), 
 *   Organization:  UNICAMP
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

double vvr [ 21 ];
double vvk [ 21 ];

const double EPS = 10e-7;

double t;
int n;

inline double f ( double r, double vr, double vk )
{
    return r/vr + (t-r)/vk;
}

double ternarySearch ( const double l, const double r, double& M )
{
    if ( fabs ( r - l ) < EPS ) // y1 - y2 > 0
    {
        return (r + l) / 2; 
    }
    //getchar();
    //printf ( "Calling %lf %lf\t", l, r );
    const double m1 = (2*l + r)/3;
    const double m2 = (l + 2*r)/3;

    double fm1 = f ( m1, vvr[n-1], vvk[n-1] );
    double fm2 = f ( m2, vvr[n-1], vvk[n-1] );

    double y1 = +2000000.0;
    double y2 = +2000000.0;
    for ( int i = 0; i < n-1; ++i )
    {
        //printf ( "\n\t(%d)y1 %lf   y2 %lf\n", i, fm1 - f ( m1, vvr[i], vvk[i] ), fm2 - f ( m2, vvr[i], vvk[i] ) );
        y1 = min ( y1, f ( m1, vvr[i], vvk[i] ) - fm1 ); 
        y2 = min ( y2, f ( m2, vvr[i], vvk[i] ) - fm2 ); 
    }

    //printf ( "y1 %lf   y2 %lf  %d\n", y1, y2, (y1 < y2) );

    if ( y1 < y2 )
    {
        M = y1;
        return ternarySearch ( m1, r, M );
    }

    M = y2;
    return ternarySearch ( l, m2, M);
}

int main ()
{

    while ( scanf ( " %lf", &t ) == 1 )
    {

        scanf ( " %d", &n );

        for ( int i = 0; i < n; ++i )
        {
            scanf ( " %lf %lf", &vvr[i], &vvk[i] );
        }

        double M;
        double res = ternarySearch ( 0, t, M);
        if ( M > 0 )
        {
            printf ( "The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", M*3600, res, t-res );
        }
        else
        {
            printf ( "The cheater cannot win.\n" );
        }
        
    }
}
