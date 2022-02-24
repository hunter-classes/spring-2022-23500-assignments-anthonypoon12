#include <iostream>
#include "Node.h"
#include "List.h"

int main(int argc, char *argv[]){
    List *l1 = new List();
    l1->insert("a");
    l1->insert("b");
    l1->insert("c");
    std::cout<<l1->toString()<<"\n";
    std::cout<<l1->locate(-1)->getData()<<"\n";
    std::cout<<l1->locate(0)->getData()<<"\n";
    std::cout<<l1->locate(1)->getData()<<"\n";
    std::cout<<l1->locate(2)->getData()<<"\n";
    l1->remove(0);
    std::cout<<l1->toString()<<"\n";
    l1->insert("c");
    l1->remove(1);
    std::cout<<l1->toString()<<"\n";
    l1->insert("b");
    std::cout<<l1->toString()<<"\n";
    l1->remove(2);
    std::cout<<l1->toString()<<"\n";
    l1->insert("a");
    std::cout<<l1->toString()<<"\n";
    l1->remove(3);
    std::cout<<l1->toString()<<"\n";
    l1->remove(-1);
    std::cout<<l1->toString()<<"\n";
    return 0;
}