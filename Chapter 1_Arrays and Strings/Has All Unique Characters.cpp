#include <iostream>
#include <string>
#include <map>
using namespace std;

class solution_1_1{

public:
	// map hash
	bool hasAllUniqueCharacters(string str){
		map<char, int> m;
		for(int i = 0; i < str.size(); i++){
			if(m[str[i]]) return false;
			m[str[i]]++;
		}
		return true;
	}

	// two loops
	bool hasAllUniqueCharacters2(string str){
		for(int i = 0; i < str.size(); i++){
			for(int j = 0; j < str.size(); j++){
				if(i != j && str[i] == str[j])
					return false;
			}
		}
		return true;
	}

	// hash: point: ask range
	// 26 letters -> bit
	// 256 chars -> ASCII 

	// without using extra data structures
	// sort -> O(nlogn) + O(n)

};

int main(){
	solution_1_1 *obj = new solution_1_1();
	cout << obj->hasAllUniqueCharacters("abcdefghi") << endl;
	cout << obj->hasAllUniqueCharacters("abcdefghia") << endl;
	cout << obj->hasAllUniqueCharacters2("abcdefghi") << endl;
	cout << obj->hasAllUniqueCharacters2("abcdefghia") << endl;

	return 0;
}