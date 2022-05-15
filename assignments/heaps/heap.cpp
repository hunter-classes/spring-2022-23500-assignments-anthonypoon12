#include "heap.h"
#include <iostream>
void heapsort(int data[], int size){
    while(size>0){
        heapify(data, size);
        swap(data, 0, size-1);
        size--;
    }
}
void heapify(int data[], int size){
    heapify(data, 0, size);
}
void heapify(int data[], int index, int size){
    if (index*2+1<size){
        heapify(data,index * 2 + 1, size);
        if (index*2 + 2<size){
            heapify(data, index * 2 + 2, size);
        }
    }
    sift_down(data, index, size);
}
void swap(int data[], int indone, int indtwo){
    int dummy = data[indone];
    data[indone] = data[indtwo];
    data[indtwo]=dummy;
}
void sift_down(int data[], int index, int size){
    if (index*2+1<size){
        if (index*2+2<size){
            if (data[index*2+2]>data[index*2+1]){
                if (data[index*2+2]>data[index]){
                    swap(data,index,index*2+2);
                    sift_down(data, index*2+2,size);
                    return;
                }
            }
        }
        if (data[index*2+1]>data[index]){
            swap(data,index,index*2+1);
            sift_down(data, index*2+1,size);
        }
    }
}