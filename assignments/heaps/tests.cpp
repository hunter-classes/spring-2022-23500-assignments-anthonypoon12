#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "heap.h"

int arr1[] = {4,7,9,1,0,2,-12,245,3,74,236};
int arr11[] = {4,7,9,1,0,2,-12,245,3,74,236};
int correctarr1[] = {245, 236, 9, 7, 74, 2, -12, 1, 3, 4, 0};
int sortedarr1[] = {-12, 0, 1, 2, 3, 4, 7, 9, 74, 236, 245};
int arr2[] = {900,1,-4,-20,-100,-75,0,-5,25,7,-3,-13,250};
int arr22[] = {900,1,-4,-20,-100,-75,0,-5,25,7,-3,-13,250};
int correctarr2[] = {900, 25, 250, 1, 7, -4, 0, -5, -20, -100, -3, -13, -75};
int sortedarr2[] = {-100, -75, -20, -13, -5, -4, -3, 0, 1, 7, 25, 250, 900};
int size1 = sizeof(arr1)/sizeof(arr1[0]);
int size2 = sizeof(arr2)/sizeof(arr2[0]);
TEST_CASE("heapify"){
    CHECK(size1==11);
    heapify(arr1,size1);
    for (int i = 0; i < size1; i++)
        CHECK(arr1[i]==correctarr1[i]);
    heapify(arr2,size2);
    for (int i = 0; i < size2; i++)
        CHECK(arr2[i]==correctarr2[i]);
}
TEST_CASE("heapsort"){
    heapsort(arr1, size1);
    heapsort(arr2, size2);
    heapsort(arr11, size1);
    heapsort(arr22, size2);
    for (int i=0;i<size1;i++)
        CHECK(arr1[i]==sortedarr1[i]);
    for (int i=0;i<size2;i++)
        CHECK(arr2[i]==sortedarr2[i]);
    for (int i=0;i<size1;i++)
        CHECK(arr11[i]==sortedarr1[i]);
    for (int i=0;i<size2;i++)
        CHECK(arr22[i]==sortedarr2[i]);
}