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
    int ch=0,sum=0;
    
    void solver(TreeNode* root,int h)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            if(h>ch) { sum= root->val; ch=h; }
            else if(h==ch){ sum+=root->val; }
        }
        if(root->left) solver(root->left,h+1);
        if(root->right) solver(root->right,h+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        solver(root,1);
        return sum;
    }
};