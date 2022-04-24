#include <iostream>
#include "stack.h"

stack::stack(){
    list = List();
}
stack::~stack(){
    while(true){
        try{
            pop();
        }catch(int e){
            break;
        }
    }
}
void stack::push(int val){
    list.insert(val);
}
int stack::pop(){
    Node* popped = list.locate(0);
    list.remove(0);
    return popped->getData();
}
int stack::top(){
    return list.locate(0)->getData();
}
bool stack::is_empty(){
    try{
        if (list.locate(0)!=nullptr)
            return false;
    }catch(int e){
        return true;
    }
}