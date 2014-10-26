/* You are given an array of integers (both positive and negative). 
   Find the continuous sequence with the largest sum. Return the sum.
   EXAMPLE
   Input: {2, -8, 3, -2, 4, -10}
   Output: 5 (i.e., {3, -2, 4} )  */

// Leetcode

#include<vector>
#include<iostream>
using namespace std;

class solution_19_7 {

public:
	int findMaxSubarray(vector<int> &arr){
		int ret = INT_MIN;
		int sum = 0;
		for(int i = 0; i < arr.size(); i++){
			sum = max(sum + arr[i], arr[i]);
			ret = max(ret, sum);
		}
		return ret;
	}
};

int main(){
	int a[] = {2, -8, 3, -2, 4, -10};
	vector<int> arr;
	arr.assign(a, a + 6);

	solution_19_7 *obj = new solution_19_7();
	cout << obj->findMaxSubarray(arr) << endl;
	return 0;
}