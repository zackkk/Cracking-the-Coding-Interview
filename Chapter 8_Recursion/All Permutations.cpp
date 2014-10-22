#include<iostream>
#include<string>
#include<vector>
using namespace std;

class solution_8_4 {

public:
	// permutation: {1,2,3} -> {1,2,3}{1,3,2}{2,1,3}{2,3,1}{3,1,2}{3,2,1}
	void allPermutations(string &input, string &str){
		if(str.size() == input.size()){
			cout << str << endl;
			return;
		}
		for(int i = 0; i < input.size(); i++){
			if(str.find(input[i]) == string::npos){
				str += input[i];
				allPermutations(input, str);
				str.pop_back();
			}
		}
	}

	// alternative: insertion
	// insert 1: {1}
	// insert 2: {2,1} {1,2}
	// insert 3: {3,2,1} {2,3,1} {2,1,3} ...
	void allPermutations2(string &input){
		//...
	}
};

int main(){
	solution_8_4 *obj = new solution_8_4();
	string input = "123";
	string str = "";
	obj->allPermutations(input, str);
}