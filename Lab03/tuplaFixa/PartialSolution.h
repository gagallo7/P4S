/* 
 * File:   Solucao.h
 * Author: eduardoxavier
 *
 * Created on 4 de Julho de 2013, 08:45
 */

#ifndef SOLUCAO_H
#define	SOLUCAO_H

enum { Complete, Ineficiente, Inviavel, Partial };

#include <math.h>
#include "Instance.h"
#include <set>

class PartialSolution {
private:
    long double value; //The value of the partial selected sets
    long double upperBound; //A primal bound value
    long double lowerBound; //A dual bound value
    
public:
	long double showLB ();
	void atualizaLowerBound ( std::vector < Set > );
	std::set < int > conj;
	int status;
    PartialSolution();//X
    PartialSolution(const PartialSolution&);//X
    virtual ~PartialSolution(); //X

    //Estes não precisa implementar
    PartialSolution& operator=(const PartialSolution& a);
    bool operator<(const PartialSolution &p) const;
    bool operator>(const PartialSolution &p) const;
    bool operator<=(const PartialSolution &p) const;
    bool operator>=(const PartialSolution &p) const;
    bool operator==(const PartialSolution &p) const;
    bool operator!=(const PartialSolution &p) const;
    friend std::ostream & operator<<(std::ostream & os, const PartialSolution &p);


};

#endif	/* SOLUCAO_H */

