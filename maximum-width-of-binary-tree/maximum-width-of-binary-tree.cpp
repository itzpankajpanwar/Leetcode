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
    int widthOfBinaryTree(TreeNode* root) {
    if(!root)
        return 0;
    queue<pair<TreeNode*,size_t>> q;
    size_t maxi=1;
    q.push({root,1});
    
    while(!q.empty())
    {
        maxi = max(maxi, q.back().second-q.front().second+1);
        int p = q.size();
        for(int i=0;i<p;i++)
        {
        auto gg = q.front();
        q.pop();
            if(gg.first->left)  q.push({gg.first->left,gg.second*2});
            if(gg.first->right)  q.push( {gg.first->right,gg.second*2+1} );  
        }
    }
    return maxi;
    }
};