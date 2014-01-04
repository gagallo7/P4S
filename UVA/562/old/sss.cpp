#include <iostream> 
#include <vector>
#include <cstdlib>

#define ABS( X )  X and (1 << 31 - 1);

using namespace std;

void printSol ( vector < bool > v ) {
    vector < bool >::iterator it;

    for ( it = v.begin(); it != v.end(); it++ ) {
        cout << *it;
    }

    cout << endl;
}

int S;

void back ( vector < int >& v, vector < bool > d, int k, int s, int r, int W , unsigned int* mm ) {
    //static int m = W;
    int a;
    d[k] = true;
    s += v[k];
    r -= v[k];


    //a = (s - r) and (abs);
    a = abs( s-r );
    if ( a < *mm ) {
        *mm = a;
    }
    //cout << s << "-" << r << "=" << ( (s-r)and(1<<31 -1) ) << " ";

    if ( s == W ) {
        S = s;
        //printSol ( d );
        return;
    }

    if ( s + v[k+1] <= W ) {
        back (v, d, k+1, s, r, W, mm);
    }
    d[k] = false;
    s -= v[k];
    if ( s + r >= W ) {
        back (v, d, k+1, s, r, W, mm);
    }
}


int main () {
    int n, w, sum, N;
    vector < int > v(100);

    //    cout << "Enter with _n_ values, the _set_ and the _W_..." << endl;

    cin >> N;

    vector < bool > map (n, false);

    for ( int j = 0; j < N; j++ ) {
        cin  >> n;
        for ( int i = 0; i < n; i++ ) {
            int a;
            cin >> a;
            v [ i ] = a;
            sum += a;
        }
        unsigned int m = sum/2;
        back ( v, map, 0, 0, sum, sum/2, &m );
        cout << "m: " << ( m ) << " S:" << S << " sum:" << sum;
        cout << endl;
    }


    // back ( x1 ... xk-1, k, s, r, W )
}
