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
    
    int solver(TreeNode* root , int targetSum)
    {   
       if(!root)
           return 0;
        int res=0;
        if(root->val == targetSum)
            res+=1;
        res += solver(root->left,targetSum-root->val)+solver(root->right,targetSum-root->val);
        return res;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
    if(!root) return 0;
    return pathSum(root->left,targetSum)+pathSum(root->right,targetSum)+solver(root,targetSum); 
    }
};













