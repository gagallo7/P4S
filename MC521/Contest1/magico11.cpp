#include <iostream>

using namespace std;

int main ()
{
		int m [1000][1000];
		int n;
		bool magic = true;

		cin >> n;

		for ( int i = 0; i < n; i++ )
		{
				for ( int j = 0; j < n; j++ )
				{
						cin >> m [i][j];
				}
		}

		int sum = 0;
		int acc = 0;

		for ( int i = 0; i < n; i++ )
		{
				sum += m[i][i];
		}

		/*
		for ( int i = 0; i < n; i++ )
		{
				acc += m[i][n-1-i];
		}
		*/

		if ( acc != sum )
		{
				magic = false;
		}
		

		for ( int i = 0; i < n && magic; i++ )
		{
				acc = 0;
				for ( int j = 0; j < n; j++ )
				{
						acc += m[i][j];
				}
				if ( acc != sum )
				{
						magic = false;
						break;
				}

				acc = 0;

				for ( int j = 0; j < n; j++ )
				{
						acc += m[j][i];
				}
				if ( acc != sum )
				{
						magic = false;
						break;
				}
		}

		if ( magic == true )
				cout << sum;
		else
				cout << 0;

		cout << endl;

		return 0;
}
