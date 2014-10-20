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

class solution_2_4{

public:
	// input: (3->1->5) + (5->9->2)
	// output: 8->0->8
	Node *addTwoLinkedList(Node *&l1, Node *&l2){
		Node *dummy = new Node(-1);
		Node *prev = dummy;
		int carry = 0;
		while(l1 != nullptr || l2 != nullptr || carry != 0){
			int sum = carry;
			if(l1 != nullptr){
				sum += l1->data;
				l1 = l1->next;
			}
			if(l2 != nullptr){
				sum += l2->data;
				l2 = l2->next;
			}
			Node *node = new Node(sum % 10);
			prev->next = node;
			prev = node;
			carry = sum / 10;
		}
		return dummy->next;
	}
};

int main(){
	solution_2_4 *obj = new solution_2_4();
	Node *n11 = new Node(3);
	Node *n12 = new Node(1);
	Node *n13 = new Node(5);
	Node *n21 = new Node(5);
	Node *n22 = new Node(9);
	Node *n23 = new Node(2);
	n11->next = n12;
	n12->next = n13;
	n21->next = n22;
	n22->next = n23;
	Node *n = obj->addTwoLinkedList(n11, n21);
	while(n != nullptr) { cout << n->data << " "; n = n->next; }
	return 0;
}