#include "Tree.h"

Tree::Tree(){
    root = nullptr;
}
int Tree::rsearch(int value){
    return rsearch(value, root);
}
int Tree::rsearch(int value, Node *p){
    if (p==nullptr)
        throw TREE_ERR_EMPTY;
    if (p->getData()==value)
        return p->getData();
    else if(p->getData()>=value)
        return rsearch(value,p->getLeft());
    else
        return rsearch(value,p->getRight());
}
void Tree::insert(int value){
    insert_helper(value,root);
}
void Tree::insert_helper(int value, Node *r){
    if (r==nullptr){
        Node *newnode = new Node(value);
        r = newnode;
    }else{
        if (r->getData()>=value){
            insert_helper(value,r->getLeft());
        }else{
            insert_helper(value,r->getRight());
        }
    }
}