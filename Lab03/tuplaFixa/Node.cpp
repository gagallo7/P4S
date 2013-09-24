/* 
 * File:   Node.cpp
 * Author: eduardoxavier
 * 
 * Created on 22 de Julho de 2013, 16:19
 */

#include "Node.h"
#include "PartialSolution.h"

template <class T>
Node<T>::Node() {
    father = NULL;
    lchild = NULL;
    rchild = NULL;

}

template <class T>
Node<T>::Node(T nodeSol_) {
    this->nodeSol = T(nodeSol_);
}

template <class T>
Node<T>::Node(const Node& orig) {
    this->nodeSol = T(orig.nodeSol);
    this->lchild = orig.lchild;
    this->rchild = orig.rchild;
    this->father = orig.father;
}

template <class T>
Node<T>::~Node() {
}

template class Node<int>;
template class Node<PartialSolution>;

