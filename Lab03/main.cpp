#include <iostream>
#include <set>

#include "PartialSolution.h"
#include "Heap.h"

using namespace std;

set < int > diff ( set < int > A, set < int > B ) {

    if (A.empty()) 
        return B;

    int v = *(A.end());
    int size = B.size();

    for ( int i = 0; i < v; i++ ) {
        B.erase(i);
    }

    return B;
}

set < int > diff2 ( set < int > A, set < int > B ) {

    set < int >::iterator is;

    for ( is = A.begin(); is != A.end(); is++ ) {
        if ( *is >= *(A.end()) )
            B.erase (*is);
    }

    return B;
}

int totalElem ( set < int > a, set < int > b, vector < Set > sets ) {
    set < int > s;
    set < int >::iterator si;

    for ( si = a.begin(); si != a.end(); si++ ) {
        for ( int i = 0; i < sets[*si].elements.size(); i++ ) {
            s.insert( sets[*si].elements[i] );
        }
    }

    for ( si = b.begin(); si != b.end(); si++ ) {
        for ( int i = 0; i < sets[*si].elements.size(); i++ ) {
            s.insert( sets[*si].elements[i] );
        }
    }

    return s.size();
}


int numElemUnion (vector < int > a, vector < int > b ) {
    set < int > s;

    for ( int i = 0; i < a.size(); i++ ) {
        s.insert(a[i]);
    }

    for ( int i = 0; i < b.size(); i++ ) {
        s.insert(b[i]);
    }

    return s.size();
}

set < int > uniao (set < int > a, set < int > b ) {
    set < int >::iterator si;

    for ( si = b.begin(); si != b.end(); si++ ) {
        a.insert(*si);
    }

    return a;
}


int main () {
    Instance I;
    I.readInstance ();

    PartialSolution P, E, S;
    set < int > filhos, tmp, aux;
    Heap < PartialSolution > Nos;

    Nos.insert(P);

    long double U = INFINITY;
    cout << U << endl;


    vector < bool > map (I.numberSets, true);
    for ( int i = 0; i < I.numberSets; i++ ) {
        filhos.insert (i);
    }
    // filhos contem todos os conjuntos que podem ser selecionados

    I.printInstance();

    cout << Nos.top();

    cout << "Numero de elementos... " << endl;
    cout << numElemUnion ( I.sets[2].elements, I.sets[3].elements );
    cout << endl;

    while ( !Nos.empty() ) {
        cout << "U: " << U << " -- ";
        Nos.print();
        E = Nos.top();
        printSet ( E.conj );
        Nos.deleteTop();

        tmp = diff ( E.conj, filhos );

        set < int >::iterator is;


        if ( E.status == Complete ) {
            S = E;
            break;
        }
        // Atualizando lowerBound de X, o qual e' um filho de E
        for ( is = tmp.begin(); is != tmp.end(); is++ ) {
            cout << "add conj " << *is << endl << endl;
            PartialSolution X;
            X.conj = E.conj;
            X.conj.insert (*is);
            X.atualizaBounds( I.sets );
            aux = diff ( X.conj, filhos );
            aux = uniao ( E.conj, aux );


            // solucao e' viavel/completa
            if ( totalElem ( E.conj, X.conj, I.sets ) == I.numberElements ) {
                X.upperBound = X.lowerBound;
                X.value = X.lowerBound;
                X.status = Complete;
            }

            // solucao e' inviavel
            else if ( totalElem ( X.conj, aux, I.sets ) < I.numberElements ) {
                X.upperBound = INFINITY;
                X.lowerBound = INFINITY;
                X.status = Inviavel;
            }

            // solucao parcial
            else {
                //cout << X.showLB() << endl;
            }

            if ( X.lowerBound <= U ) {
                Nos.insert(X);
                U = U > X.upperBound ? X.upperBound : U;
            }
        }


        /*
           if ( E.status == Complete && E.status == Partial ) {
           S = E;
           break;
           }

        // Selecionando filhos de Nos
        for ( int i = 0; i < map.size(); i++ ) {
        if ( map [i] ) {
        X = I.sets[i];

        }
        }


        ... */
    }

saida:

    cout << "Solucao: " << S.lowerBound;
    printSet ( S.conj );

    return 0;
}
