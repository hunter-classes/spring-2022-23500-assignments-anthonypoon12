#pragma once
#include "Node.h"
#define TREE_ERR_EMPTY 1
#define TREE_ERR_NO_VALUE 2
class Tree{
    private:
        Node *root;
    public:
        Tree();
        int rsearch(int value);       
        int rsearch(int value, Node *p);
        void insert(int value);     
        void insert_helper(int value, Node *r);
        void remove(int value);
        int count_leaves();
        int height();
        int sum_at_level(int level);
        std::string pretty_printer();
        bool cousins(Node *one, Node *two);
};