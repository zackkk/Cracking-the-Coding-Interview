#include<iostream>
#include<string>
using namespace std;
class solution_1_3{

public:

	// without using additional buffer
	int removeDuplicateCharacters(string &str){
		int sz = str.size();
		if(sz == 0 || sz == 1) return sz;

		int slow = 0;
		int fast = 0;

		// check all previous characters 
		for(fast = 1; fast < sz; ++fast){
			bool flag = true;
			for(int i = fast - 1; i >= 0; --i){
				if(str[i] == str[fast]) { flag = false; break; }
			}
			if(flag){
				slow++;
				str[slow] = str[fast];
			}
		}
		return slow+1; // null terminator
	}
};

int main(){
	solution_1_3 *obj = new solution_1_3();
	string str = "hellohelloxyz";
	int len = obj->removeDuplicateCharacters(str);
	cout << str.substr(0,len) << endl;
	return 0;
}