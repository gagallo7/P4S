#include <cstdio>

void search ( int a, int b )
{
    double f = (double)a/b;
    double lm = 0;
    double ln = 1;
    double rm = 1;
    double rn = 0;
    double m = 1, n = 1;
    double val = 1.0;

    while ( 1 )
    {
        if ( f > val )
        {
            lm = m;
            ln = n;
            m += rm;
            n += rn;

            val = m/n;
            printf ( "R" );
        }
        else if ( f < val )
        {
            rm = m;
            rn = n;
            m += lm;
            n += ln;

            val = m/n;
            printf ( "L" );
        }
        else
        {
            printf ( "\n" );
            return;
        }
    }
}
            
    

int main ()
{
    int a, b;

    while ( scanf ( " %d %d", &a, &b ) == 2 )
    {
        if ( a == 1 && b == 1 )
        {
            return 0;
        }

        search ( a, b );
    }

    return 0;
}
