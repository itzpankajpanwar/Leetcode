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
    void getinorder(TreeNode* root)
    {
        if(! root ) return ;
        getinorder(root->left);
        in.push_back(root->val);
        getinorder(root->right);  
    }
    
    TreeNode* formtree(int s , int e)
    {   
        if(e <s) return nullptr;
        if(e==s)
            {
                TreeNode* root = new TreeNode(in[s]);
                return root;
            }
        int m=(s+e)/2;
        TreeNode* root = new TreeNode(in[m] , formtree(s,m-1) , formtree(m+1,e));
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) 
    {
        getinorder(root);
        int n=in.size()-1;
        return formtree(0,n);
    }
};