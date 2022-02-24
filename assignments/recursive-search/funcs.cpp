#include <iostream>
#include <fstream>
#include <unistd.h>
#include <iomanip>
#include "funcs.h"

char empty = -1;
char notvisited = 0;

int getgrid(std::string filename, int **grid){
	std::ifstream infile(filename);
	int i=0;
	std::string placeholder;
	while(std::getline(infile, placeholder)){
		i++;
		for (int j = 0; j < placeholder.size(); j++){
			if (placeholder[j]==' ')
				grid[i-1][j]=-1;
			else
				grid[i-1][j]=0;
		}
	}
	return i;
}
void printgrid(int **grid,int lines){
	// std::cout << "[0;0H\n";
	for (int i = 0; i < lines; i++){
		for (int j = 0; j < lines; j++){
			if (grid[i][j]!=-1)
			// 	std::cout<<std::setw(3)<<".";
			// else
				std::cout<<std::setw(3)<<grid[i][j];
		}
		std::cout<<"\n";
	}
}
void plant(int **grid, int row, int col){
	if (grid[row][col]==notvisited)
		grid[row][col]=1;
	else
		std::cout<<"You can not plant a knight in that location\n";
}
void solve (int **grid, int row, int col, bool &done, int num, int lines){
	// plant(grid,row,col);
	// usleep(800);
	// printgrid(grid, lines);
	if (grid[row][col]==notvisited){
		grid[row][col] = num+1;
		if (!done) solve(grid, row-2, col-1,done,num+1, lines);
		if (!done) solve(grid, row-2, col+1,done,num+1, lines);
		if (!done) solve(grid, row-1, col-2,done,num+1, lines);
		if (!done) solve(grid, row-1, col+2,done,num+1, lines);
		if (!done) solve(grid, row+2, col+1,done,num+1, lines);
		if (!done) solve(grid, row+2, col-1,done,num+1, lines);
		if (!done) solve(grid, row+1, col-2,done,num+1, lines);
		if (!done) solve(grid, row+1, col+2,done,num+1, lines);
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
	else{
		for (int i = 0; i < lines; i++){
			for (int j = 0; j < lines;j++){
				if (grid[i][j]>num)
					grid[i][j]=notvisited;
			}
		}
	}
}
