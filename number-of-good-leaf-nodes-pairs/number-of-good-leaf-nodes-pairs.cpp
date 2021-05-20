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
    int res=0;
    
    vector<int> solver(TreeNode* root,int d)
    {   
        if(!root) return{0};
        if(!root->left && !root->right) return{1};
        auto l = solver(root->left,d);
        auto r = solver(root->right,d);
        
        for(auto &x:l)
            for(auto&y:r)
                if(x && y && x+y <= d)
                    res++;
        vector<int> rr;
        
        for(auto &x:l)
            if( x && x+1<+d) rr.push_back(x+1);
        for(auto &x:r)
            if( x && x+1<+d) rr.push_back(x+1);
        return rr;

    }
    int countPairs(TreeNode* root, int distance) {
    solver(root,distance); 
    return  res;
    }
};