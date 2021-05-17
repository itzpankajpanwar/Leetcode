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
    
    TreeNode* solver(TreeNode* root,int d,int &val)
    {   
        if(d<0)
            return root;
        if(d==0)
        {
            TreeNode* n1=new TreeNode(val,root->left,NULL);
            TreeNode* n2=new TreeNode(val,NULL,root->right);
            root->left = n1;
            root->right=n2;
            return root;
        }
        else
        {
            if(root->left) solver(root->left,d-1,val);
            if(root->right) solver(root->right,d-1,val);
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if(depth==1)
    {
        TreeNode* n1=new TreeNode(val,root,NULL);
        return n1;
    }
    solver(root,depth-2,val);  
    return root;
    }
};