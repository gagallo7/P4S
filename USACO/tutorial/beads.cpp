/*
ID: gagallo1
PROG: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    unsigned int N;

    fin >> N;

    const int total = N;
    int maxB = 0, maxR = 0, ws = 0;
    vector < char > bead;

    ++N;
    while ( --N )
    {
        char curr;
        fin >> curr; 

        bead.push_back ( curr );
        if ( curr == 'b' )
        {
            ++maxB;
        }
        else if ( curr == 'r' )
        {
            ++maxR;
        }
        else
        {
            ++ws;
        }
    }

    bead.insert ( bead.begin(), bead.begin(), bead.end() ); 

    vector < int > countB ( bead.size(), 0 );
    vector < int > countBr ( bead.size(), 0 );
    vector < int > countR ( bead.size(), 0 );
    vector < int > countRr ( bead.size(), 0 );

    for ( size_t curr = 0; curr < bead.size(); ++curr )
    {
        const int prev = curr -1;
        const char& b = bead [ curr ];
        if ( b == 'b' || b == 'w' )
        {
            if ( curr > 0 )
            {
                countB [curr] = countB [prev] + 1;
            }
            else
            {
                countB [curr] = 1;
            }
        }
        else
        {
            countB [curr] = 0;
        }

        if ( b == 'r' || b == 'w' )
        {
            if ( curr > 0 )
            {
                countR [curr] = countR [prev] + 1;
            }
            else
            {
                countR [curr] = 1;
            }
        }
        else
        {
            countR [curr] = 0;
        }
    }

    size_t next = bead.size();
    size_t curr = next-1;
    for ( auto vi = bead.rbegin(); vi != bead.rend(); ++vi )
    {
        const char b = *vi;

        if ( b == 'b' || b == 'w' )
        {
            if ( next < bead.size() )
            {
                countBr [curr] = countBr [next] + 1;
            }
        }
        else
        {
            countBr [curr] = 0;
        }

        if ( b == 'r' || b == 'w' )
        {
            if ( next < bead.size() )
            {
                countRr [curr] = countRr [next] + 1;
            }
        }
        else
        {
            countRr [curr] = 0;
        }
        if ( curr > 0 )
        {
            --curr;
        }
        --next;
    }


    std::transform ( countRr.begin(), countRr.end(), countR.begin(), countRr.begin(), [] (int a, int b) { if ( a > b ) return a; return b; } );
    std::transform ( countBr.begin(), countBr.end(), countB.begin(), countBr.begin(), [] (int a, int b) { if ( a > b ) return a; return b; } );

    /*
    std::ostream_iterator<int> out_it (std::cout," ");
    std::ostream_iterator<char> cout_it (std::cout," ");
    std::copy ( bead.begin(), bead.end(), cout_it );
    cout << endl;
    cout << endl << "B straightforward\n";
    std::copy ( countB.begin(), countB.end(), out_it );
    cout << endl;
    cout << endl;
    std::copy ( countR.begin(), countR.end(), out_it );
    cout << endl;
    cout << endl;
    std::copy ( countBr.begin(), countBr.end(), out_it );
    cout << endl;
    cout << endl;
    std::copy ( countRr.begin(), countRr.end(), out_it );
    cout << endl;
    */

    int counter = max ( countBr[0] + countRr [1], countBr[1] + countRr[0] );
    for ( size_t i = 1; i < bead.size()-1; ++i )
    {
        const int tmp = max ( countBr[i] + countRr [i+1], countBr[i+1] + countRr[i] );
        counter = max ( counter, tmp );
    }

    counter = min ( total, counter );

    fout << counter << endl;

    return 0;
}
