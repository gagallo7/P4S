/*
ID: gagallo1
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np;

    fin >> np;

    unordered_map < string, int > money;
    vector < string > order;

    for ( int i = 0; i < np; ++i )
    {
        string name;
        fin >> name;
        money [ name ] = 0;
        order.push_back ( name );
    }

    while ( !fin.eof() )
    {
        string name;
        int ng, spend;

        fin >> name >> spend >> ng;

        if ( ng > 0 )
        {
            int amount = spend / ng;
            money [ name ] -= spend - spend % ng;

            for ( int i = 0; i < ng; ++i )
            {
                fin >> name;
                money [ name ] += amount;
            }
        }
    }

    for ( auto i : order )
    {
        fout << i << " " << money[i] << endl;
    }
    
    return 0;
}
