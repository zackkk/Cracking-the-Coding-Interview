#include<vector>
#include<stack>
using namespace std;

class solution_3_3{

private:
	vector<stack<int>*> stacks;
	int stack_num;
	int capacity;
	int current_stack_num;

public:
	solution_3_3(int sn, int c){
		current_stack_num = 0;
		stack_num = sn;
		int capacity = c;
		/* create one stack at the beginning */
		stack<int> *stk = new stack<int>();
		stacks.push_back(stk);
	}

	void push(int val){
		stack<int> *stk = stacks[current_stack_num];
		if(stk->size() < capacity){
			stk->push(val);
		}
		else{
			/* create a new stack */
			stack<int> *stk = new stack<int>();
			stacks.push_back(stk);
			current_stack_num++; // point to the next stack
			if(current_stack_num >= stack_num) return; // exception
			this->push(val); // push to the new stack
		}
	}

	int top(){
		stack<int> *stk = stacks[current_stack_num];
		if(stk->size() > 0){
			return stk->top();
		}
		else{
			delete(stk);
			current_stack_num--; // point to the previous stack
			if(current_stack_num < 0) return -1; // exception
			this->top(); // top from the previous stack
		}
	}

	void pop(){
		stack<int> *stk = stacks[current_stack_num];
		if(stk->size() > 0){
			stk->pop();
		}
		else{
			delete(stk);
			current_stack_num--; // point to the previous stack
			if(current_stack_num < 0) return; // exception
			this->pop(); // pop from the previous stack
		}
	}

	int popAt(){
	}

};