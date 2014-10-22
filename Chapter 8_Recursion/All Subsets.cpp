#include<iostream>
#include<vector>
using namespace std;

class solution_8_3 {

public:

	// solution 1: []
	//			   [] [1]
	//			   [] [1] [2] [1,2]
	// solution 2:
	//			   0,0 -> []
	//			   0,1 -> [1]
	//			   1,0 -> [2]
	//			   1,1 -> [1,2]

	// implementation for solution 2
	void allSubsets(vector<int> &set){
		int bits = set.size();
		int n = pow(2, bits);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < bits; j++){
				if((i >> j) & 1){
					cout << set[j] << " ";
				}
			}
			cout << endl;
		}
	}

};

int main(){
	solution_8_3 *obj = new solution_8_3();
	vector<int> set;
	set.push_back(1);
	set.push_back(2);
	set.push_back(3);
	obj->allSubsets(set);
	return 0;
}