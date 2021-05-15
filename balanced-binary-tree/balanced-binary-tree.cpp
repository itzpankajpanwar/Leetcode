// Recursive Soln
// Time O(n)
// Space O(n)

class Solution 
{
public:
    int height(TreeNode *root)
    {
        // base case
        if ( root == nullptr ) {
            return 0;
        }
        // recursive case
        return 1+max(height(root->left),height(root->right));
    }
    
    bool isBalanced(TreeNode* root) 
    {
        // base case 
        if ( root == nullptr ) {
            return true;
        }    
        // recursive case
        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left)-height(root->right)) <= 1;
    }
};