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
    
    map< pair<TreeNode*,int> , int > m;
    
    int solver(TreeNode* root,int ct)
    {   
        pair<TreeNode*,int> p(root,ct);
        if(m[p])
            return m[p];
        if(root==nullptr)
            return 0;
        if(ct==0)
        {
            int p1 = root->val + solver(root->left,1)+solver(root->right,1);
            int p2 = solver(root->left,0) + solver(root->right,0);
            return m[p] = max(p1,p2);
        }
        if(ct==1)
            return m[p] = solver(root->left,0) + solver(root->right,0);
        return 0;
    }
    
    
    int rob(TreeNode* root)
    {
    if(!root)
        return 0;
    return solver(root,0);
    }
};