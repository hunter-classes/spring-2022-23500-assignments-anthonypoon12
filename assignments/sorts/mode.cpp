#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}
int count(std::vector<int> v, int value){
    int output=0;
    for (auto i: v){
        if (i==value)
            output++;
    }
    return output;
}
int largest(std::vector<int> v){
    int max = v[0];
    for (auto i: v){
        if (i>max)
            max=i;
    }
    return max;
}
int mode(std::vector<int> v){
    std::vector<int> values;
    std::vector<int> counts;
    for (int i: v){
        if (count(values,i)==0)
            values.push_back(i);
    }
    int max = 0;
    int output = 0;
    for (int i: values){
        int placeholder = count(v,i);
        if (placeholder>max){
            max = placeholder;
            output = i;
        }
    }
    return output;
}
int mode2(std::vector<int> v){
    std::vector<int> counts(largest(v)+1);
    for(int i: v){
        counts[i]++;
    }
    int maxindex = 0;
    for (int i = 0; i < counts.size();i++){
        if (counts[maxindex]<counts[i])
            maxindex=i;
    }
    return maxindex;
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
    std::cout<<"largest number in Test2 is: "<<largest(test2)<<"\n";
    std::cout<<"largest number in Test3 is: "<<largest(test3)<<"\n";
    std::cout<<"Mode of Test1 is: "<<mode(test)<<"\n";
    std::cout<<"Mode of Test2 is: "<<mode(test2)<<"\n";
    std::cout<<"Mode of Test3 is: "<<mode(test3)<<"\n";
    std::cout<<"Mode of Test1 is: "<<mode2(test)<<"\n";
    std::cout<<"Mode of Test2 is: "<<mode2(test2)<<"\n";
    std::cout<<"Mode of Test3 is: "<<mode2(test3)<<"\n";
    std::srand(std::time(nullptr));
    std::vector<int> randoms;
    for (int i = 0; i < 8000; i++)
        randoms.push_back(std::rand()%1000);
    std::cout<<"Mode of random vector is: "<<mode(randoms)<<"\n";
    std::cout<<"Mode of random vector is: "<<mode2(randoms)<<"\n";
    return 0;
}