#include<iostream>
#include<string>
using namespace std;

class solution_8_5 {

public:
	void printAllValidParentheses(int n){
		string str = "";
		helper(n, 0, 0, str);
	}

	void helper(int n, int left, int right, string &str){
		if(str.size() == n * 2){
			cout << str << endl;
			return;
		}

		if(left < n)
			helper(n, left+1, right, str+"(");
		if(right < left)
			helper(n, left, right+1, str+")");
	}
};

int main(){
	solution_8_5 *obj = new solution_8_5();
	obj->printAllValidParentheses(3);
	return 0;
}