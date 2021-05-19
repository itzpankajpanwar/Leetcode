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
class FindElements {
public:
    
    unordered_set<int> st;
    void solver(TreeNode* root,int val)
    {
        root->val = val;
        st.insert(val);
        if(root->left) solver(root->left,val*2+1); 
        if(root->right) solver(root->right,val*2+2); 
    }
        
        
    FindElements(TreeNode* root) {
        solver(root,0);
    }
    
    bool find(int target) {
    return st.find(target) != st.end() ? true : false;       
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */