#include <cstdio>
#include <cmath>

int hist [1000];
int pos [256][256][256];

int main ()
{
    int x, y, z;
    int old = 11;
    int a = -1, b = -1, c = -1;

    while ( scanf ( " %d %d %d", &x, &y, &z ) == 3 )
    {
        if ( !x && !y && !z )
        {
            break;
        }

        if ( pos[x][y][z]++ > 0 )
        {
            hist[0]++;
        }


        if ( a >= 0 )
        {
            a = x-a;
            b = y-b;
            c = z-c;
            int tmp = a*a + b*b + c*c;

            float f = sqrt (tmp);
            int fi = floor(f);

            if ( fi < old )
            {
                hist [ fi ]++;
            }
            else
            {
                hist [ old ] ++;
            }
            old = fi;
        }

        a = x;
        b = y;
        c = z;
    }

    hist [ old ]++;

    for ( int i = 0; i < 10; i++ )
    {
        printf ( "%4d", hist[i] );
    }
    printf ( "\n" );

    return 0;
}
