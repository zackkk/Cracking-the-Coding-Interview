/* Design an algorithm to find all pairs of integers within an array which sum to a specified value. */

#include<vector>
#include<iostream>
#include<map>
using namespace std;

class solution_19_11 {

public:
	void twoSum(vector<int> &arr, int target){
		map<int, int> m; // used as hash table, <value, index>
		for(int i = 1; i <= arr.size(); i++){ // defaults are 0, so we start from 1
			int value = arr[i - 1];
			m[value] = i;
			if(m[target - value] != 0){
				int index = m[target - value] - 1;
				cout <<  arr[index] << " " << value << endl;
			}
		}
	}
};

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	vector<int> arr;
	arr.assign(a, a+9);

	solution_19_11 *obj = new solution_19_11();
	obj->twoSum(arr, 10);
	return 0;
}