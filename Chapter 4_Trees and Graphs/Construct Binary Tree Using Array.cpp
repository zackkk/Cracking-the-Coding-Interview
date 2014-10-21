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

class solution_4_3{

public:
	TreeNode *constructBinaryTree(int arr[], int low, int high){
		if(high > low) return nullptr;
		int mid = (low + high) / 2;
		int rootVal = arr[mid];
		TreeNode *root = new TreeNode(rootVal);
		root->left = constructBinaryTree(arr, low, mid-1);
		root->right = constructBinaryTree(arr, mid+1, high);
		return root;
	}

};