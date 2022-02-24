#include <iostream>
#include "funcs.h"
int main(){
	bool done = false;
	int** grid = new int*[20];
	for (int i = 0; i < 20; i++) {
        grid[i] = new int[20];
    }
	int lines = getgrid("grid.dat",grid);
	solve(grid,6,2, done, 0, lines);
	printgrid(grid,lines);
	return 0;
}
