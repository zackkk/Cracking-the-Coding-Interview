#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


bool anagram_cmp_func (string str1, string str2){
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	return str1 < str2;
}


class solution_9_2 {

public:
	void sortAnagrams(vector<string> &v){
		sort(v.begin(), v.end(), anagram_cmp_func);
	}
};

int main(){
	solution_9_2 *obj = new solution_9_2();
	vector<string> v;
	v.push_back("bb");
	v.push_back("abcd");
	v.push_back("abdc");
	v.push_back("acbd");
	v.push_back("ba");
	v.push_back("eeee");
	v.push_back("abbd");
	v.push_back("adaa");
	obj->sortAnagrams(v);
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}