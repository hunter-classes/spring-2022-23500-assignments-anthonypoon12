#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "stack.h"
#include "Queue.h"

stack *stack1 = new stack();
TEST_CASE("Creating a stack, checking errors for pop and top, checking is empty"){
    CHECK(stack1->is_empty()==true);
    CHECK_THROWS(stack1->pop());
    CHECK_THROWS(stack1->top());
}
TEST_CASE("Testing Push, Push, Top"){
    stack1->push(0);
    CHECK(!stack1->is_empty());
    stack1->push(1);
    CHECK(!stack1->is_empty());
    CHECK(stack1->top()==1);
    CHECK(stack1->pop()==1);
    CHECK(stack1->pop()==0);
    CHECK(stack1->is_empty());
    stack1->push(1);
    stack1->push(2);
    stack1->push(3);
    stack1->push(4);
    stack1->push(5);
    stack1->push(6);
    stack1->push(7);
    stack1->pop();
    stack1->pop();
    stack1->pop();
    stack1->pop();
    CHECK(stack1->top()==3);
    delete stack1;
}
Queue *queue1 = new Queue();
TEST_CASE("Testing enqueue and sequeue"){
    queue1->enqueue(1);
    CHECK(queue1->sequeue()==1);
    queue1->enqueue(1);
    queue1->enqueue(2);
    queue1->enqueue(3);
    queue1->enqueue(4);
    queue1->enqueue(5);
    CHECK_THROWS(queue1->enqueue(6));
    CHECK(queue1->sequeue()==1);
    CHECK(queue1->sequeue()==2);
    CHECK(queue1->sequeue()==3);
    CHECK(queue1->sequeue()==4);
    CHECK(queue1->sequeue()==5);
}
TEST_CASE("Testing is_empty and is_full"){
    CHECK(queue1->is_empty());
    CHECK(!queue1->is_full());
    queue1->enqueue(1);
    CHECK(!queue1->is_empty());
    CHECK(!queue1->is_full());
    queue1->enqueue(1);
    CHECK(!queue1->is_empty());
    CHECK(!queue1->is_full());
    queue1->enqueue(1);
    CHECK(!queue1->is_empty());
    CHECK(!queue1->is_full());
    queue1->enqueue(1);
    CHECK(!queue1->is_empty());
    CHECK(!queue1->is_full());
    queue1->enqueue(1);
    CHECK(!queue1->is_empty());
    CHECK(queue1->is_full());
    queue1->sequeue();
    CHECK(!queue1->is_empty());
    CHECK(!queue1->is_full());
    queue1->sequeue();
    CHECK(!queue1->is_empty());
    CHECK(!queue1->is_full());
    queue1->sequeue();
    CHECK(!queue1->is_empty());
    CHECK(!queue1->is_full());
    queue1->sequeue();
    CHECK(!queue1->is_empty());
    CHECK(!queue1->is_full());
    queue1->sequeue();
    CHECK(queue1->is_empty());
    CHECK(!queue1->is_full());
}
TEST_CASE("Testing front"){
    queue1->enqueue(13);
    CHECK(queue1->front()==13);
    queue1->enqueue(23);
    CHECK(queue1->front()==13);
    queue1->enqueue(33);
    CHECK(queue1->front()==13);
    queue1->enqueue(43);
    CHECK(queue1->front()==13);
    queue1->enqueue(53);
    CHECK(queue1->front()==13);
    queue1->sequeue();
    CHECK(queue1->front()==23);
    queue1->sequeue();
    CHECK(queue1->front()==33);
    queue1->sequeue();
    CHECK(queue1->front()==43);
    queue1->sequeue();
    CHECK(queue1->front()==53);
    delete queue1;
}