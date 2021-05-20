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
    bool isCompleteTree(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        int f=0;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* temp=q.front();
                q.pop();  
                
                if(temp->left && f==1) return false;
                else if(temp->left) q.push(temp->left);
                else
                    f=1;
                
                if(temp->right && f==1) return false;
                else if(temp->right) q.push(temp->right);
                else
                    f=1;
                
            }
        }
        return true;
    }
};
    