#include <iostream>
#include <set>
#include <vector>
#include "Instance.h"

using namespace std;

set < int > domain ( vector < int > x, int k, vector < int > V1, vector < int > V2, int** E ) {
    set < int > dom;

    for ( int i = 0; i < V2.size(); i++ ) {
        if ( E [ V1[k] ] [ V2[i] ] ) {
            dom.insert( V2[i] );
        }
    }


    // Removing 'dirty' vertices: already in use
    for ( int i = 0; i < k; i++ ) {
        if ( dom.find( x[i] ) != dom.end() ) {
            dom.erase( x[i] );
        }
    }


    return dom;
}

vector < int > xmax;
int maxx = 0;

void back ( vector < int >& x, int k, vector < int > V1, vector < int > V2, int** E, int s ) {

    if ( k == V1.size() ) {
        if ( s >= maxx ) {
            maxx = s;
            xmax = x;
        }
    }

    set < int > dom;

    dom = domain ( x, k, V1, V2, E );

    set < int >::iterator d;


    for ( d = dom.begin(); d != dom.end(); d++ ) {
        x[k] = *d;
        back ( x, k+1, V1, V2, E, s + E[ V1[k] ] [ *d ]) ;
        
    }
    
//    x[k] = xmax;
}

int main () {
    Instance I;
    I.readInstance();
    vector < int > x (I.numberVertices/2, -1), V1, V2;
    
    int g;
    for ( int i = 0; i < x.size(); i++ ) {
        cin >> g;
        V1.push_back ( g );
    }

    for ( int i = 0; i < I.numberVertices - x.size(); i++ ) {
        cin >> g;
        V2.push_back ( g );
    }

    back ( x, 0, V1, V2, I.adjMatrix, 0 );
    cout << "Sol: " << maxx  << endl;

        cout << "V1: ";
        for ( int i = 0; i < V1.size(); i++ ) {
            cout << V1[i] << " ";
        }
        cout << endl;
        cout << "V2: ";
        for ( int i = 0; i < V1.size(); i++ ) {
            cout << V2[i] << " ";
        }
        cout << endl;
        cout << "xk: ";
        for ( int i = 0; i < V1.size(); i++ ) {
            cout << "(" <<  V1[i] << "," << xmax[i] << ") ";
        }
    
    cout << endl;
}
