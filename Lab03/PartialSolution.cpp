
#include "PartialSolution.h"
#include "Heap.h"

using namespace std;

void printSet ( set < int > A ) {
    set < int >::iterator si;

    cout << endl << "Set: ";
    for ( si = A.begin(); si != A.end(); si++ ) {
        cout << *si << " ";
    }
    cout << endl;
}


// 4 estados: inviavel, viavel, parcial, limitado
PartialSolution::PartialSolution () {
	this->status = Partial;
    this->value = INFINITY;
    this->upperBound = INFINITY;
    this->lowerBound = -1 * INFINITY;
}

/*
void PartialSolution::Cover ( int n ) {
	this->covering.resize (n, false);
}
*/

// Construtor com referencia
PartialSolution::PartialSolution (const PartialSolution& orig) {
	this->status = orig.status;
	this->value = orig.value;
	this->lowerBound = orig.lowerBound;
	this->upperBound = orig.upperBound;
	this->conj = orig.conj;
}

PartialSolution& PartialSolution::operator=(const PartialSolution &orig) {
	this->status = orig.status;
    this->value = orig.value;
    this->lowerBound = orig.lowerBound;
    this->upperBound = orig.upperBound;
    this->conj = orig.conj;
    return *this;
}

long double PartialSolution::showLB () {
		return this->lowerBound;
}

void PartialSolution::atualizaBounds ( vector < Set > sets ) {
		long double valorAcc = 0;

		set < int >::iterator is;

		for ( is = this->conj.begin(); is != this->conj.end(); is++ ) {
				valorAcc += sets[*is].value;
		}

		this->lowerBound = valorAcc;

		for ( int i = *is; i < sets.size(); i++ ) {
				valorAcc += sets[i].value;
		}

        this->upperBound = valorAcc;

}

PartialSolution::~PartialSolution() {
}

bool PartialSolution::operator<(const PartialSolution &p) const {
    return (this->lowerBound < p.lowerBound);

}

bool PartialSolution::operator>(const PartialSolution &p) const {
    return (this->lowerBound > p.lowerBound);
}

bool PartialSolution::operator<=(const PartialSolution &p) const {
    return (this->lowerBound <= p.lowerBound);
}

bool PartialSolution::operator>=(const PartialSolution &p) const {
    return (this->lowerBound >= p.lowerBound);
}

bool PartialSolution::operator==(const PartialSolution &p) const {
    return (this->lowerBound == p.lowerBound);
}

bool PartialSolution::operator!=(const PartialSolution &p) const {
    return (this->lowerBound != p.lowerBound);

}


std::ostream & operator<<(std::ostream & os, const PartialSolution &p) {
    using namespace std;
    set < int >::iterator si;

    os << "Solution value: " << p.value << std::endl;
    os << "Upper Bound: " << p.upperBound << std::endl;
    os << "Lower Bound: " << p.lowerBound << std::endl;
    os << "#conj: " << p.conj.size() << " --";
    for ( si = p.conj.begin(); si != p.conj.end(); si++ ) {
        os << " " << *si; 
    }
    os << endl;
}
