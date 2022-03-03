#include <iostream>
#include "OList.h"

OList::OList(){
    head=nullptr;
}
OList::~OList(){
    while (head!=nullptr)
        remove(0);
}
void OList::insert(int value){
    bool used = false;
    Node* newnode = new Node(value);
    if (head==nullptr)
        head=newnode;
    else{
        Node* trailer = head;
        Node* after = head->getNext();
        if (trailer->getData() >= value){
            head = newnode;
            head->setNext(trailer);
        }
        else{
            while (after!=nullptr){
                if (trailer->getData()<=value && after->getData() >= value){
                    trailer->setNext(newnode);
                    newnode->setNext(after);
                    used = true;
                    break;
                }
                trailer=trailer->getNext();
                after=after->getNext();
            }
            if (!used)
                trailer->setNext(newnode);
        }
    }
}
std::string OList::toString(){
    std::string output = "";
    Node* walker = head;
    while (walker!=nullptr){
        output+=std::to_string(walker->getData());
        walker=walker->getNext();
        output+="-->";
    }
    output+="nullptr";
    return output;
}
bool OList::contains (int value){
    if (value<head->getData())
        return false;
    Node *walker = head;
    while (walker!=nullptr){
        if (walker->getData()==value)
            return true;
        if (walker->getData()>value){
            return false;
        }
        walker=walker->getNext();
    }
    return false;
}
int OList::get(int loc){
    Node* walker = head;
    int place = 0;
    if (loc<0)
        throw std::out_of_range("Out of range");
    while(walker!=nullptr){
        if (place==loc){
            return walker->getData();
        }
        place++;
        walker=walker->getNext();
    }
    throw std::out_of_range("Out of range");
}
void OList::remove(int loc){
    Node* trailer = nullptr;
    Node* walker = head;
    int place = 0;
    if (loc<0)
        throw std::out_of_range("Out of range");
    while(walker!=nullptr && place!=loc){
        place++;
        trailer=walker;
        walker=walker->getNext();
    }
    if (walker==nullptr)
        throw std::out_of_range("Out of range");
    if (trailer==nullptr)
        head=walker->getNext();
    else
        trailer->setNext(walker->getNext());
    delete walker;
}
void OList::reverse(){
    Node *walker = head;
    Node *trailer = nullptr;
    if(walker!=nullptr){
        trailer = walker;
        walker = walker->getNext();
        while(walker!=nullptr){
            trailer->setNext(walker->getNext());
            walker->setNext(head);
            head = walker;
            walker=trailer->getNext();
        }
    }
}