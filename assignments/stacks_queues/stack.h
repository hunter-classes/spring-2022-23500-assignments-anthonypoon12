#pragma once
#include "List.h"
#define STACK_ERR_EMPTY 1
#define STACK_ERR_OTHER 2
#define STACK_ERR_FULL 4
class stack{
    private:
        List list;
        int size;
    public:
        stack();
        ~stack();
        void push(int val);
        int pop(); // remove and return the top item
        int top(); // return but do not remove the top item
        bool is_empty(); // return true if empty, false otherwise
};