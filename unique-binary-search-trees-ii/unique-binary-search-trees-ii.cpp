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
    vector<TreeNode*> solver(int start, int end)
    {
        vector<TreeNode*> v;
        if(start>end)
        {
            v.push_back(NULL);
            return v;
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left = solver(start,i-1);
            vector<TreeNode*> right = solver(i+1,end);

            for(TreeNode* l : left)
                for(TreeNode* r : right)
                {
                 TreeNode* root = new TreeNode(i);
                 root->left = l;
                 root->right = r;
                 v.push_back(root);
                }  
        }   
        return v;
    }
    
    vector<TreeNode*> generateTrees(int n) {
    if(n==0) return vector<TreeNode *>();
    return solver(1,n);
    }
};