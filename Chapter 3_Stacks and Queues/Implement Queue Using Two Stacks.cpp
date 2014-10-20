#include<iostream>
#include<stack>
using namespace std;

class solution_3_5{

private:
	stack<int> *in;
	stack<int> *out;

public:
	solution_3_5(){
		in = new stack<int>();
		out = new stack<int>();
	}
	~solution_3_5(){
		delete(in);
		delete(out);
	}

	void push(int d){
		in->push(d);
	}

	int front(){
		int ret = 0;
		if(out->empty()){
			// push all elements from in to out
			while(!in->empty()){
				int tmp = in->top();
				in->pop();
				out->push(tmp);
			}
		}
		
		if(!out->empty()){
			ret = out->top();
		}

		return ret;
	}

	void pop(){
		if(!out->empty())
			out->pop();
	}
};

int main(){
	solution_3_5 *obj = new solution_3_5();
	obj->push(1);
	obj->push(2);
	obj->push(3);
	obj->push(4);
	cout << obj->front() << endl;
	obj->pop();
	obj->pop();
	cout << obj->front() << endl;
	obj->push(5);
	cout << obj->front() << endl;
	return 0;
}