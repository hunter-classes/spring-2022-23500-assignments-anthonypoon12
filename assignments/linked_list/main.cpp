#include <iostream>
#include "Node.h"
#include "List.h"
#include "OList.h"

int main(int argc, char *argv[]){
    List *l1 = new List();
    std::cout<<"creating List\n";
    l1->insert(1);
    l1->insert(2);
    l1->insert(3);
    std::cout<<"inserted 1, 2, and 3\n";
    std::cout<<"l1 is: "<<l1->toString()<<"\n";
    std::cout<<"First element of l1 is: "<<l1->locate(0)->getData()<<"\n";
    std::cout<<"Second element of l1 is: "<<l1->locate(1)->getData()<<"\n";
    std::cout<<"Third element of l1 is: "<<l1->locate(2)->getData()<<"\n";
    l1->remove(0);
    std::cout<<"removed first element:\n";
    std::cout<<"l1 is: "<<l1->toString()<<"\n";
    l1->insert(3);
    std::cout<<"inserted 3 to front.\n";
    std::cout<<"l1 is: "<<l1->toString()<<"\n";
    l1->remove(1);
    std::cout<<"removed second element:\n";
    std::cout<<"l1 is: "<<l1->toString()<<"\n";
    l1->insert(2);
    std::cout<<"inserted 2 to front.\n";
    std::cout<<"l1 is: "<<l1->toString()<<"\n";
    l1->remove(2);
    std::cout<<"removed third element:\n";
    std::cout<<"l1 is: "<<l1->toString()<<"\n";
    l1->insert(1);
    std::cout<<"inserted 1 to front.\n";
    std::cout<<"l1 is: "<<l1->toString()<<"\n";
    delete l1;
    std::cout<<"l1 after being deleted is.\n";
    std::cout<<"\n\nTesting OList:\n\n";
    OList *OrderedList = new OList();
    std::cout<<"Created new OList\n";
    OrderedList->insert(1);
    OrderedList->insert(-1);
    OrderedList->insert(23);
    OrderedList->insert(7);
    OrderedList->insert(14);
    std::cout<<"inserted 1, -1, 23, 7, and 14\n";
    std::cout<<"OrderedList is: "<<OrderedList->toString()<<"\n";
    std::cout<<std::boolalpha;
    std::cout<<"Does OrderedList contain the number 1?: " << OrderedList->contains(1)<<"\n";
    std::cout<<"Does OrderedList contain the number -1?: " << OrderedList->contains(-1)<<"\n";
    std::cout<<"Does OrderedList contain the number 200?: " << OrderedList->contains(200)<<"\n";
    std::cout<<"The value of the first element in OrderedList is: "<<OrderedList->get(0)<<"\n";
    std::cout<<"The value of the fourth element in OrderedList is: "<<OrderedList->get(3)<<"\n";
    OrderedList->remove(0);
    std::cout<<"Removing first element of OrderedList\n";
    std::cout<<"OrderedList is: "<<OrderedList->toString()<<"\n";
    OrderedList->remove(3);
    std::cout<<"Removing fourth element of OrderedList\n";
    std::cout<<"OrderedList is: "<<OrderedList->toString()<<"\n";
    OrderedList->reverse();
    std::cout<<"reversing OrderedList\n";
    std::cout<<"OrderedList is: "<<OrderedList->toString()<<"\n";
    std::cout<<"reversing OrderedList\n";
    std::cout<<"OrderedList is: "<<OrderedList->toString()<<"\n";
    delete OrderedList;
    std::cout<<"Deleting OrderedList\n";
    return 0;
}