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
    // rsearch(value);
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
        while(focus!=nullptr && focus->getData()!=value && (l!=nullptr || r!=nullptr)){
            if (value<=focus->getData()){
                trailer=focus;
                focus=l;
                if (focus==nullptr){
                    l=nullptr;
                    r=nullptr;
                }
                else{
                    l=focus->getLeft();
                    r=focus->getRight();
                }
            }
            else{
                trailer=focus;
                focus=r;
                if (focus==nullptr){
                    l=nullptr;
                    r=nullptr;
                }
                else{
                    l=focus->getLeft();
                    r=focus->getRight();
                }
            }
        }
        if (focus==nullptr || focus->getData()!=value)
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
    height(root);
}
int Tree::height(Node* n){
    int l=0;
    int r=0;
    if (n->getLeft()!=nullptr)
        l = height(n->getLeft());
    if (n->getRight()!=nullptr)
        r = height(n->getRight());
    if (l>r)
        return l+1;
    return r+1;
}
int Tree::sum_at_level(int level){//root is level 1
    sum_at_level(level, root, 1);
}
int Tree::sum_at_level(int level, Node *n, int current){
    if (current<level){
        return sum_at_level(level, n->getLeft(), current+1) + sum_at_level(level, n->getRight(), current+1);
    }
    else{
        return n->getData();
    }
}
std::string Tree::pretty_printer(){
    return "";
}
bool Tree::cousins(Node *one, Node *two){
    if (level(one)==level(two))
        return true;
    return false;
}
int Tree::level(Node *value){
    return level(root, value, 1);
}
int Tree::level(Node *p, Node *value, int l){
    if (p==nullptr)
        throw TREE_ERR_NO_VALUE;
    if (p==value)
        return l;
    else if(p->getData()>=value->getData())
        return level(p->getLeft(),value,l+1);
    else
        return level(p->getRight(),value,l+1);

}
void Tree::insert(int value){
    if (root==nullptr){
        Node *newnode = new Node(value);
        root = newnode;
    }
    else
        insert_helper(value,root);
}