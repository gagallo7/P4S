#include <iostream>
#include <list>

using namespace std;

void print ( list < int > l )
{
    for ( auto li = begin(l); li != end(l); li++ )
    {
        cout << *li << " ";
    }
    cout << "\n";
}

int main ()
{
    list < int > l;

    for ( auto i = 1; i < 11; i++ )
    {
        l.push_back ( i );
    }

    print ( l );
    l.push_front ( 0 );
    l.push_back ( 11 );
    print ( l );

    auto li = l.begin();
    for ( auto i = 0; i < 6; i++ ) 
        li++;
    l.insert ( li, 25 );
    print ( l );

    return 0;
}
