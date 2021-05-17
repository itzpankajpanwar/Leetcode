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
    
int findHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }
    void fill(vector<vector<string>>& ans, TreeNode* root, int lvl, int start, int end) {
        if (!root) return;
        int mid = (start + end) / 2;
        ans[lvl][mid] = to_string(root->val);
        fill(ans, root->left, lvl + 1, start, mid - 1);
        fill(ans, root->right, lvl + 1, mid + 1, end);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        // find the height of the tree and allot space
        // fill the tree recursively from top to bottom
        int h = findHeight(root);
        int c = pow(2, h) - 1;
        vector<vector<string>> ans(h, vector<string>(c, ""));
        fill(ans, root, 0, 0, c - 1);
        return ans;
    }
};