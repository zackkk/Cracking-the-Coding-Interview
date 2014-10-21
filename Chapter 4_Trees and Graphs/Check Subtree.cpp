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

class solution_4_7{

public:
	// check if root is the same as t2
	bool checker(TreeNode *root, TreeNode *t2){
		if(!root && !t2) return true;
		if(root && !t2) return false;
		if(!root && t2) return false;
		if(root->val != t2->val) return false;
		return checker(root->left, t2->left) &&
			   checker(root->right, t2->right);
	}


	// traverse t1
	bool isSubtree(TreeNode *t1, TreeNode *t2){
		if(t1 == nullptr) return false;
		if(t1->val == t2->val){
			if(checker(t1, t2)) 
				return true;
		}
		return isSubtree(t1->left, t2) ||
			   isSubtree(t1->right, t2);
	}

	// alternative: traverse tree match into string match 
	// inorder and postorder can uniquely identify a tree
};