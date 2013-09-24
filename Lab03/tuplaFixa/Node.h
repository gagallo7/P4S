/* 
 * File:   Node.h
 * Author: eduardoxavier
 *
 * Created on 22 de Julho de 2013, 16:19
 */

#ifndef NODE_H
#define	NODE_H

template <class T>
class Node {
public:
    Node();
    Node(T nodeSol_);
    Node(const Node& orig);
    virtual ~Node();
    T nodeSol;
    Node *father;
    Node *lchild;
    Node *rchild;
 private:
};

#endif	/* NODE_H */

