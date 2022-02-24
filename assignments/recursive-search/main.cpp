#include <iostream>
#include "funcs.h"
int main(){
	bool done = false;
	int** grid = new int*[20];
	for (int i = 0; i < 20; i++) {
        grid[i] = new int[20];
    }
	int lines = getgrid("grid.dat",grid);
	std::cout<<"upper left corner is (0,0),\nbottom right corner is (4,0),\ntop right corner is (0,4),\n bottom right corner is (4,4)\nknight starting point is (0,0)\n";
	solve(grid,2,2, done, 0, lines);
	printgrid(grid,lines);
	for (int i = 0; i < 20; i++)
		for (int j = 0; j<20; j++)
			if (grid[i][j]!=-1)
				grid[i][j]=0;
	done=false;
	std::cout<<"knight starting at (3,3)\n";
	solve(grid,4,4, done, 0, lines);
	printgrid(grid,lines);
	return 0;
}
