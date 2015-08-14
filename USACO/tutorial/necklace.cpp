/*
ID: gagallo1
PROG: friday
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

unsigned int calcLeap ( unsigned int year )
{
    if ( year % 100 == 0 )
    {
        if ( year % 400 == 0 )
        {
            return 1;
        }
        return 0;
    }

    if ( year % 4 == 0 )
    {
        return 1;
    }
    return 0;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    unsigned int N;

    fin >> N;

    vector < pair < char, int > > veq;
    list < pair < char, int > > seq;
    list < pair < char, int > > seq2;
    vector < int > res;

    char last = 0;
    char curr;

    ++N;
    while ( --N )
    {
        fin >> curr; 

        if ( last != curr )
        {
            last = curr;
            veq.push_back ( make_pair ( curr, 1 ) );
        }
        else
        {
            ++veq.back().second;
        }
    }

    if ( veq.size() == 1 )
    {
        fout << veq.front().second << endl;
        return 0;
    }

    for ( auto s : veq )
    {
        cout << s.first ;
    }
    cout << endl;
    for ( auto s : veq )
    {
        cout << s.second;
    }

    cout << endl;
    /*
    // First bead is 'w' case
    if ( seq.front().first == 'w' )
    {
        seq[1].second += seq.front().second;
        if ( seq.back().first != 'w' )
            seq.back().second += seq.front().second;
        seq.pop_front();
    }

    // Last bead is 'w' case
    if ( seq.back().first == 'w' )
    {
        seq[seq.size()-1].second += seq.back().second;
        seq.front().second += seq.back().second;
        seq.pop_back();
    }

    // First and Last beads have same color case
    if ( seq.front().first == seq.back().first )
    {
        seq.front().second += seq.back().second;
        seq.back().second += seq.front().second;
    }
  */


    seq.insert ( seq.end(), begin ( veq ) + veq.size()/2, end ( veq ) );
    seq.insert ( seq.end(), begin ( veq ) , begin ( veq ) + veq.size() /2 );

    if ( seq.front().first == 'w' )
    {
        auto li = begin ( seq );
        ++li;
        li->second += seq.front().second;
        seq.erase ( begin ( seq ));
    }
    for ( auto s : seq )
    {
        cout << s.first << "(" << s.second << ") ";
    }

    cout << endl;
    cout << endl;

    auto itEnd = prev ( seq.end() );

    // removing ww
    auto li = begin ( seq );
    for ( ; li != itEnd; ++li )
    {
        auto nx = li;
        ++nx;
        
        if ( nx->first == li->first )
        {
            seq2.push_back ( make_pair ( nx->first, nx->second + li->second ) );
            if ( li != itEnd )
                ++li;
        }
        else
        { 
            seq2.push_back ( *li );
        }
    }
    if ( li != seq.end() )
        seq2.push_back ( *li );

    for ( auto s : seq2 )
    {
        cout << s.first ;
    }
    cout << endl;
    for ( auto s : seq2 )
    {
        cout << s.second;
    }
    
    // Grouping
    li = begin ( seq2 );
    for ( ; li != seq2.end(); ++li )
    {
        char& now = li->first;
        auto pv = li;
        auto nx = li;
        --pv;
        ++nx;

        if ( now == 'w' )
        {
            if ( pv != seq2.end() )
                pv->second += li->second;
            if ( nx != seq2.end() )
                nx->second += li->second;
            if ( nx->first == pv->first )
            {
                pv->second -= li->second;
            }
            li = seq2.erase ( li );
        }
    }

    cout << endl;
    cout << endl;

    for ( auto s : seq2 )
    {
        cout << s.first ;
    }
    cout << endl;
    for ( auto s : seq2 )
    {
        cout << s.second;
    }

    itEnd = prev ( seq2.end() );
    li = begin ( seq2 );
    for ( ; li != itEnd; ++li )
    {
        auto nx = li;
        ++nx;
        
        while ( nx->first == li->first )
        {
            nx->second += li->second;
            li = seq2.erase ( li );
            nx = li;
            ++nx;
        }
    }

    cout << endl;
    cout << endl;

    for ( auto s : seq2 )
    {
        cout << s.first ;
    }
    cout << endl;
    for ( auto s : seq2 )
    {
        cout << s.second;
    }

    if ( seq2.size() == 1 )
    {
        fout << seq2.front().second << endl;
        return 0;
    }

    int beads = 0;
    li = begin ( seq2 );
    for ( ; li != itEnd; ++li )
    {
        auto nx = li;
        ++nx;
        int n = li->second + nx->second;
        beads = max ( n, beads );
    }

    cout << endl;
    fout << beads << endl;

    return 0;
}
