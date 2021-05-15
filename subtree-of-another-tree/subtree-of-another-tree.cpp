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
    bool checkequal(TreeNode* root, TreeNode* sr)
    {   
        if(!root && !sr)
            return true;
        if( (!root && sr ) || (root && !sr) )
            return false;
        if(root->val == sr->val)
        {   
             cout<<root->val<<endl;
            return checkequal(root->left,sr->left) && checkequal(root->right,sr->right);
        }
        return false;
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* sr) {
    
    if(!root && !sr)
        return true;
    if( (!root && sr ) || (root && !sr) )
        return false;
   
    if(root->val == sr->val)
    {   
        bool res = checkequal(root->left,sr->left) && checkequal(root->right,sr->right);
        if(res==true)
            return true;
    }
        
    if ( isSubtree(root->left,sr) || isSubtree(root->right,sr) )
        return true;
    return false;
    
    }
};