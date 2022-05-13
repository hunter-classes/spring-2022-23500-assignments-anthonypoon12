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
    std::cout<<"Removing number 2: ";
    try{
        tree->remove(2);
        std::cout<<"Sucess!\n";
    }catch(int e){
        std::cout<<"Failed\n";
    }
    std::cout<<"Removing number 1: ";
    try{
        tree->remove(1);
        std::cout<<"Sucess!\n";
    }catch(int e){
        std::cout<<"Failed\n";
    }
    std::cout<<"Removing number 4: ";
    try{
        tree->remove(4);
        std::cout<<"Sucess!\n";
    }catch(int e){
        std::cout<<"Failed\n";
    }
    std::cout<<"Removing number 6: ";
    try{
        tree->remove(6);
        std::cout<<"Sucess!\n";
    }catch(int e){
        std::cout<<"Failed\n";
    }
    std::cout<<"Removing number 8: ";
    try{
        tree->remove(8);
        std::cout<<"Sucess!\n";
    }catch(int e){
        std::cout<<"Failed\n";
    }
    tree->pretty_printer();
    return 0;
}
