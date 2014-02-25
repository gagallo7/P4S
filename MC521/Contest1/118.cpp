#include <iostream>
#include <string>
#include <cstdio>

char str[150];

using namespace std;

char hash ( char c )
{
		if ( c < 91 )
		{
				return c + 32;
		}
		return c;
}

bool isIn ( char c, char v[] )
{
	for ( int i = 0; i < 12; i++ )
	{
			if ( c == v[i] )
					return true;
	}
	return false;
}
		
int main () {
	char vow[12] = { 'A', 'O', 'Y', 'E', 'U', 'I',
					 'a', 'o', 'y', 'e', 'u', 'i' };
	string s;

	getline ( cin, s );

	
	for ( int i = 0; i < s.size(); i++ )
	{
			if ( isIn ( s[i], vow ) )
			{
					s.erase ( s.begin() + i );
					i--;
			}
	}


	string s2;

	for ( int i = 0; i < s.size(); i++ )
	{
			s2 += '.';
			s2 += hash(s[i]);
	}


	cout << s2;

	cout << endl;

	return 0;
}
