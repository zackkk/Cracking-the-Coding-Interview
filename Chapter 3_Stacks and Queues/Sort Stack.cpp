#include<iostream>
#include<stack>
using namespace std;

class solution_3_6{

public:
	// kind of insertion sort
	stack<int> sortStack(stack<int> unsorted){
		stack<int> sorted;
		while(!unsorted.empty()){
			int tmp = unsorted.top();
			unsorted.pop();
			while(!sorted.empty() && tmp > sorted.top()){
				unsorted.push(sorted.top());
				sorted.pop();
			}
			sorted.push(tmp);
		}
		return sorted;
	}
};

int main(){
	solution_3_6 *obj = new solution_3_6();
	stack<int> s;
	s.push(3);
	s.push(2);
	s.push(4);
	s.push(1);
	stack<int> ss = obj->sortStack(s);
	while(!ss.empty()){
		cout << ss.top() << endl;
		ss.pop();
	}
	return 0;
}