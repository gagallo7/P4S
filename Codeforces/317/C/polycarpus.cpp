#include <iostream>
#include <set>
#include <map>
#include <utility>

using namespace std;

void countItens ( char formula[], int n[]) {
    for ( int i = 0; i < 100; i++ ) {
        if ( formula[i] == 'B' ) {
            n[0]++;
        }
        else if ( formula[i] == 'C' ) {
            n[2]++;
        }
        else if ( formula[i] == 'S' ) {
            n[1]++;
        }
        else 
            break;
    }
}


int main () {
    long long r;
    int n[3];
    int p[3], nItens[3];
    char formula[101];

    set < int > qty;
    multimap < int, int > m;

    cin >> formula >> n[0] >> n[1] >> n[2] >> p[0] >> p[1] >> p[2] >> r;

    nItens[0] = 0;
    nItens[1] = 0;
    nItens[2] = 0;
    countItens ( formula, nItens );

    if ( nItens[0])
        m.insert ( pair < int, int > ( n[0]/nItens[0], 0 ) );
    if ( nItens[1])
        m.insert ( pair < int, int > ( n[1]/nItens[1], 1 ) );
    if ( nItens[2])
        m.insert ( pair < int, int > ( n[2]/nItens[2], 2 ) );

    //cout << n[0]/nItens[0] << " " << n[1]/nItens[1]<< " " << n[2]/nItens[2] << " *** " << nItens[2] << endl;

    multimap < int, int >::iterator it;

    /*
    for ( it = m.begin(); it != m.end(); it++ ) {
        cout << it->second << ":" << it->first << " ";
    }
    cout << endl << endl;
    */

    int a;
    bool equal = false;
    while ( !equal ) {
        it = m.begin();
        int tmp = it->first + 1;
        int minor = it->second;
        if ( (a = p[minor] * ( nItens[minor] - n[minor]%nItens[minor] ) ) <= r ) {
            r -= a;
            n[minor] += nItens[minor] - n[minor]%nItens[minor];
            m.erase(it);
            m.insert ( pair < int, int > ( n[minor]/nItens[minor], minor ) );
            for ( it = m.begin(); it != m.end(); it++ ) {
                cout << it->second << ":" << it->first << " " ;
            }
            cout << " r " << r << " tmp = " << tmp << " a " << a << endl;
            /*
                */
            int test = m.begin()->first;
            for ( it = m.begin(); it != m.end(); it++ ) {
                if ( test != it->first ) {
                    equal = false;
                    break;
                }
                equal = true;
            }
        }
        
        else
            break;
    }

    long double add = 0;
    if ( equal ) {
        add = r / ( p[0]*nItens[0] + p[1]*nItens[1] + p[2]*nItens[2] );
    }

    cout.precision(12);
    cout << "add = " << add << " r = " << r << " prod " << p[0]*n[0] + p[1]*n[1] + p[2]*n[2] << endl;
    cout << m.begin()->first + add;
    /*
    */


    cout << endl;

    return 0;
}
