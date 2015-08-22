#include <iostream>

using namespace std;

int main ()
{
    int A [101][101];
    int xi, xf, yi, yf, n;
    int area=0;


    for ( int i = 0; i < 101; i++ )
    {
        for ( int j = 0; j < 101; j++ )
        {
            A [ i ] [ j ] = 0;
        }
    }

    cin >> n;

    while ( n-- )
    {
        cin >> xi >> xf >> yi >> yf;

        for ( int i = xi; i < xf; i++ )
        {
            for ( int j = yi; j < yf; j++ )
            {
                if ( A[i][j] == 0 )
                {
                    A [ i ] [ j ] = 1;
                    area++;
                }
            }
        }

    }

    cout << area << endl;
    return 0;
}

