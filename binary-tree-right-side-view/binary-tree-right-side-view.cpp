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
    
    void solver(vector<TreeNode*> &v)
    {
        if(v.size()==0)
            return;
        res.push_back(v[v.size()-1]->val);
        vector<TreeNode*> temp;
        for(auto &x:v)
        {
            if(x)
            {
                if(x->left) temp.push_back(x->left);
                if(x->right) temp.push_back(x->right);
                    
            }
        }
        solver(temp);
    }
    
    vector<int> rightSideView(TreeNode* root) {
    if(root==nullptr)
        return res;
    vector<TreeNode*> v;
    v.push_back(root);
    solver(v);
    return res;
    }
};