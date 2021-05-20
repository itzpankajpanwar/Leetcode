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
    
    void solver(TreeNode *root , int flag , int h , int &ans){
        
            if(!root) return;
            ans = max(ans,h);
            solver(root->left , 1 , flag==0?h+1:1 , ans);
            solver(root->right , 0 , flag==1?h+1:1 , ans);
    }
    int longestZigZag(TreeNode* root) {
        
         int ans = 0; 
         solver(root , 1 ,0 ,ans);
         return ans; 
    }
};