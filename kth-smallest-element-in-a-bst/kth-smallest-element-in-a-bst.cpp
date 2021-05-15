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
    vector<int> res;
    void solver(TreeNode* root)
    {
        if(root==nullptr)
            return ;
        solver(root->left);
        res.push_back(root->val);
        solver(root->right);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
    solver(root);
    return res[k-1];
    }
};