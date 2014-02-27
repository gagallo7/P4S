#include <iostream>

using namespace std;

int main ()
{
    int v [1000][1000];
    int n, S;
    int gap;
    int diag = 0;

    cin >> n >> S;

    for ( int i = 0; i < n; i++ )
    {
        if ( i&1 ) 
        {
            gap = -i*n;
        }
        else
        {
            gap = i*n;
        }

        for ( int j = 0; j < n; j++)
        {
            v [i][j] = gap + j + 1;
        }
        
        diag += v[i][i];
    }

   //cout << "diag " << diag << endl;

        diag -= S;

        int aux;
        if ( n == 1 )
        {
            aux = 0;
        }
        else if ( n & 1 && diag > 0 )
        {
            aux = n-2;
        }
        else
        {
            aux = n-1;
        }

    for ( int i = 0; i < n; i++ )
    {

        v [aux][i] -= diag;
    }

    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
