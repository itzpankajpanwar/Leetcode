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
    string res="";
    
    string solver(TreeNode* root)
    {
    if(root==nullptr)
        return res+="()";
    res+='(';
    res+=to_string(root->val);
     
    if(root->right)
    {   solver(root->left);
        solver(root->right);
    }
    else if(root->left)     
        solver(root->left);
        
    res+=')';
    return res;
    }
    string tree2str(TreeNode* root) {
    if(root==nullptr)
        return res;
    res+=to_string(root->val);
    if(root->right)
    {   solver(root->left);
        solver(root->right);
    }
    else if(root->left)     
        solver(root->left);
    return res;
    }
};