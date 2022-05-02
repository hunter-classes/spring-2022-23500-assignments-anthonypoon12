#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "Tree.h"

Tree *tree = new Tree();
TEST_CASE("Testing insert and rsearch"){
    CHECK_THROWS(tree->rsearch(0));
    tree->insert(1);
    tree->insert(0);
    tree->insert(2);
    CHECK(tree->rsearch(0)==0);
    CHECK(tree->rsearch(1)==1);
    CHECK(tree->rsearch(2)==2);
    CHECK_THROWS(tree->rsearch(100));
}