#include<iostream>
#include<string>
#include<map>
using namespace std;

class solution_1_4{

public:
	// space in the string?

	// count the apprerance for each char
	bool decideTwoStringsAnagrams(string &str1, string &str2){
		if(str1.size() != str2.size()) return false;
		map<char, int> m;
		for(int i = 0; i < str1.size(); i++)
			m[str1[i]]++;
		for(int i = 0; i < str2.size(); i++){
			if(!m[str2[i]] || m[str2[i]] == 0)
				return false;
			m[str2[i]]--;
		}
		return true;
	}

	// sort 
};

int main(){
	solution_1_4 *obj = new solution_1_4();
	string str1 = "helloworld";
	string str2 = "lloowrldee";
	cout << obj->decideTwoStringsAnagrams(str1, str2) << endl;
	return 0;
}