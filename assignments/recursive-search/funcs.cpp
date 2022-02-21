#include <iostream>
#include <fstream>

char knight = 'N';
char empty = ' ';
char notvisited = 'X';

int getgrid(std::string filename, std::string *grid){
	std::ifstream infile(filename);
	int i=0;
	while(std::getline(infile,grid[i]))
		i++;
	return i;
}
void printgrid(std::string grid[],int lines){
for (int i = 0; i < lines; i++)
	std::cout<<grid[i]<<"\n";
}
void plant(std::string *grid, int row, int col){
	if (grid[row][col]==notvisited)
		grid[row][col]=knight;
	else
		std::cout<<"You can not plant a knight in that location\n";
}
void solve (std::string *grid, int row, int col, bool &done, int num, int lines){
	// plant(grid,row,col);
	if (grid[row][col]==notvisited){
		if (!done)
			solve(grid, row-2, col-1,done,num+1, lines);
		if (!done)
			solve(grid, row-2, col+1,done,num+1, lines);
		if (!done)
			solve(grid, row-1, col-2,done,num+1, lines);
		if (!done)
			solve(grid, row-1, col+2,done,num+1, lines);
		if (!done)
			solve(grid, row+2, col+1,done,num+1, lines);
		if (!done)
			solve(grid, row+2, col-1,done,num+1, lines);
		if (!done)
			solve(grid, row+1, col-2,done,num+1, lines);
		if (!done)
			solve(grid, row+1, col+2,done,num+1, lines);
	}
	else{
		return;
	}
	int count = 0;
	for (int i = 0; i < lines; i++){
		for (int j = 0; j < lines;j++){
			if (grid[i][j]==notvisited)
				count++;
		}
	}
	if (count==0)
		done=true;
	if (done)
		grid[row][col]=num;
	else{
		for (int i = 0; i < lines; i++){
			for (int j = 0; j < lines;j++){
				if (grid[i][j]>num)
					//get rid of all numbers above a certain part
			}
		}

	}
}
int main(){
	bool done = false;
	std::string grid[20];
	int lines = getgrid("grid.dat",grid);
	printgrid(grid,lines);
	solve(grid,3,3, done, 0, lines);
	printgrid(grid,lines);
	return 0;
}
