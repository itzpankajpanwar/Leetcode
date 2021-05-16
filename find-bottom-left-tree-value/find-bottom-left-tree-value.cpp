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
    int h=0,val;
    
    void solver(TreeNode* root,int gg)
    {
        if(!root->left && !root->right)
            {
                if(1+gg>h)
                { 
                    val=root->val;
                    h=1+gg;
                 }
            }
        if(root->left) solver(root->left,gg+1);
        if(root->right) solver(root->right,gg+1);
    }
    int findBottomLeftValue(TreeNode* root) {
    solver(root,0);
    return val; 
    }
};