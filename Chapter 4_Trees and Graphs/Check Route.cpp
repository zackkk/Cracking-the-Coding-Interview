#include<queue>
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


class solution_4_2{

public:

	// bfs
	bool checkRoute(TreeNode *start, TreeNode *end){
		queue<TreeNode *> myqueue;
		myqueue.push(start);
		while(!myqueue.empty()){
			TreeNode *tmp = myqueue.front();
			myqueue.pop();
			if(tmp == end) return true;
			if(tmp->left)
				myqueue.push(tmp->left);
			if(tmp->right)
				myqueue.push(tmp->right);
		}
		return false;
	}

};