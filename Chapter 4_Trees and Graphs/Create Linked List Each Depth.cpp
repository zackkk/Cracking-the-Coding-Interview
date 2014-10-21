#include<queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int v){
		val = v;
		left = nullptr;
		right = nullptr;
		next = nullptr;
	}
};

class solution_4_4{

public:

	// c++ has no built-in linkedlist type
	void createLinkedListEachDepth(TreeNode *root){
		queue<TreeNode *> current;
		current.push(root);
		while(!current.empty()){
			queue<TreeNode *> next;
			TreeNode *prev = nullptr;
			while(!current.empty()){
				TreeNode *tmp = current.front();
				if(prev == nullptr){
					prev = tmp;
				}
				else{
					prev->next = tmp;
					prev = tmp;
				}

				if(tmp->left)
					next.push(tmp->left);
				if(tmp->right)
					next.push(tmp->right);
			}
			current = next;
		}
	}
};