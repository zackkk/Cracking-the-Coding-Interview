/*
20.2
	Write a method to shuffle a deck of cards. 
	It must be a perfect shuffle - in other words, each 52! permutations of the deck has to be equally likely. 
	Assume that you are given a random number generator which is perfect.
20.3
	Write a method to randomly generate a set of m integers from an array of size n. 
	Each element must have equal probability of being chosen.

*/


//            Array: [1] [2] [3] [4] [5]
//Randomly select 4: [4] [?] [?] [?] [?]
//Swap dead element: [X] [2] [3] [1] [5]

//            Array: [X] [2] [3] [1] [5]
//Randomly select 3: [4] [3] [?] [?] [?]
//Swap dead element: [X] [X] [2] [1] [5]

#include<iostream>
#include<vector>
#include<cstdlib>
#include <ctime>
using namespace std;

class solution_20_2 {

public:
	void perfectShuffle(vector<int> &cards){
		srand(time(NULL));
		int sz = cards.size();
		for(int i = 0; i < sz; i++){
			int random_num = rand() % (sz - i) + i; // rand() is not perfect
			swap(cards, i, random_num);
		}
	}

	void swap(vector<int> &v, int ia, int ib){
		int tmp = v[ia];
		v[ia] = v[ib];
		v[ib] = tmp;
	}
};

int main(){
	solution_20_2 *obj = new solution_20_2();

	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v;
	v.assign(arr, arr+10);
	obj->perfectShuffle(v);
	for(int j : v) cout << j << " ";
	cout << endl;

	return 0;
}