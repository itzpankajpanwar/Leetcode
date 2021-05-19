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
    int sum=0;
    int gettotal(TreeNode* root)
    {   if(!root) return 0;
        return gettotal(root->left) + root->val + gettotal(root->right);
    }
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        int temp = root->val;
        root->val=sum;
        sum-=temp;
        inorder(root->right);  
    }
    TreeNode* bstToGst(TreeNode* root) {
       if(!root)
            return root;
        sum = gettotal(root);
    
        inorder(root);
        return root; 
    }
};