#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int d){
		data = d;
		next = nullptr;
	}
};

// use an extra min stack, it is more space efficient than using an extra min field for each element

class solution_3_2{

private:
	Node *top;
	Node *bottom;
	Node *top_min;
	Node *bottom_min;

public:
	solution_3_2(){
		top = nullptr;
		bottom = nullptr;
		top_min = nullptr;
		bottom_min = nullptr;
	}

	void push(int d){
		if(top == nullptr && bottom == nullptr){
			top = new Node(d);
			bottom = top;
			top_min = new Node(d);
			bottom_min = top;
			return;
		}
		// normal stack
		Node *tmp = new Node(d);
		tmp->next = top;
		top = tmp;

		// min stack
		if(d <= top_min->data){
			Node *tmp_min = new Node(d);
			tmp_min->next = top_min;
			top_min = tmp_min;
		}
	}

	void pop(){
		if(top == nullptr) return;

		// normal stack
		Node *node = top;
		int ret = node->data;
		top = top->next;
		delete(node);


		// min stack
		if(ret == top_min->data){
			Node *node_min = top_min;
			top_min = top_min->next;
			delete(node_min);
		}
	}

	int getTopElement(){
		return top->data;
	}

	int getMinStackElement(){
		return top_min->data;
	}
};


int main(){
	solution_3_2 *obj = new solution_3_2();
	obj->push(3);
	obj->push(2);
	obj->push(1);
	obj->push(4);
	cout << obj->getMinStackElement() << endl;
	obj->pop();
	obj->pop();
	cout << obj->getMinStackElement() << endl;
	return 0;
}