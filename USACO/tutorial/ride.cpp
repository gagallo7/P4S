/*
ID: gagallo1
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const unsigned int A = static_cast < unsigned int > ( 'A' ) -1;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    
    unsigned int modA = a[0]-A, modB = b[0]-A;
    for ( int i = 1; i < a.size(); ++i )
    {
        modA *= static_cast<unsigned int>(a[i]) - A;
    }

    for ( int i = 1; i < b.size(); ++i )
    {
        modB *= static_cast<unsigned int>(b[i]) - A;
    }

    modA %= 47;
    modB %= 47;

    if ( modA == modB )
    {
        fout << "GO" << endl;
    }
    else
    {
        fout << "STAY" << endl;
    }

    return 0;
}
