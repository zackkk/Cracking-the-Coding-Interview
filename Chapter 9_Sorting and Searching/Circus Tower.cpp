#include<iostream>
#include<vector>
using namespace std;

class solution_9_7 {

public:
	// sort by height (or weight), depends on the number of duplicates
	// use dp to find the Longest Increasing Sequence of weight
	
	int longestIncreasingSequence(vector<int> &arr){
		int sz = arr.size();
		vector<int> LIS (sz, 1);

		for(int i = 1; i < sz; i++){ // for all elements
			for(int j = 0; j < i; j++){ // check it previous sequence
				if(arr[j] < arr[i])
					LIS[i] = max(LIS[i], LIS[j]+1);
			}
		} 

		int ret = 0;
		for(int i : LIS)
			ret = max(ret, i);
		return ret;
	}

	// O(nlogn) solution: http://stackoverflow.com/questions/6129682/longest-increasing-subsequenceonlogn
};

int main(){
	solution_9_7 *obj = new solution_9_7();
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
	vector<int> v;
	v.assign(arr, arr + 8);
	cout << obj->longestIncreasingSequence(v) << endl;
	return 0;
}

