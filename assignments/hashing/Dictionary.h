#pragma once
#include "List.h"
class Dictionary{
    private:
        List *list[10];
    public:
        Dictionary();
        ~Dictionary();
        void insert(Person *person);
        Person* retrieve(int id);
        std::string allKeys();
};