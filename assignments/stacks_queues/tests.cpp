#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "stack.h"

stack *stack1 = new stack();
Node *node1 = new Node(1);
TEST_CASE("Creating a stack"){
    CHECK(stack1->is_empty()==true);
    CHECK_THROWS(stack1->pop());
    CHECK_THROWS(stack1->top());
}