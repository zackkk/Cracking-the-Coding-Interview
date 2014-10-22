#include<vector>
#include<iostream>
using namespace std;

/********** classic question **********/

class solution_8_8 {

private:
	int ways;

public:
	solution_8_8(){
		ways = 0;
	}
	~solution_8_8(){}

	// print all ways
	int eightQueens(){
		vector<int> v; // represent col num, eliminate row dups automatically.
		dfs(v, 0);
		return ways;
	}

	void dfs(vector<int> &v, int cur){
		if(cur == 8){
			ways++;
			return;
		}

		for(int i = 0; i < 8; i++){
			if(isValid(v, cur, i)){
				v.push_back(i);
				dfs(v, cur+1); // fill next row
				v.pop_back();
			}
		}
	}

	bool isValid(vector<int> &v, int row, int col){
		for(int i = 0; i < row; i++){
			if(v[i] == col || (row - i) == abs(col - v[i]))
				return false;
		}
		return true;
	}

};

int main(){
	solution_8_8 *obj = new solution_8_8();
	cout << obj->eightQueens() << endl;
	return 0;
}