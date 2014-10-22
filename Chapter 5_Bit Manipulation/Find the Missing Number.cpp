#include<iostream>
#include<vector>
using namespace std;

class solution_5_7 {

public:
	int fetchTheJthBit(int num, int j){
		return (num >> j) & 1;
	}

	// arr[100] has one number missed 
	int findTheMissingNumber(int arr[], int n){
		int ret = 0;
		
		for(int j = 0; j < 32; j++){
			int curBit = 0;
			for(int i = 0; i < n; i++){
				curBit ^= fetchTheJthBit(arr[i], j); 
			}
			ret |= (curBit << j);
		}
		return ret;
	}

	// optimize a little bit, don't have to go through all bits of all numbers

	// assume there are even number of input integers
	// so the number of odds and evens will always diff one with one number missing
	// we can check the last number to easily satisfy our assumption
	// O(n) + O(n/2) + ... O(1) = O(2n)
	int findTheMissingNumber(vector<int> input, int column){
		if(column < 0) return 0;

		vector<int> evens;
		vector<int> odds;
		for(int i = 0; i < input.size(); i++){
			if(fetchTheJthBit(input[i], column) == 1) 
				odds.push_back(input[i]);
			else
				evens.push_back(input[i]);
		}
		
		if(evens.size() <= odds.size()){
			findTheMissingNumber(evens, column-1) << 1 | 0; // this bit is 0
		}
		else
			findTheMissingNumber(odds, column-1) << 1 | 1; // this bit is 1
	}
}; 

int main(){
	solution_5_7 *obj = new solution_5_7();
	int arr[] = {0,1,2,3,4,5,7,8,9,10,11,12,13,14,15};
	cout << obj->findTheMissingNumber(arr, 15) << endl; 
	return 0;
}