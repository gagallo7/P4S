#include <iostream>
#include <cstdio>
#include <cstring>

#define SIZE 102

using namespace std;

char v[102][102];
char num[SIZE][SIZE];

void printM ( char m[SIZE][SIZE] )
{
        for ( int y = 1; y <= SIZE; ++y )
        {
            for ( int x = 1; x <= SIZE; ++x )
            {
                if ( m[y][x] < 0 )
                {
                    printf ( "*" );
                }
                else
                {
                    printf ( "%d", m[y][x] );
                }
            }
            printf ( "\n" );
        }
}


int main() {
    int m, n, field = 0;

    scanf(" %d %d", &m, &n);
    while ( m || n )
    {
        memset ( num, 0, SIZE*SIZE*sizeof(char) );
        if ( field )
        {
            printf ( "\n" );
        }
        printf ( "Field #%d:\n", ++field );
            for ( int x = 1; x <= n; ++x )
        {
        for ( int y = 1; y <= m; ++y )
            {
                char c;
                //scanf (" %c", &v[y][x]);
                scanf ( " %c", &c );
                if ( c == '*' )
                {
                    num[y][x] = -9;
                    ++num[y-1][x-1];
                    ++num[y-1][x];
                    ++num[y-1][x+1];
                    ++num[y][x-1];
                    ++num[y][x+1];
                    ++num[y+1][x-1];
                    ++num[y+1][x];
                    ++num[y+1][x+1];
                }
            }
        }
            for ( int x = 1; x <= n; ++x )
        {
        for ( int y = 1; y <= m; ++y )
            {
                if ( num[y][x] < 0 )
                {
                    printf ( "*" );
                }
                else
                {
                    printf ( "%d", num[y][x] );
                }
            }
            printf ("\n");
        }
        scanf(" %d %d", &m, &n);
    }
    return 0;
}
