#include<iostream>
#include<string>
using namespace std;

class solution_1_8{

public:
	// assume have a method is subString
	// waterbottle <-> erbottlewat. 
	// waterbottle + waterbottle = wat erbottlewat erbottle
	bool decideTwoStringsRotations(string &str1, string &str2){
		string str = str1 + str1;
		if(str.find(str2) == string::npos){
			return false;
		}
		else 
			return true;
	}
};

/*
int main(){
	solution_1_8 *obj = new solution_1_8();
	string str1 = "waterbottle";
	string str2 = "erbottlewat";
	cout << obj->decideTwoStringsRotations(str1, str2) << endl;
	return 0;
}
*/