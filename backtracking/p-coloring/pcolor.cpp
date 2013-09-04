#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void printSol ( vector < int >& sol ) {
    for ( int i = 0; i < sol.size(); i++ ) {
        cout << sol [i] << " ";
    }
    cout << endl;
}

void readGraph ( vector < vector < int > >& adj ) {
    int n, m;
    cin >> n >> m;

    for ( int i = 0; i < n; i++ ) {
        vector < int > v (n);
        adj.push_back(v);
    }

    for ( int i = 0; i < m; i++ ) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1; // Non-directed
    }

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}


void viability ( int k, vector < int >& x, vector < int >& cor, int p, vector < vector < int > > adj ) {
    for (int i = 0; i < p; i++ ) {
        cor[i] = 1;
    }

    for (int i = 0; i < k; i++) {
        if (adj[k][i] == 1) {
            cor[ x[i] ] = 0;
        }
    }
}

void backTrack ( int k, vector < int >& x, vector < int >& cor, int n, int p, vector < vector < int > > adj ) {
   viability ( k, x, cor, p, adj );

   for ( int i = 0; i < p; i++ ) {
       if ( cor[i] == 1 ) {
           x[k] = i;
       }
   }
    
   if ( k == n-1 ) {
       printSol ( x );
   }
   else

   backTrack ( k + 1, x, cor, n, p, adj );
}

int main (int argc, char *argv[]) {
    
    if (argc != 3) {
         cout << "Check the args!" << endl;
         exit(1);
    }

    int n = atoi(argv[1]); 
    int p = atoi(argv[2]);

    vector < int > x (n);
    vector < int > cor (p);
    vector < vector < int > > adj;

    readGraph(adj);

    backTrack (0, x, cor, n, p, adj);

    return 0;
}
