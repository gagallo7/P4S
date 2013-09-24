/* 
 * File:   Instance.h
 * Author: eduardoxavier
 *
 * Created on 19 de Julho de 2013, 14:50
 */

#ifndef INSTANCE_H
#define	INSTANCE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "Set.h"

class Instance {
    friend std::ostream& operator<<(std::ostream& os, const Instance& inst);
public:
    int numberElements; //Number of elements to be covered from 1...numberElements
    int numberSets; //Number of sets of the instance
    int k;
    std::vector<Set> sets; //The sets of the instance

    Instance();
    Instance(const Instance& orig);
    virtual ~Instance();

    void readInstance();
    void printInstance();
    bool feasibleSolution(int sol[]); //Given a vector representing a solution, check if it is feasible
private:

};

#endif	/* INSTANCE_H */

