#include<iostream>
#include<string>
#include<vector>
using namespace std;

class solution_9_5 {

public:

	// binary search with empty strings
	int binarySearch(vector<string> &v, string str){
		return helper(v, str, 0, v.size()-1);
	}

	int helper(vector<string> &v, string &str, int low, int high){
		if(low > high) return -1;
		int mid = (low + high) / 2;
		while(v[mid] == "" && mid < high) mid++;

		if(v[mid] == str) 
			return mid;
		else if(v[mid] > str)
			return helper(v, str, low, mid-1);
		else
			return helper(v, str, mid+1, high);
	}
};


int main(){
	solution_9_5 *obj = new solution_9_5();
	vector<string> v;
	v.push_back("at");
	v.push_back("");
	v.push_back("");
	v.push_back("");
	v.push_back("ball");
	v.push_back("");
	v.push_back("");
	v.push_back("car");
	v.push_back("");
	v.push_back("");
	v.push_back("dad");
	v.push_back("");
	v.push_back("");
	string str = "carcar";
	cout << obj->binarySearch(v, str) << endl;
	return 0;
}