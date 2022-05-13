#pragma once
#include <iostream>
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
        int count_leaves(Node *n);
        int height();
        int height(Node *n);
        int sum_at_level(int level);
        int sum_at_level(int level, Node *n, int current);

        void pretty_printer();
        std::string pretty_printer(Node *n, int tabs,bool l);
        bool cousins(Node *one, Node *two); 
        int level(Node *n);
        int level(Node *n, Node *value, int l);
};