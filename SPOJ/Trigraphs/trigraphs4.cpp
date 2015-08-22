/*
 * =====================================================================================
 *
 *       Filename:  trigraphs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/09/2014 07:30:28 PM
 *       Reiision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guilherme Alcarde Gallo (), 
 *   Organization:  UNICAMP
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair < int, int > ii;

class graph 
{
   public:
       graph (size_t N)
       {
            list = vector < vector < long long int > > (N);
       }
       vector < vector < long long int > > list;

       void add ( int i, long long int weight )
       {
           list [ i ].push_back ( weight );
       }

       /*
       void print ()
       {

           for ( auto& a : list )
           {
               for ( auto& b : a )
               {
                   cout << b.second << " ";
               }
               cout << endl;
           }
       }
       */
};

int main ()
{
    int N;
    int testNumber = 0;

    cin >> N;


    while ( N )
    {
        ++testNumber;
        vector < long long int > A (3);
        vector < long long int > A2 (3);

        //cin >> A[0] >> A[1] >> A[2];
        scanf ( " %lli %lli %lli", &A[0], &A[1], &A[2] );

        A[0] = A[1];
        A[2] += A[1];

        for ( int i = 1; i < N; ++i )
        {
            for ( int j = 0; j < 3; ++j )
            {
                A2 [j] = A [j];
            }
            for ( int j = 0; j < 3; ++j )
            {
                long long int w;
                //cin >> w;
                scanf ( " %lli", &w );

                if ( j == 0 )
                {
                    w  += min ( A2[0], A2[1] );
                }
                else if ( j == 1 )
                {
                    const long long int w1  = min ( A2[0], A2[1] );
                    const long long int w2  = min ( A2[2], A[0] );
                    w += min ( w1, w2 );
                }
                else 
                {
                    w += min ( A2[2], 
                            min ( A[1], A2[1] ) );
                }
                A[j] = w;

                //cout << w << " ";
            }
            //cout << endl;
        }

        //cout << testNumber << ". " << A[1] << "\n";
        printf ( "%d. %lli\n", testNumber, A[1] );
        cin >> N;

    }

    return 0;
}
