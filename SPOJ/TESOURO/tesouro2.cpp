#include <iostream>
#include <climits>
#include <cstdlib>
#include <algorithm>

using namespace std;

int v [101];
//unsigned short int A [100][5000];
bool **A;

bool binBag ( int sum , int n )
{
    // A ( index, size ) returns the value of 
    // the bag with index items and size of size
  //          int a,b;
    bool a, b;

            /*
    for ( int i = 0; i <= n; i++ )
        for ( int j = 0; j <= sum; j++ )
            A[i][j] = 200000;
*/
    for ( int i = 0; i <= sum; i++ )
    {
//        A [0][ i ] = 200000;
        A [0][ i ] = false;
    }

    for ( int i = 0; i <= n; i++ )
    {
        //A [i][0] = 0;
        A [i][0] = true;
        A [i][ v[i] ] = true;
        //A [i][ v[i] ] = v[i];
    }

    //for ( int k = 1; k <= n; k++ )
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= sum; j++ )
        {
    //        cout << "i" <<  i << " j" << j << " A=" << A[i][j] << endl;
            if ( j >= v[i] )
            {
                
     //           cout << "-- a = A[" << i-1 << "][" << j-v[i] << "] + v[" << i << "]" << endl;
      //          cout << "-- " << a << " = " << A[i-1][j-v[i]] << " + " << v[i] << endl;
                
//                a = A[i-1][ j - v[i] ] + v[i];
                a = true & A[i-1][ j - v[i] ];
            }
            else
            {
//                a = 200000;
                a = false;
            }
            b = A[i-1][j];
//            A [i][j] = ( a > b ) ? a : b;
            A[i][j] = (a|b);
            
       //     cout << "i" <<  i << " j" << j << " A=" << A[i][j] << " a " << a << " b " << b << endl;
            
        }
    }

//    cout << endl << endl << A[n][sum] << " sum: " << sum << endl << endl;
        return A[n][sum];

}

int main () {
    int x, y, n;
    int tstNum = 0;
    char poss;

    A = ( bool** ) alloca ( sizeof ( bool* ) * (100+1) );
    for ( int i = 0; i <= 100; i++ )
    {
        A [i] = ( bool* ) alloca ( sizeof ( bool ) * (5000+1) );
    }

    while (1)
    {
        poss = 'S';
        cin >> x >> y >> n;
        if ( !x && !y && !n )
        {
            return 0;
        }
        tstNum++;

        int i = 0;
        int sum = 0;
        int M = ( x < y ) ? y : x;
        int m = ( x < y ) ? x : y;
        for ( i = 1; i < n+1; i++ )
        {
            cin >> v[i];
            sum += v[i];
        }

     //   sort ( v, v + 4*101 );
        sum += x + y;
        

        if ( sum & 1 )
        {
            poss = 'N';
        //    cout << sum << " - " << (sum & 1) << endl;
        }

        sum >>= 1;
        if ( sum  < M )
        {
            poss = 'N';
        }

        if ( sum > M )
        {
            sum -= M;
        }
        else
            sum -= m;
       // cout << "sum3 " << sum << " M " << M << endl;

        bool teste = false;
        if ( poss == 'S' )
        {
            teste = binBag ( sum, n );
        }

        if ( !teste )
        {
            poss = 'N';
        }

        cout << "Teste " << tstNum << endl << poss << endl << endl;
    }

    return 0;
}

