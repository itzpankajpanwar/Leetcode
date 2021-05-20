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
    int maxLevelSum(TreeNode* root) {
    int maxi=root->val;
    if(!root) return 0;
    queue<TreeNode*> q;
    if(root->left) q.push(root->left);
    if(root->right) q.push(root->right);
    int h=1,res=1;
    while(!q.empty())
    {   
        h++;
        int sum=0;
        int r=q.size();
        for(int i=0;i<r;i++)
            {
                auto gg = q.front();
                q.pop();
                sum+=gg->val;
                if(gg->left) q.push(gg->left);
                if(gg->right) q.push(gg->right);
            }
        if(sum > maxi)
        { maxi=sum;
          res=h;
        }
    }
     return res;   
    }
};