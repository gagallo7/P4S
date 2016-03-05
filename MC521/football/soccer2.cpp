#include <cstdio>

int v [101];

int main () 
{
    int n, g;
    int s, r;
    int aditional = 0;
    int points = 0;

    while ( scanf ( " %d %d", &n, &g ) == 2 )
    {
        aditional = 0;
        points = 0;
        for ( int i = 0; i < 101; i++ )
        {
            v[i]=0;
        }

        for ( int i = 0; i < n; i++ )
        {
            scanf ( " %d %d", &s, &r );

            int rsaldo = r-s;

            if ( rsaldo < 0 )
            {
                points += 3;
            }

            else if ( rsaldo == 0 )
            {
                points += 1;
            }
            if ( rsaldo >= 0 )
            {
                v [rsaldo]++;
            }
        }

        /*
        for ( int i = 0; i < 101; i++ )
        {
            printf ( "%d ", v[i] );
        }
        printf ( "\n" );
        */

        for ( int i = 0; i < 101 && g; i++ )
        {
            while ( v[i] -- )
            {
                if ( g > i )
                {
                    g -= i+1;
                    aditional += 3;
                    if ( !i )
                        aditional--;
                }
                else if ( g == i )
                {
                    g -= i;
                    aditional += 1;
                }
                if ( g == 0 )
                {
                    break;
                }
            }
        }

        printf ( "%d\n", points+aditional );

    }
    return 0;
}




