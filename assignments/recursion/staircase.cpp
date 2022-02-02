#include <iostream>
#include <cmath>
/*
stepPerms
Parameters: int n representing number of stairs in staircase
returns: int number of ways you can clumb the staircase in 1, 2, or 3 steps at a time modulo 10^10 + 7 
*/

int stepPerms(int n) {
    if (n<3)
        return n;
    if (n==3)
        return 4;
    return (stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3)) % int(std::pow(10,10) + 7);
}
int main(){
    std::cout<<"input : output \n";
    for (int x : {1,2,3,4,5,10,20,15}){
        std::cout << x << " : " << stepPerms(x) << "\n";
    }
    return 0;
}