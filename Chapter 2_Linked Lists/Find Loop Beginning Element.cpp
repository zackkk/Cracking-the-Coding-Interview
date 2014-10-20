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

class solution_2_5{

public:
	// dist(slow) = k+x
	// dist(fast) = k+x+c
	// --> dist(fast) = 2 * dist(slow)
	// --> k+x = c (circle)
	Node *findLoopBeginningElement(Node *head){
		if(head == nullptr) return head;
		
		Node *slow = head;
		Node *fast = head;
		while(fast != nullptr && fast->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast) break; // meet
		}
		if(fast == nullptr) return nullptr; // no loop
		if(fast->next == nullptr) return nullptr; // no loop

		slow = head;
		while(slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};

int main(){
	solution_2_5 *obj = new solution_2_5();
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n3;
	Node *n = obj->findLoopBeginningElement(n1);
	cout << n->data << endl;
	return 0;
}