#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v){
		val = v;
		left = nullptr;
		right = nullptr;
	}
};

class solution_4_6{

public:

	// find in BT not BST
	// solution 1: save paths using extra data structure
	// solution 2: post order traverse, O(n)
	
	TreeNode *findCommonAncestor(TreeNode *root, TreeNode *n1, TreeNode *n2){
		// return until empty or meet n1/n2
		if(root == nullptr || root == n1 || root == n2)
			return root;

		TreeNode *leftCA = findCommonAncestor(root->left, n1, n2);
		TreeNode *rightCA = findCommonAncestor(root->right, n1, n2);

		if(leftCA && rightCA) 
			return root;
		else
			return leftCA ? leftCA : rightCA;
	}

};

int main(){
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(5);
	TreeNode *n6 = new TreeNode(6);
	TreeNode *n7 = new TreeNode(7);

	n4->left = n2;
	n4->right = n6;
	n2->left = n1;
	n2->right = n3;
	n6->left = n5;
	n6->right = n7;

	solution_4_6 *obj = new solution_4_6();
	cout << obj->findCommonAncestor(n4, n2, n6)->val << endl;
	cout << obj->findCommonAncestor(n4, n1, n3)->val << endl;
	cout << obj->findCommonAncestor(n4, n1, n2)->val << endl;
}