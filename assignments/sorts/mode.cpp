#include <iostream>
#include <vector>
#include "sorts.h"
int count(std::vector<int> v, int value){
    std::vector<int> sorted = msort(v);
    int result = 0;
    int i = 0;
    while(i<v.size() && sorted[i]<=value){
        if (sorted[i]==value)
            result++;
        i++;
    }
    return result;
}
int largest(std::vector<int> v){
    return msort(v).back();
}
int mode(std::vector<int> v){
    std::vector <int> sorted = msort(v);
    int output = 0;
    if (v.size()>0){
        int current = sorted[0];
        int count=0;
        int largest = 0;
        for (int i = 0; i<v.size();i++){
            if (current==sorted[i]){
                count++;
            }
            else{
                current = sorted[i];
                if (largest < count){
                    largest = count;
                    output = sorted[i-1];
                    count=0;
                }
            }
        }
        if (largest < count){
            output = sorted.back();
        }
    }
    return output;
}
int main(){
    std::vector <int> test = {1,245,4,31,35,73,5,6,8,1,1,1,15,15,31};
    std::cout<<"Test Vector 1: "<<"\n";
    print_vector(test);
    std::vector<int> test2 = {1,1,1,1,1,1};
    std::cout<<"Test Vector 2: "<<"\n";
    print_vector(test2);
    std::vector<int> test3 = {1,1,1,1,1,1,2,2,2,2,2,2,2,2,2};
    std::cout<<"Test Vector 3: "<<"\n";
    print_vector(test3);
    std::cout<<"Number of 1s in Test 1: "<<count(test,1)<<"\n";
    std::cout<<"Number of 245s in Test 1: "<<count(test,245)<<"\n";
    std::cout<<"Number of 15s in Test 1: "<<count(test,15)<<"\n";
    std::cout<<"Number of 1s in Test 2: "<<count(test2,1)<<"\n";
    std::cout<<"Number of 245s in Test 2: "<<count(test2,245)<<"\n";
    std::cout<<"Number of 1s in Test 3: "<<count(test3,1)<<"\n";
    std::cout<<"Number of 2s in Test 3: "<<count(test3,2)<<"\n";
    std::cout<<"largest number in Test1 is: "<<largest(test)<<"\n";
    std::cout<<"largest number in Test2 is: "<<largest(test)<<"\n";
    std::cout<<"largest number in Test3 is: "<<largest(test)<<"\n";
    std::cout<<"Mode of Test1 is: "<<mode(test)<<"\n";
    std::cout<<"Mode of Test2 is: "<<mode(test2)<<"\n";
    std::cout<<"Mode of Test3 is: "<<mode(test3)<<"\n";
    return 0;
}