#include <iostream>

using namespace std;

int m [1000][1000];
int v [1000], h [1000];

int sumRes ( int sum, int n )
{
    int acc;
    int max = n*n;
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n /*&& v[i] < sum && h[i] < sum*/ && m[i][j] <= max; j++ )
        {
            //acc += m[i][j];
            v[i] += m[i][j];
            v[i] ^= m[j][i];
        }
        /*
        if ( acc != sum )
        {
            return 0;
        }

        acc = 0;
*/
        /*
        for ( int j = 0; j < n && acc < sum && m[i][j] <= max; j++ )
        {
            acc += m[j][i];
        }
        if ( acc != sum )
        {
            return 0;
        }
        */
        if ( !v[i] )
        {
            return 0;
        }
    }


    return sum;
}
    
int main ()
{
    int n;

    cin >> n;

    for ( int i = 0; i < n; i++ )
    {
        v[i] = 0;
        h[i] = 0;
        for ( int j = 0; j < n; j++ )
        {
            cin >> m [i][j];
        }
    }

    int sum = 0;
    int max = n*n;

    for ( int i = 0; i < n; i++ )
    {
        if ( m[i][i] > max )
        {
            cout << 0;
            return 0;
        }
        sum += m[i][i];
    }

    /*
       for ( int i = 0; i < n; i++ )
       {
       acc += m[i][n-1-i];
       }
       */

    cout << sumRes ( sum, n );

    cout << endl;

    return 0;
}
