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
    vector<int> s;
    
    int solver(TreeNode* root)
    {
        if(!root)
            return 0;
     int res = root->val + solver(root->left) + solver(root->right);
     s.push_back(res);
     return res; 
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
    if(!root) return s;
    solver(root);
   
    sort(s.begin(),s.end());
   
    int max=1,cm=1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1])
            cm++;
        else
            cm=1;
        if(cm>max)
            max=cm;
    }
    
    vector<int> res;
    for(int i=0;i<s.size();i++)
    {
        if( i+max-1 < s.size() && s[i]==s[i+max-1])
            res.push_back(s[i]);
    } 
    return res;      
    }
};