#include <iostream> 
#include <vector>

using namespace std;

void printSol ( vector < bool > v ) {
    vector < bool >::iterator it;

    for ( it = v.begin(); it != v.end(); it++ ) {
        cout << *it;
    }

    cout << endl;
}

void back ( vector < int > v, vector < bool > d, int k, int s, int r, int W ) {
    d[k] = true;
    s += v[k];
    r -= v[k];

    if ( s == W ) {
        printSol ( d );
        return;
    }

    if ( s + v[k+1] <= W ) {
        back (v, d, k+1, s, r, W);
    }
    d[k] = false;
    s -= v[k];
    if ( s + r >= W ) {
        back (v, d, k+1, s, r, W);
    }
}


int main () {
    vector < int > v;
    int n, w, sum;

    cout << "Enter with _n_ values, the _set_ and the _W_..." << endl;

    cin >> n;

    vector < bool > map (n, false);

    for ( int i = 0; i < n; i++ ) {
        int a;
        cin >> a;
        v.push_back( a );
        sum += a;
    }

    cin >> w;

    // back ( x1 ... xk-1, k, s, r, W )
    back ( v, map, 0, 0, sum, w );
}
