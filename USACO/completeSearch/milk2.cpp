/*
ID: gagallo1
PROG: milk2
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

typedef pair < unsigned int, unsigned int > uiui;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2b.in");

    unsigned int N;

    fin >> N;

    const unsigned int total = N;
    vector < uiui > times;

    ++N;
    while ( --N )
    {
        unsigned int st, end;
        fin >> st >> end; 

        times.push_back ( make_pair ( st, end ) );
    }

    sort ( begin ( times ), end ( times ) );

    unsigned int accTime = times[0].second - times[0].first;
    unsigned int maxAcc = accTime;
    unsigned int idleTime = 0;
    unsigned int latest = times[0].second;
    for ( size_t i = 0; i < total-1; ++i )
    {
        cout << "acc: " << accTime << endl;
        if ( latest >= times[i+1].first )
        {
            cout << "hey" << endl;
            accTime += times[i+1].second - times[i].second;
        }
        else
        {
            cout << "ho" << endl;
            maxAcc = max ( maxAcc, accTime );
            idleTime = max ( idleTime, times [i+1].first - times[i].second );
            accTime = times[i+1].second - times[i+1].first;
        }
        latest = max ( latest, times[i].second );
    }
    maxAcc = max ( maxAcc, accTime );

    for ( auto& t : times )
    {
        cout << t.first << " " << t.second << endl;
    }
    cout << endl;

    /*
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


    fout << maxAcc << " " << idleTime << endl;

    return 0;
}
