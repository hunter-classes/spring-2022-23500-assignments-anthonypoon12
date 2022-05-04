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
TEST_CASE("Deleting"){
    CHECK_THROWS(tree->remove(100));
    tree->insert(-100);
    tree->insert(-50);
    tree->insert(-75);
    tree->insert(-2);
    tree->insert(10);
    tree->insert(5);
    tree->insert(20);
    tree->insert(32);
    tree->insert(11);
    tree->insert(31);
    tree->remove(31);
    CHECK_THROWS(tree->rsearch(31));
    tree->remove(2);
    CHECK_THROWS(tree->rsearch(2));
    tree->remove(20);
    CHECK_THROWS(tree->rsearch(20));
    tree->remove(1);
    CHECK_THROWS(tree->rsearch(1));
    CHECK(tree->rsearch(-100)==-100);
    CHECK(tree->rsearch(-50)==-50);
    CHECK(tree->rsearch(-75)==-75);
    CHECK(tree->rsearch(-2)==-2);
    CHECK(tree->rsearch(10)==10);
    CHECK(tree->rsearch(5)==5);
    CHECK(tree->rsearch(11)==11);
    CHECK(tree->rsearch(32)==32);
}
TEST_CASE("Count Leaves"){
    CHECK(tree->count_leaves()==3);
}