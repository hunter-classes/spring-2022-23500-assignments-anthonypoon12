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
Tree *treewithnoroot = new Tree();
Tree *treewithonenode = new Tree();
TEST_CASE("Count Leaves"){
    treewithonenode->insert(10);
    CHECK(tree->count_leaves()==3);
    CHECK(treewithnoroot->count_leaves()==0);
    CHECK(treewithonenode->count_leaves()==1);
    tree->remove(-2);
    CHECK(tree->count_leaves()==2);
    tree->insert(-15);
    tree->insert(-1);
    tree->insert(-20);
    tree->insert(-21);
    tree->insert(-19);
    tree->insert(-3);
    CHECK(tree->count_leaves()==5);
}
TEST_CASE("heightoftree"){
    CHECK(treewithnoroot->height()==0);
    CHECK(treewithonenode->height()==1);
    CHECK(tree->height()==7);
    tree->insert(-18);
    CHECK(tree->height()==8);
    tree->remove(-18);
    tree->remove(-21);
    tree->remove(-3);
    tree->remove(-15);
    CHECK(tree->height()==7);
}
TEST_CASE("sumatlevel"){
    CHECK_THROWS(treewithnoroot->sum_at_level(1));
    CHECK(treewithonenode->sum_at_level(1)==10);
    CHECK_THROWS(treewithonenode->sum_at_level(0));
    CHECK_THROWS(treewithonenode->sum_at_level(2));
    CHECK(tree->sum_at_level(1)==5);
    CHECK(tree->sum_at_level(2)==10);
    CHECK(tree->sum_at_level(4)==(-50+11));
    tree->insert(33);
    CHECK(tree->sum_at_level(4)==(-50+11+33));
    tree->remove(10);
    CHECK(tree->sum_at_level(4)==(-50));
}
TEST_CASE("cousins"){
    CHECK_THROWS(treewithnoroot->cousins(1,2));
    CHECK(treewithonenode->cousins(10,10));
    CHECK(!tree->cousins(5,0));
    CHECK(tree->cousins(-100,11));
    CHECK(tree->cousins(-100,33));
    CHECK(tree->cousins(11,33));
}