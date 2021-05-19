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
    int res=0;
    int solver(TreeNode* root)
    {
        if(!root) return 0;
        int sum = solver(root->left) + solver(root->right);
        res+= abs( sum + root->val-1); 
        return sum + root->val-1;
    }
    
    
    int distributeCoins(TreeNode* root) {
        if(!root) return 0;
        solver(root);
        return res;
    }
};