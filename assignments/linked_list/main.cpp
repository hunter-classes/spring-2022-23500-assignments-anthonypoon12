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
    return 0;
}