#include <iostream>
#include "Tree.h"

int main(){
    std::cout<<"Creating tree....\n";
    Tree *tree = new Tree();
    std::cout<<"Searching for 10: ";
    try{
        std::cout<<tree->rsearch(10)<<"\n";
    }catch(int e){
        std::cout<<"Not found\n";
    }
    std::cout<<"Adding 1,2,3,8,42,56,7,8,9063426 to tree\n";
    for (auto x: {1,2,3,8,42,56,7,8,9063426})
        tree->insert(x);
    for (auto x: {1,2,3,8,42,30,56,7,8,9063426,2000}){
        std::cout<<"Searching for "<<x<<": ";
        try{
            std::cout<<tree->rsearch(x)<<"\n";
        }catch(int e){
            std::cout<<"Not found\n";
        }
    }
    return 0;
}