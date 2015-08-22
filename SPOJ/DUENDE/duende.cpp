/*
 * =====================================================================================
 *
 *       Filename:  duende.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/06/2014 10:56:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>

using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iil;

int main ()
{

    int ** a = new int *[12];

    for ( int i = 0; i < 12; ++i )
    {
        a [i] = new int [12];
    }


    int M, N;
    ii s;

    cin >> M >> N;

    for ( int i = 0; i < 12; ++i )
    {
        a [i][0] = 2;
        a [0][i] = 2;
        a [i][N+1] = 2;
        a [M+1][i] = 2;
    }

    for ( int i = 1; i <= M; ++i )
    {
        for ( int j = 1; j <= N; ++j )
        {
            cin >> a [i][j];
            if ( a [i][j] == 3 )
            {
                s = make_pair ( i, j );
            }
        }
    }

    for ( int i = 0; i < 12; ++i )
    {
        for ( int j = 0; j < 12; ++j )
        {
//            cout << a [i][j];
        }
//        cout << endl;
    }
    queue < iil > q;
    int length = 0;

    q.push ( make_pair (s, 0) );

//        cout << endl;
    while ( q.empty() == false )
    {
        ii p = q.front().first;
        int l = q.front().second;
        q.pop();


        if ( a [p.first][p.second] == 0 )
        {
            length = l;
            break;
        }

//        cout << p.first << ", " << p.second << endl;
        a [p.first][p.second] = 2;

        --p.first;
        if ( a [p.first][p.second] < 2 )
        q.push ( make_pair ( p, l+1 ) );
        p.first += 2;

        if ( a [p.first][p.second] < 2 )
        q.push ( make_pair ( p, l+1 ) );
        --p.first;
        --p.second;

        if ( a [p.first][p.second] < 2 )
        q.push ( make_pair ( p, l+1 ) );
        p.second += 2;

        if ( a [p.first][p.second] < 2 )
        q.push ( make_pair ( p, l+1 ) );
        
    }

    cout << length << endl;

    return 0;
}
