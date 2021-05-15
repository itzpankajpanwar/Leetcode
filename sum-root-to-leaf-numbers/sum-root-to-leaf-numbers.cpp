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
    
    int solver(TreeNode* root,int sum)
    {   
        if(root==nullptr)
            return 0;
        if(root->left==nullptr &&  root->right==nullptr)
            return sum*10+root->val;
        
        int ct=sum*10+root->val;
        int temp=ct;
        int s1=solver(root->left,temp);
        int s2=solver(root->right,temp);
        return s1+s2;
    }
    
    
    int sumNumbers(TreeNode* root) {
    return solver(root,0); 
    }
};