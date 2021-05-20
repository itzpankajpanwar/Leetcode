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
    bool flipEquiv(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
       
        if( (!p && q) || (p && !q) ) return false;
        
        if(p->val==q->val)
            return ( flipEquiv(p->left,q->right) && flipEquiv(p->right,q->left) ) || (flipEquiv(p->left,q->left) && flipEquiv(p->right,q->right));
        
        return false;
        
    }
};