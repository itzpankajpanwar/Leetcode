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
        if(!root)
            return ;
        getin(root->left);
        in.push_back(root->val);
        getin(root->right);
    }
   
    int getMinimumDifference(TreeNode* root)
        {
        getin(root);
        int min=INT_MAX;
        for(int i=1;i<in.size();i++)
            {
                if( in[i]-in[i-1] < min)
                    min=in[i]-in[i-1];
            }
        return min;
    }
};