#include <iostream>
#include <fstream>
#include <unistd.h>

char knight = 'N';
char empty = ' ';
char notvisited = 'X';

int getgrid(std::string filename, std::string **grid){
	std::ifstream infile(filename);
	std::string placeholder[20];
	int i=0;
	while(std::getline(infile,placeholder[i]))
		i++;
	return i;
}
// void printgrid(std::string grid[][20],int lines){
// 	std::cout << "[0;0H\n";
// 	for (int i = 0; i < lines; i++){
// 		for (int j = 0; j < lines; j++)
// 			std::cout<<grid[i][j];
// 		std::cout<<"\n";
// 	}
// }
// void plant(std::string *grid, int row, int col){
// 	if (grid[row][col]==notvisited)
// 		grid[row][col]=knight;
// 	else
// 		std::cout<<"You can not plant a knight in that location\n";
// }
// void solve (std::string *grid, int row, int col, bool &done, int num, int lines){
// 	// plant(grid,row,col);
// 	if (grid[row][col]==notvisited){
// 		grid[row][col] = "" + (num+1);
// 		if (!done)
// 			solve(grid, row-2, col-1,done,num+1, lines);
// 		if (!done)
// 			solve(grid, row-2, col+1,done,num+1, lines);
// 		if (!done)
// 			solve(grid, row-1, col-2,done,num+1, lines);
// 		if (!done)
// 			solve(grid, row-1, col+2,done,num+1, lines);
// 		if (!done)
// 			solve(grid, row+2, col+1,done,num+1, lines);
// 		if (!done)
// 			solve(grid, row+2, col-1,done,num+1, lines);
// 		if (!done)
// 			solve(grid, row+1, col-2,done,num+1, lines);
// 		if (!done)
// 			solve(grid, row+1, col+2,done,num+1, lines);
// 	}
// 	else{
// 		return;
// 	}
// 	int count = 0;
// 	for (int i = 0; i < lines; i++){
// 		for (int j = 0; j < lines;j++){
// 			if (grid[i][j]==notvisited)
// 				count++;
// 		}
// 	}
// 	if (count==0)
// 		done=true;
// 	if (done)
// 		grid[row][col]=num;
// 	else{
// 		for (int i = 0; i < lines; i++){
// 			for (int j = 0; j < lines;j++){
// 				if (grid[i][j]>num)
// 					grid[i][j]=notvisited;
// 			}
// 		}
// 	}
// 	usleep(80000);
// 	printgrid(grid, lines);
// }
int main(){
	bool done = false;
	std::string grid[20][20];
	int lines = getgrid("grid.dat",grid);
	// printgrid(grid,lines);
	// solve(grid,3,3, done, 0, lines);
	// printgrid(grid,lines);
	return 0;
}
