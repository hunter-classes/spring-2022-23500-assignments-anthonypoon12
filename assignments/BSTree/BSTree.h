#pragma once

class BSTree{
    private:
        Node *root;
    public:
        BSTree();
        void insert(int d);
        std::string get_debug_string();
        std::string get_debug_string_helper(Node *n);
        void setup();
        void setup(Node *n);
};