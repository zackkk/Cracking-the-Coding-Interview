#include<algorithm>
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

class solution_4_1{

public:
	// check depth of root, compare max depth and min depth

	int getMaxDepth(TreeNode *root){
		if(root == nullptr) return 0;
		return 1 + max(getMaxDepth(root->left), getMaxDepth(root->right));
	}

	int getMinDepth(TreeNode *root){
		if(root == nullptr) return 0;
		return 1 + min(getMinDepth(root->left), getMinDepth(root->right));
	}

	bool checkTreeBalanced(TreeNode *root){
		if(root == nullptr) return true;
		return getMaxDepth(root) - getMinDepth(root) <= 1;
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

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n4->left = n5;
	n5->left = n6;
	n6->left = n7;

	solution_4_1 *obj = new solution_4_1();
	cout << obj->getMaxDepth(n1) << endl;
	cout << obj->getMinDepth(n1) << endl;
	cout << obj->checkTreeBalanced(n1) << endl;
}