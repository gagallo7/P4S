#include <iostream>
#include <cstring>

using namespace std;


int achaInicio ( char s[], char t[], int i ) {
	int n = strlen (t);
	int m = strlen (s);

	while ( i < n ) {
		if (s[0] == t[i])
			return i;
		i++;
	}
}

bool subZero ( char s[], char t[] ) {
	int i, j=0, k;
	int n = strlen (t);
	int m = strlen (s);

	for ( i = 0; i < n; i++ ) {
		if ( s[j] == t[i] ) {
			j++;
		}

		if ( j == m ) {
			return true;
		}
	}

	return false;
}


int main () {
	char s[100000], t[100000];

	while ( (cin >> s >> t) ) {

		if ( subZero (s, t) == true ) {
			cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;

	}

	return 0;
}

