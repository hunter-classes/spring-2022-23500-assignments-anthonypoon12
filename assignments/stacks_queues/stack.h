#pragma once
#include "List.h"
class stack{
    private:
        List list;
    public:
        stack();
        ~stack();
        void push(int val);
        int pop(); // remove and return the top item
        int top(); // return but do not remove the top item
        bool is_empty(); // return true if empty, false otherwise
};