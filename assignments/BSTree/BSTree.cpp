#include <iostream>
#include "Node.h"
#include "BSTree.h"
BSTree::BSTree(){
    root = nullptr;
}
void BSTree::insert(int d){

}
std::string BSTree::get_debug_string_helper(Node *n){
    std::string output = "";
    if (root == nullptr){
        return "";
    }else{
        if (n!=nullptr){
            output += std::to_string(n->getData()) + "-->";
            output += get_debug_string_helper(n->getLeft());
            output += get_debug_string_helper(n->getRight());
        }
        else
            output+="nullptr-->";
    }
    return output;
}
std::string BSTree::get_debug_string(){
    return get_debug_string_helper(root);
}
void BSTree::setup(){
    Node *n = new Node(10);
    root = n;
    n = new Node(20);
    root -> setLeft(n);
    n = new Node(30);
    root -> setRight(n);
    root -> getLeft() -> setLeft(n);
}
void BSTree::setup(Node *n){
    root=n;
}