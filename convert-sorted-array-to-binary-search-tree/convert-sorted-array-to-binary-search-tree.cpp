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
    TreeNode* solver(vector<int>& nums,int s,int e)
    {
        if(s>e)
            return nullptr;
        int d=(e-s)/2;
        TreeNode* root = new TreeNode(nums[s+d]);
        root->left = solver(nums,s,s+d-1);
        root->right = solver(nums,s+d+1,e);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n=nums.size();
    return solver(nums,0,n-1);
    }
};