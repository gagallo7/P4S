#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector < int > v;

int main ()
{
    int val, n;
    scanf ( " %d", &n );

    for ( int i = 0; i < n; i++ )
    {
        scanf ( " %d", &val );
        v.push_back (val);
    }

    sort ( v.begin(), v.end() );

    for ( int i = 0; i < v.size(); i++ )
    {
        printf ( "%d\n", v[i] );
    }

    return 0;
}



