struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int v){
		val = v;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};

class solution_4_5 {

public:
	// case 1: has right child -> find the left most 
	// case 2: no right child -> go up until it belongs to the left branch of a parent node

	TreeNode *findInOrderSuccessor(TreeNode *node){
		// has no successor
		if(node->parent == nullptr && node->right == nullptr)
			return nullptr;

		// case 1
		if(node->right != nullptr){
			// find left most
			TreeNode *leftMost = node->left;
			while(leftMost->left != nullptr) 
				leftMost = leftMost->left;
			return leftMost;
		}
		// case 2
		else{
			while(node != nullptr){
				TreeNode *parentNode = node->parent;
				if(parentNode->left == node){
					return parentNode;
				}
				node = parentNode;
			}
		}
		return nullptr;
	}
};