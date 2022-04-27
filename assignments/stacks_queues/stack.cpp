#include <iostream>
#include "stack.h"

stack::stack(){
    list = List();
    size = 0;
}
stack::~stack(){
    while(!is_empty()){
        pop();
    }
}
void stack::push(int val){
    list.insert(val);
    size++;
}
int stack::pop(){
    if(is_empty())
        throw STACK_ERR_EMPTY;
    int popped = list.locate(0)->getData();
    list.remove(0);
    size--;
    return popped;
}
int stack::top(){
    if (is_empty())
        throw STACK_ERR_EMPTY;
    return list.locate(0)->getData();
}
bool stack::is_empty(){
    return size==0;
}