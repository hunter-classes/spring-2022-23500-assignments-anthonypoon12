#include "Queue.h"
Queue::Queue(){//if head and tail are equal, it is empty but if their mod is equal, it is full
    head = 0;
    tail = 0;
}
bool Queue::is_empty(){
    return head==tail;
}
bool Queue::is_full(){
    return tail-head>=5;
}
void Queue::enqueue(int value){
    if (is_full()){
    throw QUEUE_ERR_FULL;
    }
    list[tail%5]=value;
    tail++;
}
int Queue::sequeue(){
    if(is_empty())
        throw QUEUE_ERR_EMPTY;
    int output = list[head%5];
    head++;
    return output;
}
int Queue::front(){
    if (is_empty())
        throw QUEUE_ERR_EMPTY;
    return list[head%5];
}
Queue::~Queue(){
    while(!is_empty()){
        sequeue();
    }
}