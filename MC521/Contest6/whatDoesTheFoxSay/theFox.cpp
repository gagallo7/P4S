#include <string>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char str [20000];
char snd [20000];

int main ()
{
    int n;
    
    scanf ( " %d", &n );

    while ( n-- )
    {
        vector < string > sounds;
        scanf ( " %[a-zA-Z ]s", str );
        string all ( str );
        all += " ";
        all = " " + all;

        while ( 1 )
        {
            scanf ( " %[a-zA-Z? ]s\n", snd );
            if ( strncmp ( snd, "what does the fox say?", 21 ) == 0 )
            {
                break;
            }
            
           char* a = strtok ( snd, " " ); 
           a = strtok ( NULL, " " );
           a = strtok ( NULL, " " );

           string s ( a );
           s += " ";
           s = " " + s;
           sounds.push_back ( s );
           //printf ( "%s\n", s.c_str() );
           getchar();
        }

        //printf ( "\n" );
        for ( int i = 0; i < sounds.size(); i++ )
        {
            int j = all.find ( sounds[i] );
            while ( j != string::npos )
            {
                all.erase ( all.begin() + j, all.begin() + j + sounds[i].size() -1 );
                j = all.find ( sounds[i] );
            }
        }

        if ( all.size() > 1 )
        {
            all.erase ( all.begin(), all.begin() + 1 );
            all.erase ( all.end() -1, all.end()  );
        }

        printf ( "%s\n", all.c_str() );
    }

    return 0;
}
