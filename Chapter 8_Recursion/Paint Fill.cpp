#include<iostream>
#include<vector>
using namespace std;

class solution_8_6 {

public:
	void paintFill(vector<vector<char>> &grid, int x, int y, char oldColor, char newColor){
		if(x < 0 || x > grid.size()) return;
		if(y < 0 || y > grid[0].size()) return;
		if(grid[x][y] != oldColor) return;

		grid[x][y] = newColor;
		paintFill(grid, x-1, y, oldColor, newColor);
		paintFill(grid, x+1, y, oldColor, newColor);
		paintFill(grid, x, y-1, oldColor, newColor);
		paintFill(grid, x, y+1, oldColor, newColor);
	}

};