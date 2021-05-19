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
bool find(TreeNode* root  ,int x,vector<int>& path )
    {
        if(root == NULL) return false ;
        if(root->val == x) 
        {
            path.push_back(root->val) ;
            return true;
        }
        bool lp = find(root->left , x,path) ;
        if(lp) 
        {
            path.push_back(root->val) ;
            return true;
        }
        bool rp = find(root->right , x,path) ;
        if(rp) 
        {
            path.push_back(root->val) ;
            return true;
        }
        return false ;
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(x == root->val || y == root->val) return false ;
        vector<int> path ;
        vector<int> path1 ;
        find(root , x , path) ;
        find(root , y , path1) ;
        if(path.size() != path1.size()) return false ;
        if(path[1] == path1[1]) return false ;
        return true ;
    }
};      