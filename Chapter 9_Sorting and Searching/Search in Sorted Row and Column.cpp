#include<iostream>
#include<vector>
using namespace std;

class solution_9_6 {

public:
	// works by elimination
	// start from the right-top corner
	void search(vector<vector<int>> &matrix, int target){
		int x = 0;
		int y = matrix[0].size() - 1;
		while(true){
			if(x > matrix.size() || y < 0){
				cout << "not found" << endl; 
				return;
			}

			if(target == matrix[x][y]){
				cout << "found" << endl; 
				return;
			}
			else if(target > matrix[x][y]){
				x++;
			}
			else{
				y--;
			}
		}
	}
};