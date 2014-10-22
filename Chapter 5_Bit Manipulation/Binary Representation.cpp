#include<iostream>
#include<string>
using namespace std;

class solution_5_2 {

public:
	string binaryRepresentation(string str){
		/* string parse */
		string left;
		string right;
		bool dot = false;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '.') { dot = true; continue; }
			if(!dot) left += str[i];
			else right += str[i];
		}

		// first part
		string ret;
		int tmp = stoi(left);
		while(tmp > 1){
			ret += to_string(tmp % 2);
			tmp /= 2;
		}
		ret += to_string(tmp);
		reverse(ret.begin(), ret.end());
		if(!dot) return ret;
		
		// second part
		// transfer the "right" part into double
		// ...
	}

};

int main(){
	solution_5_2 *obj = new solution_5_2();
	cout << obj->binaryRepresentation("25") << endl;
	return 0;
}