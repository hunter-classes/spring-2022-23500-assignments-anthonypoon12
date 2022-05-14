#pragma once
#include "List.h"
class Dictionary{
    private:
        List *list[10];
    public:
        Dictionary();
        ~Dictionary();
        void insert(Person *person);
        Person* retrieve(std::string name);
        std::string allKeys();
        int hashfunc(std::string s, int m);
};