#include<iostream>
#include<vector>
using namespace std;

class solution_1_6{

public:
	void rotateMatrix(vector<vector<int>> &matrix, int n){
		for(int layer = 0; layer < n/2; ++layer){
			int first = layer;
			int last = n - 1 - first;
			
			for(int i = first; i < last; ++i){
				int offset = i - first;

				// save top
				int top = matrix[first][i];

				// top <- left
				matrix[first][i] = matrix[last-offset][first];

				// left <- bottom
				matrix[last-offset][first] = matrix[last][last-offset];

				// bottom <- right
				matrix[last][last-offset] = matrix[i][last];

				// right <- top
				matrix[i][last] = top;

			}
		}
	}
};

int main(){
	solution_1_6 *obj = new solution_1_6();
	int arr[4][4] ={
		{1, 2, 3, 4},
		{12, 13, 14, 5},
		{11, 16, 15, 6},
		{10, 9, 8, 7}
	};
	vector<vector<int>> vec(4, vector<int>(4));
	for (int i = 0; i < 4; ++i){
		vec[i].assign(arr[i], arr[i] + 4);
	}
	cout << "after rotation: " << endl;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << vec[i][j] << "  ";
		}
		cout << endl;
	}
	obj->rotateMatrix(vec, 4);
	cout << "before rotation: " << endl;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << vec[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}

