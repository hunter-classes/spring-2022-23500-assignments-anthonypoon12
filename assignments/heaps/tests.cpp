#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "heap.h"

int arr1[] = {4,7,9,1,0,2,-12,245,3,74,236};
int correctarr1[] = {-12,0,2,1,7,4,9,245,3,74,236};
int arr2[] = {900,1,-4,-20,-100,-75,0,-5,25,7,-3,-13,250};
int correctarr2[] = {-100,-20,-75,-5,-3,-13,0,900,25,7,1,-4,250};
TEST_CASE("heapify"){
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    CHECK(size1==11);
    heapify(arr1,size1);
    for (int i = 0; i < size1; i++)
        CHECK(arr1[i]==correctarr1[i]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    heapify(arr2,size2);
    for (int i = 0; i < size2; i++)
        CHECK(arr2[i]==correctarr2[i]);
}