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
    int maxi=0;
    
    int solver(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = 1+solver(root->left);
        int r = 1+solver(root->right);
        if( l+r > maxi )
            maxi=l+r;
        return max(l,r);
    }
        
        
    int diameterOfBinaryTree(TreeNode* root) {
    if(!root)
        return 0;
    solver(root);
    return max(0,maxi-2);
    }
};