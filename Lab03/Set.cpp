/* 
 * File:   Set.cpp
 * Author: eduardoxavier
 * 
 * Created on 19 de Julho de 2013, 14:51
 */

#include "Set.h"

Set::Set() {
}

Set::Set(const Set& orig) {
    this->value = orig.value;
    this->size = orig.size;
    this->elements = orig.elements;
}

Set::~Set() {
}

