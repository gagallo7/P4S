#include <cstdio>

int main ()
{
    int k;
    int n;
    int N;

    scanf ( " %d", &n );

    while ( n-- )
    {
        scanf ( " %d", &k );
        
            N = 0;
            
            while ( k-- )
            {
                N = N*2 + 1;
            }

            printf ( "%d\n", N );
    }

    return 0;
}
