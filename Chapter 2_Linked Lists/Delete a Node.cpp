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

class solution_2_3{

public:
	// give only access to the node to be deleted
	void deleteOneNode(Node *node){
		if(node == nullptr) return;
		if(node->next == nullptr){
			delete(node);
			return;
		}
		Node *nt = node->next;
		node->data = nt->data;
		node->next = nt->next;
		delete(nt);
		return;
	}
};

int main(){
	solution_2_3 *obj = new solution_2_3();
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	obj->deleteOneNode(n3);
	Node *n = n1;
	while(n != nullptr) { cout << n->data << " "; n = n->next; }
	return 0;
}