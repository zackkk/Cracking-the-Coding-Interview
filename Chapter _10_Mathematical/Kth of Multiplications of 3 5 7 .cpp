// Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7.
// main three queues
//		3, 3*3
//	    5, 3*5, 5*5
//      7, 3*7, 5*7, 7*7

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class solution_10_7 {

private:
	vector<int> sequence;

public:
	void generateSequence(int n){ // a sequence of size n
		queue<int> three;
		queue<int> five;
		queue<int> seven;
		three.push(3);
		five.push(5);
		seven.push(7);
		while(sequence.size() < n){
			if(three.front() < five.front() && three.front() < seven.front()){
				int tmp = three.front();
				three.pop();
				sequence.push_back(tmp);
				three.push(tmp*3);
				five.push(tmp*5);
				seven.push(tmp*7);
			}
			else if(five.front() < three.front() && five.front() < seven.front()){
				int tmp = five.front();
				five.pop();
				sequence.push_back(tmp);
				five.push(tmp*5);
				seven.push(tmp*7);
			}
			else{
				int tmp = seven.front();
				seven.pop();
				sequence.push_back(tmp);
				seven.push(tmp*7);
			}
		}
	}

	void printSequence(){
		for(auto it = sequence.begin(); it < sequence.end(); ++it)
			cout << *it << endl;
	}
};

int main(){
	solution_10_7 *obj = new solution_10_7();
	obj->generateSequence(20);
	obj->printSequence();
	return 0;
}