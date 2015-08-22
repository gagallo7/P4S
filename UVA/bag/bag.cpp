#include <iostream>
#include <vector>

using namespace std;

int bag ( vector < int > T, vector < int > V, int mW ) {
	T.insert(T.begin(), 0);
	V.insert(V.begin(), 0);
	int A[T.size()][mW+1];

	for ( int i = 0; i < mW+1; i++ ) { // walking on weight
		A[0][i] = 0;
	}

	for ( int i = 0; i < T.size(); i++ ) { 
		A[i][0] = 0;
	}

	for ( int i = 1; i < T.size(); i++ ) {
		for ( int j = 0; j < mW+1; j++ ) {
			if ( T[i] < j && A[i-1][j] < A[i-1][j - T[i]] + V[i] ) {
				A[i][j] = A[i-1][j - T[i]] + V[i];
			}
			else {
				A[i][j] = A[i-1][j];
			}
		}
	}

	/*
	*/
	for ( int i = 1; i < T.size(); i++ ) {
		for ( int j = 0; j <= mW; j++ ) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	return A[T.size()-1][mW];

}

int main () {
	int t, n, p, w, numF, mW;

	cin >> t;

	for ( int h = 0; h < t; h++ ) {
		int acc = 0;
		vector < int > T, V;
		cin >> n;

		for ( int i = 0; i < n; i++ ) {
			cin >> p >> w;
			T.push_back ( w );
			V.push_back ( p ); 
		}

		/*
		cout << "T:";
		for ( int i = 0; i < T.size(); i++ ) {
			cout << T[i] << " ";
		}

		cout << endl;

		cout << "V:";
		for ( int i = 0; i < V.size(); i++ ) {
			cout << V[i] << " ";
		}
		cout << endl;
		cout << endl;
		*/


		cin >> numF;

		for ( int k=0; k < numF; k++ ) {
			cin >> mW;
			acc += bag (T, V, mW);
		}

		cout << acc << endl;
	}

	return 0;
}
