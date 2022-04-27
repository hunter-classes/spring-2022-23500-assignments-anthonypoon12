#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "stack.h"

stack *stack1 = new stack();
TEST_CASE("Creating a stack"){
    CHECK(stack1->is_empty()==true);
    CHECK_THROWS(stack1->pop());
    CHECK_THROWS(stack1->top());
}
TEST_CASE("Testing Push"){
    stack1->push(0);
    CHECK(!stack1->is_empty());
    stack1->push(1);
    CHECK(!stack1->is_empty());
    CHECK(stack1->top()==1);
    CHECK(stack1->pop()==1);
    CHECK(stack1->pop()==0);
    CHECK(stack1->is_empty());
}