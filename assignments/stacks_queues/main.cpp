#include <iostream>
#include "stack.h"
#include "Queue.h"

int main(){
    std::cout<<std::boolalpha;
    std::cout<<"Testing Stacks\nCreating a new stack...\n";
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
    std::cout<<"deleting stack\n";
    delete stacky;
    std::cout<<"\n\n\nTesting Queues\n";
    std::cout<<"Creating Queue...\n";
    Queue *queue = new Queue();
    std::cout<<"This queue is empty: "<<queue->is_empty()<<"\n";
    std::cout<<"This queue is full: "<<queue->is_full()<<"\n";
    std::cout<<"Sequeuing value: ";
    try{
        std::cout<<queue->sequeue();
    }catch(int e){
        std::cout<<"failed\n";
    }
    std::cout<<"Enqueuing number 1..\n";
    queue->enqueue(1);
    std::cout<<"This queue is empty: "<<queue->is_empty()<<"\n";
    std::cout<<"This queue is full: "<<queue->is_full()<<"\n";
    std::cout<<"The front of the queue is: "<<queue->front()<<"\n";
    std::cout<<"Sequeuing once.. value is: "<< queue->sequeue()<<"\n";
    std::cout<<"This queue is empty: "<<queue->is_empty()<<"\n";
    std::cout<<"This queue is full: "<<queue->is_full()<<"\n";
    std::cout<<"Enqueuing numbers 10, 5, 3, 2, and 4..\n";
    for (auto x: {10,5,3,2,4}){
        queue->enqueue(x);
    }
    std::cout<<"This queue is empty: "<<queue->is_empty()<<"\n";
    std::cout<<"This queue is full: "<<queue->is_full()<<"\n";
    std::cout<<"The front of the queue is: "<<queue->front()<<"\n";
    std::cout<<"Enqueuing number 100: ";
    try{
        queue->enqueue(100);
        std::cout<<"success!\n";
    }catch(int e){
        std::cout<<"failed\n";
    }
    std::cout<<"Sequeuing three times.. values are: ";
    std::cout<<queue->sequeue()<<", ";
    std::cout<<queue->sequeue()<<", ";
    std::cout<<queue->sequeue()<<"\n";
    std::cout<<"Deleting Queue\n";
    delete queue;
    return 0;
}