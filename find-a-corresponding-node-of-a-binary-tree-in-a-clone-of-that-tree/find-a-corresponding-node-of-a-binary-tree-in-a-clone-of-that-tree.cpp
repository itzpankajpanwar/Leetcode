/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* solver(TreeNode* c, TreeNode* target)
    {   
        if(!c) return nullptr;
        if(c->val == target->val)
            return c;
        TreeNode *l = solver(c->left,target) , *r = solver(c->right,target);
        return l ? l : r ? r : nullptr ;
            
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    return solver(cloned,target);
    }
};