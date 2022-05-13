#include <iostream>
#include "Tree.h"

int main(){
    std::cout<<"Creating tree....\n";
    Tree *tree = new Tree();
    std::cout<<std::boolalpha;
    std::cout<<"Visual Representation of Tree:\n\n\n\n";
    tree->pretty_printer();
    std::cout<<"Height of tree is: "<<tree->height()<<"\n";
    std::cout<<"Number of leaves is: "<<tree->count_leaves()<<"\n";
    std::cout<<"\n\n\n";
    std::cout<<"Searching for 10: ";
    try{
        std::cout<<tree->rsearch(10)<<"\n";
    }catch(int e){
        std::cout<<"Not found\n";
    }
    std::cout<<"Adding 1,2,3,8,42,56,7, 9063426, -10, -30, -25, -2,-1, 50, 51 to tree\n";
    for (auto x: {1,2,3,8,42,56,7,9063426, -10, -30, -25, -2,-1, 50, 51})
        tree->insert(x);
    std::cout<<"Visual Representation of Tree:\n\n\n\n";
    tree->pretty_printer();
    std::cout<<"Height of tree is: "<<tree->height()<<"\n";
    std::cout<<"Number of leaves is: "<<tree->count_leaves()<<"\n";
    std::cout<<"Sum of nodes at level 3: ";
    try{
        std::cout<<tree->sum_at_level(3)<<"\n";
    }catch(int e){
        std::cout<<"Tree height is not large enough\n";
    }
    std::cout<<"Sum of nodes at level 10: ";
    try{
        std::cout<<tree->sum_at_level(10)<<"\n";
    }catch(int e){
        std::cout<<"Tree height is not large enough\n";
    }
    std::cout<<"Sum of nodes at level 2: ";
    try{
        std::cout<<tree->sum_at_level(2)<<"\n";
    }catch(int e){
        std::cout<<"Tree height is not large enough\n";
    }
    std::cout<<"-30 and 3 are cousins: ";
    try{
        std::cout<< tree->cousins(-30,3)<<"\n";
    }
    catch(int e){
        std::cout<<"Not all numbers are not in tree\n";
    }
    std::cout<<"-30 and 1000 are cousins: ";
    try{
        std::cout<< tree->cousins(-30,1000)<<"\n";
    }
    catch(int e){
        std::cout<<"Not all numbers are not in tree\n";
    }
    std::cout<<"-30 and -25 are cousins: ";
    try{
        std::cout<< tree->cousins(-30,-25)<<"\n";
    }
    catch(int e){
        std::cout<<"Not all numbers are not in tree\n";
    }
    std::cout<<"\n\n\n";
    for (auto x: {1,2,3,8,42,30,56,7,8,9063426,2000, -10, -30, -25, -2,-1}){
        std::cout<<"Searching for "<<x<<": ";
        try{
            std::cout<<tree->rsearch(x)<<"\n";
        }catch(int e){
            std::cout<<"Not found\n";
        }
    }
    for (auto x: {2,1,4,6,8}){
        std::cout<<"Removing number "<<x<<": ";
        try{
            tree->remove(x);
            std::cout<<"Sucess!\n";
        }catch(int e){
            std::cout<<"Failed\n";
        }
    }
    std::cout<<"Visual Representation of Tree:\n\n\n\n";
    tree->pretty_printer();
    std::cout<<"Height of tree is: "<<tree->height()<<"\n";
    std::cout<<"Number of leaves is: "<<tree->count_leaves()<<"\n";
    std::cout<<"\n\n\n";
    return 0;
}
