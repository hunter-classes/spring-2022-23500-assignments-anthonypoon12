#pragma once
#include "Node.h"
#define QUEUE_ERR_FULL 1
#define QUEUE_ERR_EMPTY 2
class Queue{
    private:
        int list[5];
        int head;
        int tail;
    public:
    Queue();
    ~Queue();
    void enqueue(int value);
    int sequeue();
    int front();
    bool is_empty();
    bool is_full();
};