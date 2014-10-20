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

class solution_2_2{

public:
	// slow & fast pointers
	Node *findNthToLastElement(Node *head, int n){
		if(head == nullptr) return nullptr;
		if(n == 0 || n == 1) return head;
	
		Node *slow = head;
		Node *fast = head;
		while(n > 0) {
			n--;
			if(fast == nullptr) return nullptr; //  length < n, not found
			fast = fast->next;
		}
		while(fast != nullptr){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};

int main(){
	solution_2_2 *obj = new solution_2_2();
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	Node *n = obj->findNthToLastElement(n1, 2);
	cout << n->data << endl;
	return 0;
}