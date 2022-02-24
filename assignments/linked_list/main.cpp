#include <iostream>
#include "Node.h"
#include "List.h"

int main(int argc, char *argv[]){
    List *l1 = new List();
    l1->insert("a");
    l1->insert("b");
    l1->insert("c");
    std::cout<<l1->toString()<<"\n";
    std::cout<<l1->locate(0)->getData()<<"\n";
    std::cout<<l1->locate(1)->getData()<<"\n";
    std::cout<<l1->locate(2)->getData()<<"\n";
    l1->remove(0);
    std::cout<<"removed first element:\n";
    std::cout<<l1->toString()<<"\n";
    l1->insert("c");
    std::cout<<"inserted c to front.\n";
    std::cout<<l1->toString()<<"\n";
    l1->remove(1);
    std::cout<<"removed second element:\n";
    std::cout<<l1->toString()<<"\n";
    l1->insert("b");
    std::cout<<"inserted b to front.\n";
    std::cout<<l1->toString()<<"\n";
    l1->remove(2);
    std::cout<<"removed third element:\n";
    std::cout<<l1->toString()<<"\n";
    l1->insert("a");
    std::cout<<"inserted a to front.\n";
    std::cout<<l1->toString()<<"\n";
    l1->remove(3);
    std::cout<<"removed fourth element:(should not have any changes)\n";
    std::cout<<l1->toString()<<"\n";
    l1->remove(-1);
    std::cout<<"removed negative first element:(should not have any changes)\n";
    std::cout<<l1->toString()<<"\n";
    delete l1;
    std::cout<<"l1 after being deleted is: "<<l1->toString()<<"\nWhat is left of l1 has been printed.\n";
    return 0;
}