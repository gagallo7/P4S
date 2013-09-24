/* 
 * File:   Heap.h
 * Author: eduardoxavier
 *
 * Created on 19 de Julho de 2013, 15:43
 */

#ifndef HEAP_H
#define	HEAP_H

#include "PartialSolution.h"
#include "Node.h"

/*struct Node{
    PartialSolution *nodeSol;
    Node *father;
    Node *lchild;
    Node *rchild;
    
};*/

template <class T>
class Heap {
    
public:
    Heap();
    Heap(const Heap& orig);
    virtual ~Heap();
    void insert(T p);
    void deleteTop();
    T top();
    bool empty();

    void print();
private:
    Node<T> *head;

    double randDouble();
    void heapfyBottomUp(Node<T> *n);
    void heapfyTopDown(Node<T> *n);
    void deleteHeap(Node<T> *n);
    void inOrderPrint(Node<T> *n,int level);
    Node<T>* findLeaf();
};

#endif	/* HEAP_H */

