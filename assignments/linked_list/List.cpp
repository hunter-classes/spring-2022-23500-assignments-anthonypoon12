#include <iostream>
#include "List.h"
List::List(){
    head = nullptr;
}
List::~List(){
    while(head!=nullptr)
        remove(0);
}
void List::insert(std::string data){
    //create a new node
    Node *new_node = new Node(data);
    //insert the new node
    new_node->setNext(head);
    head=new_node;
}
std::string List::toString(){
    if (head==nullptr){
        return "";
    }
    Node *walker = head;
    std::string s = "";
    while (walker != nullptr){
        s = s + walker -> getData() + "-->";
        walker = walker->getNext();
    }
    s=s+"nullptr";
    return s;
}
Node* List::locate(int index){
    int place = 0;
    Node *walker = head;
    if (index<=0) //if index is negative, return head
        return head;
    while(walker!=nullptr){
        walker = walker->getNext();
        place++;
        if (place==index)
            return walker;
    }
    return nullptr;//if index is greater than or equal to list size, return null pointer
}
void List::remove(int index){
    if (index<=0){
        Node* newhead = head->getNext();
        delete head;
        head = newhead;
    }
    else{
        Node* target = locate(index);
        if (target!=nullptr){
            locate(index-1)->setNext(target->getNext());
            delete target;
        }
    }
}