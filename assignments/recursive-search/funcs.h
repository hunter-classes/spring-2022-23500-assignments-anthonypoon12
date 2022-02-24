#pragma once
int getgrid(std::string filename, int **grid);
void printgrid(int **grid,int lines);
void plant(int **grid, int row, int col);
void solve (int **grid, int row, int col, bool &done, int num, int lines);