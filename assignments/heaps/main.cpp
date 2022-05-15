#include <iostream>
#include "heap.h"
int main(){
    int arr[] = {4,7,9,1,0,2,-12,245,3,74,236};
    std::cout<<"Initial Array 1: ";
    for (auto x: arr)
        std::cout<<x<<", ";
    std::cout<<"\n";
    heapify(arr, sizeof(arr)/sizeof(arr[0]));
    std::cout<<"Heapified Array 1: ";
    for (auto x: arr)
        std::cout<<x<<", ";
    std::cout<<"\n";
    heapsort(arr, sizeof(arr)/sizeof(arr[0]));
    std::cout<<"Heapsorted Array 1: ";
    for (auto x: arr)
        std::cout<<x<<", ";
    std::cout<<"\n";
    int arr2[] = {900,1,-4,-20,-100,-75,0,-5,25,7,-3,-13,250};
    std::cout<<"Initial Array 2: ";
    for (auto x: arr2)
        std::cout<<x<<", ";
    std::cout<<"\n";
    heapify(arr2, sizeof(arr2)/sizeof(arr2[0]));
    std::cout<<"Heapified Array 2: ";
    for (auto x: arr2)
        std::cout<<x<<", ";
    std::cout<<"\n";
    heapsort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    std::cout<<"Heapsorted Array 2: ";
    for (auto x: arr2)
        std::cout<<x<<", ";
    std::cout<<"\n";
    
    return 0;
}