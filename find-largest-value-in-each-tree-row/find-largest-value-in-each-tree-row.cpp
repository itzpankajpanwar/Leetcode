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
    
    void solver(vector<TreeNode*> v)
    {
        if(v.size() == 0 )
            return ;
        vector<TreeNode*> temp;
        int max=INT_MIN;
        for(auto &x: v)
        {
            if(x->val>max)
                max=x->val;
            if(x->left) temp.push_back(x->left);
            if(x->right) temp.push_back(x->right);
        }
        res.push_back(max);
        solver(temp);
    }
    
    vector<int> largestValues(TreeNode* root) 
    {
    if(!root) return res;
    vector<TreeNode*> v;
    v.push_back(root);
    solver(v);
    return res;
    }
};