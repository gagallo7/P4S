#include <cstdio>
#include <cstring>
#include <list>
#include <vector>
#include <string>

using namespace std;

char str [100001];

int main ()
{
    scanf ( " %[a-z]s", str );

    string s ( str );
    string lex;

    for ( char a = 'z'; a >= 'a'; a-- )
    {
        while ( s.find ( a ) != string::npos )
        {
            s.erase ( s.begin(), s.begin() + s.find (a) + 1 );
            lex.push_back ( a );
        }
    }

    printf ( "%s", lex.c_str() );
    printf ( "\n" );

    return 0;
}

