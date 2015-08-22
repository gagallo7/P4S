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
        graph g (N) ;

        vector < vector < long long int > >& A = g.list;

        for ( int j = 0; j < 3; ++j )
        {
            long long int w;
            cin >> w;
            g.add ( 0, w );
        }
        A[0][0] = A[0][1];
        A[0][2] += A[0][1];

        for ( int i = 1; i < N; ++i )
        {
            for ( int j = 0; j < 3; ++j )
            {
                long long int w;
                cin >> w;

                if ( j == 0 )
                {
                    w  += min ( A[i-1][0], A[i-1][1] );
                }
                else if ( j == 1 )
                {
                    const long long int w1  = min ( A[i-1][0], A[i-1][1] );
                    const long long int w2  = min ( A[i-1][2], A[i][0] );
                    w += min ( w1, w2 );
                }
                else 
                {
                    w += min ( A[i-1][2], 
                            min ( A[i][1], A[i-1][1] ) );
                }
                g.add ( i, w );

                //cout << w << " ";
            }
            //cout << endl;
        }

        cout << testNumber << ". " << A[N-1][1] << "\n";
        cin >> N;

    }

    return 0;
}
