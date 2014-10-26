/* Design a method to find the frequency of occurrences of any given word in a book.*/

// Query once: go through all words, O(N)
// Query multiple times: hash table

#include<map>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class solution_19_8 {

private:
	map<string, int> m;

public:
	void preprocess(vector<string> &words){
		for(string str : words)
			m[str]++;
	}

	int findFrequency(string str){
		return m[str];
	}
};

int main(){
	solution_19_8 *obj = new solution_19_8();
	vector<string> v;
	v.push_back("hello");
	v.push_back("hello");
	v.push_back("world");
	obj->preprocess(v);
	cout << obj->findFrequency("hell") << endl;
	cout << obj->findFrequency("hello") << endl;
	return 0;
}