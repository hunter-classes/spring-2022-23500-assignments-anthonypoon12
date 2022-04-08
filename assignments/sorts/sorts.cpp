#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}


int find_min_index(std::vector<int> a,
		   int start_index,
		   int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,j,tmp;
  int len = a.size();
  // loop through the vector from 0 to end
  for (i=0;i<len; i++){
    // find the smallest value from i to the end
    min_index = find_min_index(a,i,len);
    
    // swap it into position i
    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
    
  }
  return a;
}

/*
  left and right are already sorted

  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left,
		       std::vector<int> right){
  std::vector<int> merged;

  // your code here
  int l = 0;
  int r = 0;

  while (l < left.size() &&
	 r < right.size()){
    if (left[l] < right[r]){
      merged.push_back(left[l]);
      l++;
    } else {
      merged.push_back(right[r]);
      r++;
    }
  }

  // add any extra elements in left
  while (l < left.size()){
    merged.push_back(left[l]);
    l++;
  }
  

  // add any extra elements in right
  while (r < right.size()){
    merged.push_back(right[r]);
    r++;
  }
  	 
   
  return merged;
  
  
}
void printvectorparts(std::vector<int> list, int left, int right){
  std::string output = "";
  if (left>=0 && right<list.size()){
    for (int i = left; i <= right; i++){
      std::cout<<list[i];
      std::cout<<", ";
    }
    std::cout<<output<<"\n";
  }
}
std::vector<int> msort (std::vector<int> v){
  if (v.size()<=1)
    return v;
    std::vector<int> left;
    std::vector<int> right;
    for (int i = 0; i < v.size(); i++){
        if (i<v.size()/2)
            left.push_back(v[i]);
        else
            right.push_back(v[i]);
    }
    left = msort(left);
    right = msort(right);
    return merge(left,right);
}
std::vector <int> qsort(std::vector<int> list){
    
    // base case
    if (list.size() <=1){
        return list;
    }

    // select a pivot value.
    // for now, just pick list[0]
    int pivot = list[0];
    // make 2 new vectors
    std::vector<int> lower, higher;

    // copy all the values < pivot value to lower
    
    // copy all the values >= pivot value to higher

    for (int i = 1; i < list.size(); i++){
        if (list[i]<pivot){
            lower.push_back(list[i]);
        } else{
            higher.push_back(list[i]);
        }
    }
    lower = qsort(lower);
    higher = qsort(higher);

    // copy everything back into list
    int i;
    for (i = 0; i < lower.size(); i++){
        list[i] = lower[i];
    }
    list[i] = pivot;
    i++;
    int j;
    for (j=0; j < higher.size();j++){
        list[i] = higher[j];
        i++;
    }
    // return the sorted list
    return list;
}
void swap(std::vector<int> &list, int left, int right){
  int tmp = list[left];
  list[left] = list[right];
  list[right] = tmp;
}
int middlenum(std::vector<int> &list, int low, int high){
  if (high<=low)
    return low;
  int pivot = low;
  int a = low;
  int b = (high-low)/2 + low;
  int c = high;
  int la = list[a];
  int lb = list[b];
  int lc = list[c];
  if (la >= lb && la < lc)
    pivot = a;
  else if (la >= lc && la < lb)
    pivot = a;
  else if (lb >= la && lb < lc)
    pivot = b;
  else if (lb >= lc && lb < la)
    pivot = b;
  else if (lc >= lb && lc < la)
    pivot = c;
  else if (lc >= la && la < lb)
    pivot = c;
  return pivot;
}
std::vector <int> betterqsort(std::vector<int> list){
    
    // base case
    if (list.size() <=1){
        return list;
    }

    // select a pivot value.
    // for now, just pick list[0]
    int pivotind = middlenum(list, 0, list.size()-1);
    int pivot = list[pivotind];
    // make 2 new vectors
    std::vector<int> lower, higher;

    // copy all the values < pivot value to lower
    
    // copy all the values >= pivot value to higher

    for (int i = 0; i < list.size(); i++){
      if (i!=pivotind){
        if (list[i]<pivot){
            lower.push_back(list[i]);
        } else{
            higher.push_back(list[i]);
        }
      }
    }
    lower = qsort(lower);
    higher = qsort(higher);

    // copy everything back into list
    int i;
    for (i = 0; i < lower.size(); i++){
        list[i] = lower[i];
    }
    list[i] = pivot;
    i++;
    int j;
    for (j=0; j < higher.size();j++){
        list[i] = higher[j];
        i++;
    }
    // return the sorted list
    return list;
}
void moveleft(std::vector<int> &list, int &left, int pivot){
  while (left<pivot && list[left]<=list[pivot]){
        left++;
  }
}
void moveright(std::vector<int> &list, int &right, int pivot){
  while (right>pivot && list[right]>list[pivot]){
        right--;
  }
}
void qsort2(std::vector<int> &list, int low, int high){
  int left = low;
  int right = high;
  int pivot = low;
  if (high!=low && low<high){
    while (left <= pivot){
      moveleft(list,left,pivot);
      moveright(list,right,pivot);
      if (right==pivot)
        pivot = left;
      else if (left==pivot)
        pivot = right;
      swap(list, left, right);
      if (left==right){
        left++;
        right--;
      }
    }
    if (low<=pivot && high>=pivot && low!=high){
      qsort2(list, low, pivot-1);
      qsort2(list, pivot+1, high);
    }
  }
}
void betterqsort2(std::vector<int> &list, int low, int high){
  int left = low;
  int right = high;
  int pivot = middlenum(list,low,high);
  if (high!=low && low<high){
    while (left <= pivot){
      moveleft(list,left,pivot);
      moveright(list,right,pivot);
      if (right==pivot)
        pivot = left;
      else if (left==pivot)
        pivot = right;
      swap(list, left, right);
      if (left==right){
        left++;
        right--;
      }
    }
    if (low<=pivot && high>=pivot && low!=high){
      betterqsort2(list, low, pivot-1);
      betterqsort2(list, pivot+1, high);
    }
  }
}
std::vector<int> createvector(int size, int max_val){
  std::vector<int> a(size);
    int i;
    for (i=0;i<size; i++){
      a[i] = rand()%max_val;
    }
    return a;
}
void tests(std::vector<int> testvector, char s){
  struct timeval tp;
  gettimeofday(&tp,NULL);
  long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;
  std::vector<int> a = testvector;
  if (s=='m'){
    std::cout<<"merge sort on unsorted list for size: "<<testvector.size()<<"\n";
    a = msort(testvector);
    if (a.size()<100){
      print_vector(testvector);
      print_vector(a);
    }
  }
  else if (s=='r'){
    std::cout<<"bad quick sort on unsorted list for size: "<<testvector.size()<<"\n";
    a = qsort(testvector);
    if (a.size()<100){
      print_vector(testvector);
      print_vector(a);
    }
  }
  else if (s=='o'){
    std::cout<<"good quick sort on unsorted list for size: "<<testvector.size()<<"\n";
    a = betterqsort(testvector);
    if (a.size()<100){
      print_vector(testvector);
      print_vector(a);
    }
  }
  else if(s=='q'){
    std::cout<<"bad in place quick sort on unsorted list for size: "<<testvector.size()<<"\n";
    if (a.size()<100){
      print_vector(testvector);
      print_vector(a);
    }
    qsort2(a,0,a.size()-1);
    if (a.size()<100){
      print_vector(testvector);
      print_vector(a);
    }
  }
  else if(s=='a'){
    std::cout<<"good in place quick sort on unsorted list for size: "<<testvector.size()<<"\n";
    if (a.size()<100){
      print_vector(testvector);
      print_vector(a);
    }
    betterqsort2(a,0,a.size()-1);
    if (a.size()<100){
      print_vector(testvector);
      print_vector(a);
    }
  }
  gettimeofday(&tp,NULL);
  long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

  long elapsed = current_time - start_time;
  // print_vector(a);
  std::cout << "Time: " << elapsed << "\n";
  gettimeofday(&tp,NULL);
  start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;
  if (s=='m'){
    std::cout<<"merge sort on sorted list for size: "<<a.size()<<"\n";
    if (a.size()<100){
      print_vector(a);
    }
    a = msort(a);
    if (a.size()<100){
      print_vector(a);
    }
  }
  else if (s=='r'){
    std::cout<<"bad quick sort on sorted list for size: "<<a.size()<<"\n";
    if (a.size()<100){
      print_vector(a);
    }
    a = qsort(a);
    if (a.size()<100){
      print_vector(a);
    }
  }
  else if (s=='o'){
    std::cout<<"good quick sort on sorted list for size: "<<a.size()<<"\n";
    if (a.size()<100){
      print_vector(a);
    }
    a = betterqsort(a);
    if (a.size()<100){
      print_vector(a);
    }
  }
  else if(s=='q'){
    std::cout<<"bad in place quick sort on sorted list for size: "<<a.size()<<"\n";
    if (a.size()<100){
      print_vector(a);
    }
    qsort2(a,0,a.size()-1);
    if (a.size()<100){
      print_vector(a);
    }
  }
  else if(s=='a'){
    std::cout<<"good in place quick sort on sorted list on unsorted list for size: "<<a.size()<<"\n";
    if (a.size()<100){
      print_vector(a);
    }
    betterqsort2(a,0,a.size()-1);
    if (a.size()<100){
      print_vector(a);
    }
  }
  gettimeofday(&tp,NULL);
  current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

  elapsed = current_time - start_time;
  // print_vector(a);
  std::cout << "Time: " << elapsed << "\n";
}
int main(int argc, char *argv[])
  {
    int max_val = 100; 
    char algorithm = 'm' ; 
    bool print = false;
    srand(time(nullptr));
    std::vector<int> a;
    for(auto size : {10, 50, 100, 500, 1000, 10000, 25000}){
      std::cout<<"Size: " << size <<"\n";
      a = createvector(size,max_val);
      tests(a, 'm');
      tests(a, 'r');
      tests(a, 'o');
      tests(a, 'q');
      tests(a, 'a');
      std::cout<<"---------------------\n";
    }
    return 0;
  }