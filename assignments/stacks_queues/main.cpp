#include <iostream>
#include "stack.h"

int main(){
    std::cout<<std::boolalpha;
    std::cout<<"Creating a new stack...\n";
    stack *stacky = new stack();
    std::cout<<"This stack is empty: "<<stacky->is_empty()<<"\n";
    std::cout<<"The top of stacky is: ";
    try{
        std::cout<<stacky->top()<<"\n";
    }catch(int e){
        std::cout<<"empty\n";
    }
    std::cout<<"pushing the number 1...\n";
    stacky->push(1);
    std::cout<<"The top of stacky is: ";
    try{
        std::cout<<stacky->top()<<"\n";
    }catch(int e){
        std::cout<<"empty\n";
    }
    std::cout<<"popping 1 number...\n";
    try{
        std::cout<<"This is the popped number: "<<stacky->pop()<<"\n";
    }catch(int e){
        std::cout<<"Popping failed\n";
    }
    std::cout<<"This stack is empty: "<<stacky->is_empty()<<"\n";
    std::cout<<"Pushing 1, 2, 3, 4, 10, 32, 10, 1, 1, 3, and 1000 to stack in this order...\n";
    for (int x: {1,2,3,4,10,32,10,1,1,3,1000}){
        stacky->push(x);
    }
    std::cout<<"The top of stacky is: ";
    try{
        std::cout<<stacky->top()<<"\n";
    }catch(int e){
        std::cout<<"empty\n";
    }
    std::cout<<"popping 4 numbers...\n";
    for (int i = 0; i < 4; i++){
        try{
            std::cout<<"This is the popped number: "<<stacky->pop()<<"\n";
        }catch(int e){
            std::cout<<"Popping failed\n";
        }
    }
    std::cout<<"The top of stacky is: ";
    try{
        std::cout<<stacky->top()<<"\n";
    }catch(int e){
        std::cout<<"empty\n";
    }
    delete stacky;
    return 0;
}