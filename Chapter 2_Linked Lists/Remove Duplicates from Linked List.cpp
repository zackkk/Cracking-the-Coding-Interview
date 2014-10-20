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

class solution_2_1{

public:

	// without temporary buffer
	Node* removeDuplicates(Node *head){
		if(head == nullptr) return nullptr;

		Node *dummy = new Node(-1);
		dummy->next = head; // bug happened here
		Node *prev = dummy;
		Node *cur = head;
		while(cur != nullptr){
			Node *nt = cur->next;
			Node *checker = dummy->next;
			while(checker != cur){
				if(checker->data == cur->data){
					prev->next = nt;
					break;
				}
				checker = checker->next;
			}
			// don't need to update when we broke above
			if(prev->next != nt) prev = cur;

			cur = nt;
		}
		return dummy->next;
	}
};

int main(){
	solution_2_1 *obj = new solution_2_1();
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(2);
	Node *n5 = new Node(3);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	Node *n = obj->removeDuplicates(n1);
	while(n != nullptr) { cout << n->data << endl; n = n->next; }
	return 0;
}