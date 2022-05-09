#include "Tree.h"
Tree::Tree(){
    root = nullptr;
}
int Tree::rsearch(int value){
    if (root==nullptr)
        throw TREE_ERR_EMPTY;
    return rsearch(value, root);
}
int Tree::rsearch(int value, Node *p){
    if (p==nullptr)
        throw TREE_ERR_NO_VALUE;
    if (p->getData()==value)
        return p->getData();
    else if(p->getData()>=value)
        return rsearch(value,p->getLeft());
    else
        return rsearch(value,p->getRight());
}
void Tree::insert(int value){
    if (root==nullptr){
        Node *newnode = new Node(value);
        root = newnode;
    }
    else
        insert_helper(value,root);
}
void Tree::insert_helper(int value, Node *r){
    Node *newnode = new Node(value);
    if (r->getData()>=value){
        if (r->getLeft()==nullptr)
            r->setLeft(newnode);
        else
            insert_helper(value,r->getLeft());
    }else{
        if (r->getRight()==nullptr)
            r->setRight(newnode);
        else
            insert_helper(value,r->getRight());
    }
}
void Tree::remove(int value){
    rsearch(value);
    Node *target;
    Node *targetl;
    Node *targetr;
    Node *trailer = nullptr;
    if (root->getData()==value){
        target=root;
        targetl=target->getLeft();
        targetr=target->getRight();
    }
    else{
        Node *focus = root;
        Node *l = focus->getLeft();
        Node *r = focus->getRight();
        while(focus->getData()!=value && (l!=nullptr || r!=nullptr)){
            if (value<=focus->getData()){
                trailer=focus;
                focus=l;
                l=focus->getLeft();
                r=focus->getRight();
            }
            else{
                trailer=focus;
                focus=r;
                l=focus->getLeft();
                r=focus->getRight();
            }
        }
        if (focus->getData()!=value)
            throw TREE_ERR_NO_VALUE;
        target = focus;
        targetl = target->getLeft();
        targetr = target->getRight();
    }
    int children = 0;
    if (targetl!=nullptr)
        children++;
    if (targetr!=nullptr)
        children++;
    if (children<=1){
        Node *child;
        if (targetl!=nullptr)
            child=targetl;
        else
            child=targetr;
        if (trailer!=nullptr){
            if (trailer->getLeft()==target)
                trailer->setLeft(child);
            else
                trailer->setRight(child);
        }
        else
            root = child;
        delete target;
    }
    else{
        Node *traveler = target->getRight();
        Node *travl = traveler->getLeft();
        Node *travr = traveler->getRight();
        Node* travtrail = target;
        while (travl!=nullptr || travr!=nullptr){
            if (travl!=nullptr){
                travtrail=traveler;
                traveler=travl;
                travl=traveler->getLeft();
                travr=traveler->getRight();
            }else{
                travtrail=traveler;
                traveler=travr;
                travl=traveler->getLeft();
                travr=traveler->getRight();
            }
        }
        target->setData(traveler->getData());
        if (travtrail->getLeft()==traveler)
            travtrail->setLeft(nullptr);
        else
            travtrail->setRight(nullptr);
        delete traveler;
    }
}
int Tree::count_leaves(){
    return count_leaves(root);
}
int Tree::count_leaves(Node *n){
    int count = 0;
    if (n!=nullptr && n->getLeft()==nullptr && n->getRight()==nullptr){
        return 1;
    }
    else if (n==nullptr)
        return 0;
    return count_leaves(n->getLeft()) + count_leaves(n->getRight());
}
int Tree::height(){
    return 0;
}
int Tree::sum_at_level(int level){
    return 0;
}
std::string Tree::pretty_printer(){
    return "";
}
bool Tree::cousins(Node *one, Node *two){
    return true;
}
