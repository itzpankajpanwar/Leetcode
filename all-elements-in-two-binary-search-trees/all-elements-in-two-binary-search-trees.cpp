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
    
    void solver(TreeNode *root,vector<int>& res)
    {
        if(!root) return;
        res.push_back(root->val);
        solver(root->left,res);
        solver(root->right,res);
    }
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> res;
        solver(root1,res);
        solver(root2,res);
        sort(res.begin(),res.end());
        return res;   
        }
};