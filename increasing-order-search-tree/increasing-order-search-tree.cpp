/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *inorder(TreeNode *root, TreeNode *prev) {
	if(!root) return root;
	if(!root->left && !root->right) {
		root->right = prev;
		return root;
	}
	else if(!root->left) {
		TreeNode *rightLeftmost = inorder(root->right, prev);
		root->right = rightLeftmost;
		root->left = nullptr;
		return root;
	}
	else if(!root->right) {
		TreeNode *leftLeftmost = inorder(root->left, root);
		root->right = prev;
		root->left = nullptr;
		return leftLeftmost;
	}
	else {
		TreeNode *leftLeftmost = inorder(root->left, root);
		TreeNode *rightLeftmost = inorder(root->right, prev);
		root->right = rightLeftmost;
		root->left = nullptr;
		return leftLeftmost;
	}
}

TreeNode* increasingBST(TreeNode* root) {
	TreeNode *newRoot = inorder(root, nullptr);
	return newRoot;
}
};