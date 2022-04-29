#pragma once
#include "Node.h"
#define TREE_ERR_EMPTY 1
class Tree{
    private:
        Node *root;
    public:
        Tree();
        int rsearch(int value);       
        int rsearch(int value, Node *p);
        void insert(int value);     
        void insert_helper(int value, Node *r);

};