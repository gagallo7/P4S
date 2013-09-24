
#include "PartialSolution.h"
#include "Heap.h"

using namespace std;

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

long double PartialSolution::showLB () {
		return this->lowerBound;
}

void PartialSolution::atualizaLowerBound ( vector < Set > sets ) {
		long double valorAcc = 0;

		set < int >::iterator is;

		for ( is = this->conj.begin(); is != this->conj.end(); is++ ) {
				valorAcc += sets[*is].value;
		}

		this->lowerBound = valorAcc;
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

PartialSolution& PartialSolution::operator=(const PartialSolution &orig) {
	this->status = orig.status;
    this->value = orig.value;
    this->lowerBound = orig.lowerBound;
    this->upperBound = orig.upperBound;
    return *this;
}


std::ostream & operator<<(std::ostream & os, const PartialSolution &p) {
    using namespace std;

    os << "Solution value: " << p.value << std::endl;
    os << "Upper Bound: " << p.upperBound << std::endl;
    os << "Lower Bound: " << p.lowerBound << std::endl;
}
