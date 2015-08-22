/* 
 * File:   Instance.h
 * Author: eduardoxavier
 *
 * Created on 19 de Julho de 2013, 14:50
 */

#ifndef INSTANCE_H
#define	INSTANCE_H

#include <iostream>
#include <cstdlib>

class Instance {
    friend std::ostream& operator<<(std::ostream& os, const Instance& inst);
public:
    int numberVertices; //Number of vertices in the graph
    int **adjMatrix;
    int s, t;
    
    Instance();
    Instance(const Instance& orig);
    virtual ~Instance();

    void readInstance(/*std::string fileName*/);
    void printInstance();
    
private:
    void freeMatrix();
    void allocateMatrix();

};

#endif	/* INSTANCE_H */

