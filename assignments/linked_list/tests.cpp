#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "OList.h"
OList* OrderedList = new OList();
TEST_CASE("creating OList"){
    CHECK(OrderedList->toString() == "nullptr");
}
TEST_CASE("OList insert"){
    OrderedList->insert(1);
    CHECK(OrderedList->toString() == "1-->nullptr");
    OrderedList->insert(-1);
    CHECK(OrderedList->toString() == "-1-->1-->nullptr");
    OrderedList->insert(10);
    CHECK(OrderedList->toString() == "-1-->1-->10-->nullptr");
    OrderedList->insert(5);
    CHECK(OrderedList->toString() == "-1-->1-->5-->10-->nullptr");
    OrderedList->insert(5);
    CHECK(OrderedList->toString() == "-1-->1-->5-->5-->10-->nullptr");
}
TEST_CASE("OList contains"){
    CHECK(OrderedList->contains(-1)==true);
    CHECK(OrderedList->contains(-10)==false);
    CHECK(OrderedList->contains(0)==false);
    CHECK(OrderedList->contains(11)==false);
}
TEST_CASE("OList get"){
    CHECK(OrderedList->get(0)==-1);
    CHECK(OrderedList->get(1)==1);
    CHECK_THROWS(OrderedList->get(-1)==1);
    CHECK_THROWS(OrderedList->get(10)==1);
    CHECK_THROWS(OrderedList->get(5)==10);
    CHECK(OrderedList->get(4)==10);
}
OList* OrderedListEmpty = new OList();
TEST_CASE("OList remove"){
    OrderedList->remove(3);
    CHECK(OrderedList->toString() == "-1-->1-->5-->10-->nullptr");
    OrderedList->remove(0);
    CHECK(OrderedList->toString() == "1-->5-->10-->nullptr");
    OrderedList->remove(2);
    CHECK(OrderedList->toString() == "1-->5-->nullptr");
    CHECK_THROWS(OrderedList->remove(-1));
    CHECK_THROWS(OrderedList->remove(2));
    CHECK_THROWS(OrderedListEmpty->remove(2));
}
OList* OrderedList2 = new OList();
TEST_CASE("OList reverse"){
    OrderedList->reverse();
    CHECK(OrderedList->toString() == "5-->1-->nullptr");
    OrderedList->reverse();
    CHECK(OrderedList->toString() == "1-->5-->nullptr");
    OrderedList->insert(1);
    OrderedList->insert(2);
    OrderedList->insert(3);
    OrderedList->insert(200);
    OrderedList->insert(3);
    OrderedList->insert(8);
    OrderedList->insert(16);
    std::string originalorder = OrderedList->toString();
    OrderedList->reverse();
    CHECK(OrderedList->toString() == "200-->16-->8-->5-->3-->3-->2-->1-->1-->nullptr");
    OrderedList2->reverse();
    CHECK(OrderedList2->toString() == "nullptr");
    OrderedList2->insert(20);
    OrderedList2->reverse();
    CHECK(OrderedList2->toString() == "20-->nullptr");
    delete OrderedList;
    delete OrderedList2;
    delete OrderedListEmpty;
}