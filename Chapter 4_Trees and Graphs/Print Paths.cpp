#include<iostream>
#include<vector>
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

class solution_4_8{

public:
	// path can start from anywhere, but can only go from parent to children
	// brute-force: start from all nodes traversed
	// improve: treat traversed node as ending node, find path using back-tracking

	void printPaths(TreeNode *root, int sum, vector<int> &path){
		if(root == nullptr) return;
		path.push_back(root->val);
		int tmpSum = 0;
		for(int i = path.size() - 1; i >= 0; i--){
			tmpSum += path[i];
			if(tmpSum == sum)
				printOnePath(path, i, path.size() - 1);
		}
		printPaths(root->left, sum, path);
		printPaths(root->right, sum, path);

		path.pop_back();
	}

	void printOnePath(vector<int> &path, int start, int end){
		for(int i = start; i <= end; i++) cout << path[i] << " ";
		cout << endl;
	}
};

int main(){
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(1);
	TreeNode *n3 = new TreeNode(1);
	TreeNode *n4 = new TreeNode(1);
	TreeNode *n5 = new TreeNode(1);
	TreeNode *n6 = new TreeNode(1);
	TreeNode *n7 = new TreeNode(1);

	n4->left = n2;
	n4->right = n6;
	n2->left = n1;
	n2->right = n3;
	n6->left = n5;
	n6->right = n7;

	solution_4_8 *obj = new solution_4_8();
	vector<int> path;
	obj->printPaths(n4, 2, path);
}