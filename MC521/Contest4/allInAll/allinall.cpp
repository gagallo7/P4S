#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

char a[1000000], b[1000000];
int main ()
{
    int i, j;

    while ( scanf ( " %s %s", a, b ) != EOF )
    {
        i = 0;
        j = 0;

        while ( b[j] && a[i] )
        {
            if ( a[i] == b[j] )
             {
                 i++;
             }
            j++;
        }

        if ( a[i] == 0 )
        {
            printf ( "Yes\n" );
        }
        else
        {
            printf ( "No\n" );
        }
    }

    return 0;
}
