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
void solve (std::string *grid, int row, int col){
	plant(grid,row,col);
}
//3,3 is the center of the 5x5 grid
int main(){
	std::string grid[20];
	int lines = getgrid("grid.dat",grid);
	printgrid(grid,lines);
	solve(grid,3,3);
	printgrid(grid,lines);
	return 0;
}
