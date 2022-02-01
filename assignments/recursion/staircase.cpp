#include <iostream>
#include <cmath>
/*
stepPerms
Parameters: int n representing number of stairs in staircase
returns: int number of ways you can clumb the staircase in 1, 2, or 3 steps at a time modulo 10^10 + 7 
*/

int stepPerms(int n) {
    int output = 0;
    if (n==1)
        return 1;
    if (n-3>1)
        output+= stepPerms(n-3);
    else if (n-3 >= 0 && n-3 <=1)
        output++;
    if (n-2>1)
        output+= stepPerms(n-2);
    else if (n-2 >= 0 && n-2 <=1)
        output++;
    if (n-1>1)
        output+= stepPerms(n-1);
    else if (n-1 >= 0 && n-1 <=1)
        output++;
    return output % (int(pow(10,10) + 7));
}