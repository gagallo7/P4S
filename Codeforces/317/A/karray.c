#include <stdio.h>

int main () {
    int n, k;
    int array[100];
    int changes = 0, i, j;
    int one, two;

    scanf (" %d %d", &n, &k);

    for ( i = 0; i < n; i++) {
        scanf ( " %d", &array[i] );
    }


    for ( i = 0; i < k; i++) {
        one = 0;
        two = 0;
        for ( j = 0; j < n/k; j++ ) {
            if ( array[i+k*j] == 1 )
                one++;
            else
                two++;
        }
        if (one > two) {
            changes += two;
        }
        else
            changes += one;
    }

    printf ( "%d\n", changes );
    
    return 0;
}
