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

        for ( int j = 0; j < 3; ++j )
        {
            int w;
            cin >> w;
            g.add ( 0, j, w );
        }
        A[1][0] = g.list[0][1].second;
        A[1][1] = g.list[0][1].second;
        A[1][2] = A[1][1] + g.list[0][2].second;
        for ( int i = 1; i < N; ++i )
        {
            for ( int j = 0; j < 3; ++j )
            {
                int w;
                cin >> w;
                g.add ( i, j, w );
            }
            A [ i+1 ] [ 1 ] = min ( min ( g.list[i][0].second, g.list[i][1].second), g.list[i][2].second )  + A [i][1];
        }


        cout << testNumber << ". " << A[N][1] << "\n";
        cin >> N;

    }

    return 0;
}
