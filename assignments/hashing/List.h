#pragma once
#include <iostream>
#include "Node.h"
class List{
    private:
        Node *head;
    public:
        List();
        ~List();
        void insert(Person *data);
        std::string toString();
        Node* locate(int index);
        void remove(int index);
        Person* findByName(std::string name);
};