/* 
 * File:   Heap.cpp
 * Author: eduardoxavier
 * 
 * Created on 19 de Julho de 2013, 15:43
 * 
 * 
 * Heap of Expected Height log n
 */

#include "Heap.h"

template <class T>
Heap<T>::Heap() {
    head = NULL;
}

template <class T>
Heap<T>::Heap(const Heap& orig) {
    this->head = orig.head;
}

template <class T>
Heap<T>::~Heap() {
    if (head != NULL) {
        deleteHeap(head);
        head = NULL;

    }
}

template <class T>
void Heap<T>::deleteHeap(Node<T>* n) {
    if (n->lchild != NULL)
        deleteHeap(n->lchild);
    if (n->rchild != NULL)
        deleteHeap(n->rchild);
    delete n;
}


template <class T>
void Heap<T>::insert(T p) {
    if (head == NULL) {
        head = new Node<T>();
        head->nodeSol = p;
        head->father = NULL;
        head->lchild = NULL;
        head->lchild = NULL;
        return;
    }

    Node<T> *aux = head;
    while ((aux->lchild != NULL) && (aux->rchild != NULL)) {
        if (randDouble() < 0.5) {
            aux = aux->lchild;
        } else {
            aux = aux->rchild;
        }
    }

    Node<T> *n = new Node<T>();
    n->father = aux;
    n->nodeSol = p;
    n->lchild = NULL;
    n->rchild = NULL;

    if ((aux->lchild == NULL)&&(aux->rchild == NULL)) {
        if (randDouble() < 0.5) {
            aux->lchild = n;
        } else {
            aux->rchild = n;
        }
    } else if (aux->lchild == NULL)
        aux->lchild = n;
    else
        aux->rchild = n;

    heapfyBottomUp(n);

}

template <class T>
void Heap<T>::heapfyBottomUp(Node<T>* n) {
    Node<T> *l, *r, *min, *father;

    do {
        father = n->father;
        if (father == NULL) //Already on top;
            return;
        l = father->lchild;
        r = father->rchild;
        min = father;
        if ((l != NULL) && ((min->nodeSol) > (l->nodeSol)))
            min = l;
        if ((r != NULL) && ((min->nodeSol) > (r->nodeSol)))
            min = r;

        if (min != father) {
            T aux = father->nodeSol;
            father->nodeSol = min->nodeSol;
            min->nodeSol = aux;
            n = father; //New node to heapfy
        }
    } while (min != father);
}

template <class T>
void Heap<T>::deleteTop() {
    if (head != NULL) {
        Node<T> *n = findLeaf();
        if (n != head) {
            head->nodeSol = n->nodeSol;
            Node<T> *f = n->father;
            if (f->lchild == n) {
                delete (f->lchild);
                f->lchild = NULL;
            } else {
                delete (f->rchild);
                f->rchild = NULL;
            }
            heapfyTopDown(head);
        } else {
            delete(head);
            head = NULL;
        }
    }
}

template <class T>
T Heap<T>::top() {
    //T sol =  T((head->nodeSol));
    return head->nodeSol;
}

template <class T>
Node<T>* Heap<T>::findLeaf() {
    Node<T> *n = head;
    while ((n->lchild != NULL) || (n->rchild != NULL)) { //while node has at least one child
        if ((n->lchild != NULL) && (n->rchild != NULL)) {
            if (randDouble() < 0.5) {
                n = n->lchild;
            } else {
                n = n->rchild;
            }
        } else if (n->lchild != NULL)
            n = n->lchild;
        else
            n = n->rchild;
    }
    return n;
}

template <class T>
void Heap<T>::heapfyTopDown(Node<T>* n) {
    Node<T> *l, *r, *min;

    while ((n->lchild != NULL) || (n->rchild != NULL)) {
        l = n->lchild;
        r = n->rchild;
        min = n;
        if ((l != NULL) && ((min->nodeSol) > (l->nodeSol)))
            min = l;
        if ((r != NULL) && ((min->nodeSol) > (r->nodeSol)))
            min = r;

        if (min == n)
            return;
        else {
            T aux = n->nodeSol;
            n->nodeSol = min->nodeSol;
            min->nodeSol = aux;
            n = min; //New node to heapfy
        }
    }
}

template <class T>
double Heap<T>::randDouble() {
    return (double) rand() / (double) RAND_MAX;
}

template <class T>
void Heap<T>::print() {
    using namespace std;

    cout << "Printing Heap Tree in In-Order" << endl;

    inOrderPrint(head, 1);
}

template <class T>
void Heap<T>::inOrderPrint(Node<T>* n, int level) {
    using namespace std;

    if (n != NULL) {
        inOrderPrint(n->lchild, level + 1);
        if (n->father != NULL)
            cout << "Level: " << level << ", Value: " << (n->nodeSol) << ", Father: " << (n->father->nodeSol) << endl;
        else
            cout << "Level: " << level << ", Value: " << (n->nodeSol) << ", Father: None" << endl;

        inOrderPrint(n->rchild, level + 1);
    }
}

template <class T>
bool Heap<T>::empty() {
    if(head == NULL)
        return true;
    else
        return false;
}

template class Heap<int>;
template class Heap<PartialSolution>;