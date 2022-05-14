#include "heap.h"
void heapsort(int data[]){
    int size = sizeof(data)/sizeof(data[0]);
    if (size>0){
        heapify(data, size);
    }
}
void heapify(int data[], int size){
    heapify(data, 0, size);
}
void heapify(int data[], int index, int size){
    if (index*2+1<size){
        heapify(data,index * 2 + 1);
        if (index*2 + 2<size){
            heapify(data, index *2 + 2);
            if (data[index*2+2]<data[index*2+1])
                if (data[index*2+2]<data[index])
                    swap(data, index,index*2+2);
        }
        if (data[index*2+1]<data[index])
            swap(data, index, index*2+1);
    }
}
void swap(int data[], int indone, int indtwo){
    int dummy = data[indone];
    data[indone] = data[indtwo];
    data[indtwo]=dummy;
}