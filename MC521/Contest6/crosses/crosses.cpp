#include <cstdio>

char M[100][100];

int draw ( int x, int y )
{
    if ( M[x][y] == '#' &&
            M[x-1][y] == '#' &&
            M[x][y-1] == '#' &&
            M[x+1][y] == '#' &&
            M[x][y+1] == '#'
       )
    {
            M[x-1][y] = '.';
            M[x][y-1] = '.';
            M[x+1][y] = '.';
            M[x][y+1] = '.';
            M[x][y] = '.';

            return 1;
    }

    return 0;
}

int main ()
{
    int n;
    int spots = 0;
    char cell;

    scanf ( " %d", &n );

    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            scanf ( " %c", &cell );
            if ( cell == '#' )
            {
                spots++;
            }
            M[i][j] = cell;
        }
    }

    for ( int i = 1; i < n-1; i++ )
    {
        for ( int j = 1; j < n-1; j++ )
        {
            if ( draw ( i, j ) )
            {
                spots -= 5;
            }
        }
    }

    if ( spots )
    {
        printf ( "NO\n" );
    }
    else
    {
        printf ( "YES\n" );
    }

    return 0;
}
