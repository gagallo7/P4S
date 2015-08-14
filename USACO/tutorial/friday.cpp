/*
ID: gagallo1
PROG: friday
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
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
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

                                    // J    F   M  A   M    J  J   A   S    O  N   D
    vector < unsigned int > months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
    vector < unsigned int > days ( 7, 0 );

    unsigned int N;

    fin >> N;

    unsigned int day = 0; // First 13th is on Saturday

    for ( unsigned int year = 0; year < N; ++year )
    {
        unsigned int leap = calcLeap ( 1900 + year );

        unsigned int month = 0;

        while ( month < 12 )
        {
            ++days [ day ];

            int diff = months [ month ] - 28;
            if ( month == 1 ) // Feb
            {
                diff += leap;
            }

            day = ( day + diff ) % 7;
            ++month;
        }
    }

    fout << days [0];
    for ( auto vi = begin ( days ) + 1; vi != end ( days ); ++vi )
    {
        fout << " " << *vi;
    }
    fout << endl;

    return 0;
}
