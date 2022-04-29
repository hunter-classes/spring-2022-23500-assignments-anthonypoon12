#pragma once
class Node{
    private:
        int data;
        Node *left;
        Node *right;
    public:
        Node();
        Node(int data);
        void setData(int data);
        void setLeft(Node *next);
        void setRight(Node *next);
        int getData();
        Node *getNext();
};