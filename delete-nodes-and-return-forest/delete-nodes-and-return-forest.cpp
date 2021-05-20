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
    
    TreeNode* solver(TreeNode* root, vector<int>& td,vector<TreeNode*>& vct) 
    {
        if(!root) return nullptr;
        if(root->left) root->left=solver(root->left,td,vct);
        if(root->right) root->right=solver(root->right,td,vct);
        int f=0;
        for(auto &x:td)
            if(root->val == x){
                f=1;
                break;
            }
        if(f==1)
        {   
            if(root->left) vct.push_back(root->left);
            if(root->right) vct.push_back(root->right);
            root=nullptr;
            return root;
        }
        return root;   
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& td) {
    vector<TreeNode*> vct;
    if(!root) return vct;
    
    int f=0;
    for(auto &x:td)
        if(root->val == x){
            f=1;
            break;
        }
    if(f==0) vct.push_back(root);
    solver(root,td,vct);
    return vct;
    }
};