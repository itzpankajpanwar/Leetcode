/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode*,TreeNode*> mp;
    
    set<TreeNode*> visited;
    
    void getparent(TreeNode* root,TreeNode* parent)
    {
        if(!root)
            return;
        mp[root]=parent;
        getparent(root->left,root);
        getparent(root->right,root);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {   
        vector<int> ans;  
        if(!root)
            return ans;
        
        getparent(root,nullptr);
        
        queue<TreeNode*> q;    
       
        if(k==0)
        {
            ans.push_back(target->val);
            return ans;
        }
        q.push(target);
        visited.insert(target); 
        while(!q.empty() && k>0)
        {   
            k--;
            int r=q.size();
            for(int i=0;i<r;i++)
            {
                TreeNode* gg = q.front();
                q.pop();
                if(gg)
                {
                if(gg->left) 
                    { 
                    if(!visited.count(gg->left))
                        { q.push(gg->left);
                            visited.insert(gg->left);  
                            if(k==0)
                                ans.push_back(gg->left->val);
                        }
                    }
                if(gg->right) 
                    { 
                    if(!visited.count(gg->right))
                        { q.push(gg->right);
                        visited.insert(gg->right);   
                        if(k==0)
                            ans.push_back(gg->right->val);
                        }
                    }
                if(mp[gg] && !visited.count(mp[gg]))
                {
                    q.push(mp[gg]);
                    visited.insert(mp[gg]);
                    if(k==0)
                        ans.push_back(mp[gg]->val);
                }
                }
            }
        }
        return ans;
    }
};