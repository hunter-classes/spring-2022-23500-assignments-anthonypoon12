#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main(){
    Node *n = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(50);
    Node *n6 = new Node(60);
    Node *n7 = new Node(70);
    n->setLeft(n2);
    n->setRight(n5);
    n2->setLeft(n3);
    n3->setLeft(n4);
    n5->setLeft(n6);
    n5->setRight(n7);

    std::cout<<"The root is: "<<n->getData()<<"\n";
    for (auto x: {n,n2,n3,n4,n5,n6,n7}){
        std::cout<<"left of "<<x->getData()<<" is: ";
        if (x->getLeft()==nullptr)
            std::cout<<"nullptr\n";
        else
            std::cout<<x->getLeft()->getData()<<"\n";
        std::cout<<"right of "<<x->getData()<<" is: ";
        if (x->getRight()==nullptr)
            std::cout<<"nullptr\n";
        else
            std::cout<<x->getRight()->getData()<<"\n";
    }

    BSTree *t = new BSTree();
    t-> setup();
    BSTree *t2 = new BSTree();
    t2-> setup(n);
    std::cout << t->get_debug_string()<<"\n";
    std::cout << t2->get_debug_string()<<"\n";
    return 0;
}