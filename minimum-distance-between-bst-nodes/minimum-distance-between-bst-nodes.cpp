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
    vector<int> in;
    
    void getin(TreeNode* root)
    {
        if(!root) return;
        getin(root->left);
        in.push_back(root->val);
        getin(root->right);
    }
    
    int minDiffInBST(TreeNode* root) 
    {
        getin(root);
        int mini=in[1]-in[0];
        for(int i=2;i<in.size();i++)
            {
                if(in[i]-in[i-1] < mini)
                    mini = in[i] - in[i-1];
            }
        return mini;
    }
};