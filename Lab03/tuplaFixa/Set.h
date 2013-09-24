/* 
 * File:   Set.h
 * Author: eduardoxavier
 *
 * Created on 19 de Julho de 2013, 14:51
 */

#ifndef SET_H
#define	SET_H

#include<vector>

class Set {
public:
    long double value;
    int size;
    std::vector<int> elements;
    
    
    Set();
    Set(const Set& orig);
    virtual ~Set();
private:

};

#endif	/* SET_H */

