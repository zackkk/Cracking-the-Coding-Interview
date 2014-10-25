// maintain a queue of size k

#include<iostream>
#include<queue>
using namespace std;

class solution_13_1 {

private:
	queue<int> data_set;
	int k;

public:
	solution_13_1(int sz){
		k = sz;
	}

	void read(int i){   // treat an integer as one line
		data_set.push(i);
		if(data_set.size() == k + 1) { data_set.pop(); }
	}

	void printKLines(){
		while(!data_set.empty()){
			int tmp = data_set.front();
			data_set.pop();
			cout << tmp << " ";
		}
		cout << endl;
	}

};

int main(){
	solution_13_1 *obj = new solution_13_1(5); // last five integers
	obj->read(1);
	obj->read(2);
	obj->read(3);
	obj->read(4);
	obj->read(5);
	obj->read(6);
	obj->read(7);
	obj->read(8);
	obj->printKLines();
	return 0;
}