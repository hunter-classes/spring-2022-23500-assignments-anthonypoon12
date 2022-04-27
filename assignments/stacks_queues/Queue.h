#pragma once
#include "Node.h"
class Queue{
    private:
        int list[5];
    public:
    Queue();
    ~Queue();
    void enqueue(int value);
    int sequeue();
    int front();
    bool is_empty();
    bool is_full();
};