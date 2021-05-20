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
    
    pair<TreeNode*,int> solver(TreeNode* root,int h)
    {
        if(!root) return{nullptr,0};
        if(!root->left && !root->right)
            return{root,h};
        pair<TreeNode*,int> l = solver(root->left,h+1) ;
        pair<TreeNode*,int> r = solver(root->right,h+1) ;
        
        if(l.second == r.second) return{root,l.second};
        if(l.second>= r.second) return{l.first,l.second};
        
        return {r.first,r.second};
        
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
    if(!root) return root;
    pair<TreeNode*,int> p = solver(root,0);
    return p.first;
    }
};