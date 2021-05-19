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
    
    int solver(TreeNode* root,int max)
    {
        if(!root) return 0;
        if(root->val >= max)
            return 1+solver(root->left,root->val)+solver(root->right,root->val);
        return solver(root->left,max)+solver(root->right,max);  
    }
    int goodNodes(TreeNode* root) {
    return 1+solver(root->left,root->val)+solver(root->right,root->val);
    }
};