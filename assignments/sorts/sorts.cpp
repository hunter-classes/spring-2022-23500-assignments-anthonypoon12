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

void swap(std::vector<int> &list, int left, int right){
  int tmp = list[left];
  list[left] = list[right];
  list[right] = tmp;
}
void qsort2(std::vector<int> &list, int low, int high){
  std::cout<< "Low:" << low << " High:" << high <<"\n";
  int left = low;
  int right = high;
  int pivot;
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
  printvectorparts(list,low,high);
  std::cout<<"pivot: "<<pivot<<"\n";
  std::cout<<list[pivot]<<"\n";
  while (left <= pivot){
    if (left < pivot){
      if (list[left]<=list[pivot]){
        left++;
      }
      else{
        while (right > pivot && list[right]>list[pivot]){
          right--;
        }
        if (right==pivot){
          pivot = left;
        }
        swap(list, left, right);
        std::cout<<left<<" "<< pivot << " " << right<<" : ";
        printvectorparts(list,left,right);
        std::cout<<"\n";
      }
    }
    else if (left == pivot){
        while (right > pivot && list[right]>list[pivot]){
          right--;
        }
        if (right!=pivot){
          pivot = right;
          swap(list, left, right);
          std::cout<<left<<" "<< pivot << " " << right<<" : ";
          printvectorparts(list,left,right);
          std::cout<<"\n";
        }
        else{
          left++;
          right--;
          printvectorparts(list,low,high);
          std::cout <<left << " and "<< right << " and " << pivot <<"\n";
        }
    }
  }
  if (low<high){
    qsort2(list, low, pivot-1);
    qsort2(list, pivot+1, high);
  }
}

int main()
{
  int size=20;
  int max_val=100;

  srand(time(nullptr));
  std::vector<int> a(size);
  int i;
  for (i=0;i<size; i++){
    a[i] = rand()%max_val;
  }
  print_vector(a);
  std::cout << "\n";
  qsort2(a, 0, a.size()-1);
  print_vector(a);
  // std::vector<int> left = {1,2,5,6,10,15};
  // std::vector<int> right = {3,7,8,12,16,19,20};
  // print_vector(left);
  // print_vector(right);
  // std::vector<int> m = merge(left,right);
  // print_vector(m);
  // std::vector<int> ms = {1,2,4,5,7,542,3,46,8,3,132467,48,5,372};
  // print_vector(msort(ms));
  return 0;
}
