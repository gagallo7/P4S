#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int hash ( char c )
{
		return ( c % 65 );
}

void addReverse ( string& s, char c, char r )
{
		s[ hash(c) ] = r;
		s[ hash(r) ] = c;
}

int main ()
{
		string reverse ( 65, '-' );
		string s, s1;

		addReverse ( reverse,  'A', 'A' );
		addReverse ( reverse,  'E', '3' );
		addReverse ( reverse,  'H', 'H' );
		addReverse ( reverse,  'I', 'I' );
		addReverse ( reverse,  'J', 'L' );
		addReverse ( reverse,  'M', 'M' );
		addReverse ( reverse,  'O', 'O' );
//		addReverse ( reverse,  'O', '0' );
//		addReverse ( reverse,  '0', '0' );
		addReverse ( reverse,  'S', '2' );
		addReverse ( reverse,  'T', 'T' );
		addReverse ( reverse,  'U', 'U' );
		addReverse ( reverse,  'V', 'V' );
		addReverse ( reverse,  'W', 'W' );
		addReverse ( reverse,  'Y', 'Y' );
		addReverse ( reverse,  'Z', '5' );
		addReverse ( reverse,  '1', '1' );
		addReverse ( reverse,  '8', '8' );


		bool palindrome = true, reversal = true;
		getline ( cin, s );
		while ( s.size() )
	//	while ( scanf ( " %s", s ) == 1 )
		{
				if ( s[s.size()-1] == 32)
				{
						s1 = string ( s, 0, s.size()-1 );
				}
				else
						s1 = s;
			//	cout << "end:" << (int)s1[s1.size()-1] << ":" << endl;
				palindrome = true;
				reversal = true;

				for ( int i = 0; i < s1.size()/2; i++)
				{
				//	cout << s1[i] << " " << s1[s1.size()-1-i] << " ---> " << 
				//				(s1[i]!=s[s1.size()-1-i]) << endl;
						if ( s1[i] != s1 [ s1.size()-1 - i ] )
						{
								palindrome = false;
						}
						if ( reverse[ hash(s1[i]) ] != s1 [ s1.size()-1 - i ] )
						{
				//				cout << reverse [ hash (s[i]) ] << " " <<
				//						s [ s.size()-1 - i ] << endl;
								reversal = false;
						}
				}

				int t = s.size()  ;
				if ( t & 1 )
				{
						if ( reverse [ hash( s1 [t/2] ) ] != s1 [ t/2 ] )
						{
				
						reversal = false;
				
						}
				}
						


				if ( palindrome && reversal )
				{
						cout << s1 + " -- is a mirrored palindrome.";
				}
				else if ( palindrome )
				{
						cout << s1 + " -- is a regular palindrome.";
				}
				else if ( reversal )
				{
						cout << s1 + " -- is a mirrored string.";
				}
				else 
				{
						cout << s1 + " -- is not a palindrome.";
				}
				cout << endl;
				cout << endl;
				getline ( cin, s );
		}


		return 0;
}


