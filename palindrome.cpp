/*
 * =====================================================================================
 *
 *       Filename:  palindrome.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/13/2015 12:56:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guilherme Alcarde Gallo (), 
 *   Organization:  UNICAMP
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string s;
    bool palin = true;

    // EOF Loop
    while ( !cin.eof() )
    {
        palin = true;
        cin >> s; 
        size_t i = 0, j = s.size() - 1;

        // Verifying palindrome
        while ( i < j )
        {
            // Mirrored iterator check
            if ( s[i] != s[j] )
            {
                palin = false;
                break;
            }
            --j;
            ++i;
        }
        cout << s << "\t" << (palin? "true" : "false") << palin <<  endl;
    }

    return 0;
}
