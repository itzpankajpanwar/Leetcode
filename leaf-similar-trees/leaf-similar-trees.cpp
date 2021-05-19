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
    stack<int> st;
    
    void makestack(TreeNode* root)
    {  
        if(!root) return;
        makestack(root->left);
        if(!root->left && !root->right)
            st.push(root->val);
        makestack(root->right);   
    }
    bool checkstack(TreeNode* root)
    {  
        if(!root) return true;
        bool res=true;
        res =  res && checkstack(root->right); 
        if(!root->left && !root->right)
             {  
                if(st.empty() || st.top() != root->val) return false;
                else st.pop();
             }
        res =  res && checkstack(root->left);
        return res;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    makestack(root1);
    return checkstack(root2) && st.empty();
    }
};