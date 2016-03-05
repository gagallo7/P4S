/*
 * =====================================================================================
 *
 *       Filename:  fs.cpp
 *
 *    Description:  Uhul
 *
 *        Version:  1.0
 *        Created:  12/10/2014 12:15:53 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guilherme Alcarde Gallo (), 
 *   Organization:  UNICAMP
 *
 * =====================================================================================
 */

#include <cstdio>
#include <algorithm>    // std::swap

const int MOD = 1000000007;

using namespace std;

void printM ( int m[][3] )
{
    for ( int i = 0; i < 3; ++i )
    {
        for ( int k = 0; k < 3; ++k )
        {
           printf ( "%d ", m[i][k]);
        }
        printf ( "\n" );
    }
    printf ( "\n" );
}

void printV ( const int v2[3] )
{
    printf ( "Array:\n" );
    for ( int i = 0; i < 3; ++i )
    {
           printf ( "%d ", v2[i] );
    }
    printf ( "\n\n" );
}

void mult ( const int m1[][3], const int m2 [][3], int m3[][3])
{
    for ( int i = 0; i < 3; ++i )
    {
        for ( int k = 0; k < 3; ++k )
        {
            m3 [i][k] = 0;
        }
    }
    for ( int i = 0; i < 3; ++i )
    {
        for ( int k = 0; k < 3; ++k )
        {
            for ( int j = 0; j < 3; ++j )
            {
                m3[i][j] += m1[i][k] * m2[k][j] % MOD;
            }
        }
    }
}

void multV ( const int m1[][3], const int m2 [3], int m3 [3])
{
    for ( int i = 0; i < 3; ++i )
    {
        m3 [i] = 0;
    }
    for ( int i = 0; i < 3; ++i )
    {
            for ( int j = 0; j < 3; ++j )
            {
                m3[i] += m1[i][j] * m2[j] % MOD;
            }
    }
}

int main ()
{
    int calcs, N, M;

    int m[3][3];
    int m1[3][3];
    int m2[3][3];

    //int v [3] = { 0, 1, 0 };
    const int V [3] = { 0, 1, 0 };
    int v2 [3];

    for ( int i = 0; i < 3; ++i )
    {
        for ( int k = 0; k < 3; ++k )
        {
            m[i][k] = 0;
            m1[i][k] = 0;
        }
    }
    m [0][1] = 1;
    m [1][1] = 1;
    m [1][0] = 1;
    m [2][1] = 1;
    m [2][2] = 1;

    m1 [0][1] = 1;
    m1 [1][1] = 1;
    m1 [1][0] = 1;
    m1 [2][1] = 1;
    m1 [2][2] = 1;

    int Mold = 1;

    scanf ( " %d", &calcs );

    while ( calcs-- > 0 )
    {
        scanf ( " %d %d", &N, &M );

        int tmpM = M;
        N -= Mold;
        M -= Mold;

        printf ( "N %d M %d\n", N, M);
        int NN = N >> 1;
        int tmp = 0;
        bool change = false;
        while ( NN > 0 )
        {
            mult ( m1, m1, m2 );
            swap ( m1, m2 );
            NN >>= 1;
            ++tmp;
            change = true;
        }

        if ( tmp > 0 )
            tmp = 1 << tmp;
        else
            tmp = 0;

        NN = N - tmp;

        if ( NN-- > 0 )
        {
            change = true;
            mult ( m1, m, m2);
            swap ( m2, m1 );
        }

        int S1;
        if ( change && N > 0 )
        {
            multV ( m1, V, v2 );
            S1 = v2 [2];
            //swap ( v, v2 );
        }
        else
        {
            S1 = V [2];
        }

        printM ( m1 );
        if ( change )
            printV ( v2 );

        NN = M - N;
        while ( NN-- > 0 )
        {
            mult ( m1, m, m2 );
            swap ( m1, m2 );
            change = true;
        }

        printM ( m1 );
        printV ( V );
        multV ( m1, V, v2 );
        int S2 = v2[2];

        printf ( "S1: %d, S2: %d\n", S1, S2 );

        S2 -= S1;
        if ( S2 < 0 )
        {
            S2 = -S2;
        }

        printf ( "Result %d  %d\n\n", S2, S1 );

        Mold = tmpM;
    }

    return 0;
}
