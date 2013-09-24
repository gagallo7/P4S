#include <iostream>
#include <set>

#include "PartialSolution.h"
#include "Heap.h"

using namespace std;

set < int > diff ( set < int > A, set < int > B ) {

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

int main () {
	Instance I;
	I.readInstance ();

	PartialSolution P, E, S;
	set < int > filhos, tmp;
	Heap < PartialSolution > Nos;

	Nos.insert(P);

	long double U = INFINITY;
	cout << U << endl;


	vector < bool > map (I.numberSets, true);
	for ( int i = 0; i < I.numberElements; i++ ) {
			filhos.insert (i);
	}
	// Filhos contem todos os conjuntos que podem ser selecionados

	I.printInstance();

	cout << Nos.top();

	cout << "Numero de elementos... " << endl;
	cout << numElemUnion ( I.sets[2].elements, I.sets[3].elements );
	cout << endl;

	while ( !Nos.empty() ) {
		E = Nos.top();
		PartialSolution X;

		tmp = diff ( E.conj, filhos );

		set < int >::iterator is;

		// Atualizando lowerBound de X, o qual e' um filho de E
		for ( is = tmp.begin(); is != tmp.end(); is++ ) {
				X.conj.insert (*is);
				X.atualizaLowerBound( I.sets );
				cout << X.showLB() << endl;
		}

		if ( totalElem ( E.conj, X.conj, I.sets ) == I.numberElements ) {
				// A solucao e' viavel/completa
			//	X.upperBound = X.lowerBound;
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

	return 0;
}
