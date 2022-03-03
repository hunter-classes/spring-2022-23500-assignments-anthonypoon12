#include <iostream>
#include "Node.h"
#include "List.h"
#include "OList.h"

int main(int argc, char *argv[]){
    List *l1 = new List();
    l1->insert(1);
    l1->insert(2);
    l1->insert(3);
    std::cout<<l1->toString()<<"\n";
    std::cout<<l1->locate(0)->getData()<<"\n";
    std::cout<<l1->locate(1)->getData()<<"\n";
    std::cout<<l1->locate(2)->getData()<<"\n";
    l1->remove(0);
    std::cout<<"removed first element:\n";
    std::cout<<l1->toString()<<"\n";
    l1->insert(3);
    std::cout<<"inserted 3 to front.\n";
    std::cout<<l1->toString()<<"\n";
    l1->remove(1);
    std::cout<<"removed second element:\n";
    std::cout<<l1->toString()<<"\n";
    l1->insert(2);
    std::cout<<"inserted 2 to front.\n";
    std::cout<<l1->toString()<<"\n";
    l1->remove(2);
    std::cout<<"removed third element:\n";
    std::cout<<l1->toString()<<"\n";
    l1->insert(1);
    std::cout<<"inserted 1 to front.\n";
    std::cout<<l1->toString()<<"\n";
    delete l1;
    std::cout<<"l1 after being deleted is: "<<l1->toString()<<"\nWhat is left of l1 has been printed.\n";
    std::cout<<"\n\nTesting OList:\n\n";

    return 0;
}