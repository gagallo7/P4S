#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

char s [201];


int main ()
{
    int n;
    int sN = 0;
    int j;
    long conv, max = 0;
    long acc;
    long verf;

    scanf ( " %d", &n );

    while ( n-- )
    {
        scanf ( " %s", s );

        acc = 0;

        string ss ( s );

        max = 0;
        j = 0;

        while ( ss.size() > 10 )
        {
            sN = ss.size();
            max = 0;
            j = 0;

            //printf ( "sN = %d\n", sN );

            for ( int i = 0; i < sN - 10; i++ )
            {
                string s2 ( ss.begin() + i, ss.begin() + i + 10 );
                conv = atoi ( s2.c_str() );
                if ( max < conv )
                {
                    max = conv;
                    j = i;
                }
            }

            acc += max;

            string s2 ( ss.begin() + j, ss.begin() + j + 10 );
            //printf ( "%d\n", atoi ( s2.c_str () ) );

            ss.erase ( ss.begin() + j, ss.begin() + j + 10 );

            if ( j < 10 )
            {
                string s3 ( ss.begin(), ss. begin() + j );
                acc += atoi ( s3.c_str() );
                ss.erase ( ss.begin(), ss.begin() + j );
            }
        }

        verf = atol ( ss.c_str() );

        if ( verf > INT_MAX )
        {
            max = 0;
            j = 0;
            for ( int i = 0; i < 2; i++ )
            {
                string s2 ( ss.begin() + i, ss.begin() + i + 9 );
                conv = atoi ( s2.c_str() );
                if ( max < conv )
                {
                    max = conv;
                    j = i;
                }
            }

            acc += max;

            string s2 ( ss.begin() + j, ss.begin() + j + 9 );
            //printf ( "j=%d  %d\n", j, atoi ( s2.c_str () ) );

            ss.erase ( ss.begin() + j, ss.begin() + j + 9 );

            if ( j < 10 )
            {
                string s3 ( ss.begin(), ss. begin() + j );
                acc += atoi ( s3.c_str() );
                ss.erase ( ss.begin(), ss.begin() + j );
            }
        }

        if ( ss.size () )
        {
            acc += atoi ( ss.c_str() );
        }

        printf ( "%li\n", acc );
    }

    return 0;
}
