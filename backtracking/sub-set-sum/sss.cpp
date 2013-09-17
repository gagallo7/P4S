#include <iostream> 
#include <vector>

using namespace std;

void printSol ( vector < int > v ) {
    vector < int >::iterator it;

    for ( it = v.begin(); it != v.end(); it++ ) {
        cout << *it;
    }
}

void back ( vector < int > v, vector < bool > d, int k, int s, int r, int W ) {
    d[k] = true;
    s += v[k];
    r -= v[k];

    if ( s == W ) {
        printSol ( d );
    }

    if ( s + v[k+1] <= W ) {
        back (v, d, s, r, W);
    }
    d[k] = false;
    s -= v[k];
    if ( s + r >= W ) {
        back (v, d, s, e, W);
    }
}


int main () {
    vector < int > v;
    int n, w, sum;

    cin >> n;

    vector < bool > map (n, false);

    for ( int i = 0; i < n; i++ ) {
        cin >> int a;
        v.push_back( a );
        sum += a;
    }

    cin >> w;

    // back ( x1 ... xk-1, k, s, r, W )
    back ( v, map, 0, 0, sum, w );
}
