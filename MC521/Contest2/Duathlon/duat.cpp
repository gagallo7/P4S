#include <cstdio>

int main ()
{
    int n;
    double t;
    double a, b;
    double accA = 0, accB = 0;
    
    scanf ( " %lf", &t );
    scanf ( " %d", &n );

    for ( int i = 0; i < n-1; i++ )
    {
        scanf ( " %lf %lf", &a, &b );
        accA -= 1.0/a;
        accB -= 1.0/b;
    }

    scanf ( " %lf %lf", &a, &b );
    accA += 1.0/a;
    accB += 1.0/b;

    printf ( "accA:%lf   accB:%lf\n", accA, accB );
    
    double max;
    double x = accA/accB;
    double y = accB/accA;

    if ( y > 1 )
    {
        max = y+1;
    }
    else
    {
        max = x+1;
    }

    printf ( "x:%lf   y:%lf\n", x, y );
    double parts = t/(max);

    printf ( "%lf %lf\n", x*parts, y*parts );

    return 0;
}
