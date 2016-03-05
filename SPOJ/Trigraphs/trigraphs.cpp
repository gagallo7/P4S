/*
 * =====================================================================================
 *
 *       Filename:  trigraphs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/09/2014 07:30:28 PM
 *       Revision:  none
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

typedef pair < vector < int >, int > vi;

class graph 
{
   public:
       graph (size_t N)
       {
            A = vector < vector < int > > (N+1);
            for ( size_t i = 0; i <= N; ++i )
            {
                A [i] = vector < int > (3, 0);
            }

            list = vector < vector < vi > > (N);
       }
       vector < vector < vi > > list;
       vector < vector < int > > A;

       void add ( int i, int j, int weight )
       {
           vector < int > adj;
           switch ( j )
           {
                case (0):
                    adj.push_back ( 0 );
                    adj.push_back ( 1 );
                    break;
                case (1):
                    adj.push_back ( 0 );
                    adj.push_back ( 1 );
                    adj.push_back ( 2 );
                    adj.push_back ( 3 );
                    break;
                case (2):
                    adj.push_back ( 1 );
                    adj.push_back ( 2 );
                    adj.push_back ( 4 );
                    break;
           }
           list [ i ].push_back( vi ( adj, weight ));
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

        vector < vector < int > >& A = g.A;

        for ( int i = 0; i < N; ++i )
        {
            for ( int j = 0; j < 3; ++j )
            {
                int w;
                cin >> w;
                g.add ( i, j, w );
            }
        }

        // DP
    
        A[1][0] = g.list [0][1].second;
        A[1][1] = g.list [0][1].second;
        A[1][2] = g.list [0][1].second + g.list [0][2].second;
        for ( int a = 2; a <= N; ++a )
        {
            for ( int j = 0; j < 3; ++j )
            {
                vi& Cij = g.list [a-1][j];
                int Apast = A[a-1][Cij.first[0]];
                for ( size_t k = 1; k < Cij.first.size(); ++k )
                {
                    int factor = 1 - Cij.first[k] / 3;
                    int mod = Cij.first[k] % 3;
                    Apast = min ( Apast, A[a-factor][mod] );
                }
                //cout << Apast << endl;
                A [a][j] = Apast + Cij.second;
            }
        }

        cout << testNumber << ". " << A[N][1] << "\n";
        cin >> N;

    }

    return 0;
}
