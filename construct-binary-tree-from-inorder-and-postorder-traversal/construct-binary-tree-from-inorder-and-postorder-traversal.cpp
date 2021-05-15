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
    
    TreeNode* solver(vector<int>& inorder, vector<int>& postorder,int a,int b, int p ,int q)
    {   
        if(b-a<0)
            return NULL;
        TreeNode * root=new TreeNode(postorder[q]);
        int center;
        for(int i=a;i<=b;i++)
            if(inorder[i]==postorder[q])
            {
                center=i;
                break;
            }
        
        int ll=center-a;
        int rl=b-center;
        root->left = solver(inorder,postorder,a,a+ll-1,p,p+ll-1);
        root->right = solver(inorder,postorder,a+ll+1,b,p+ll,q-1);
        
        return root; 
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n=inorder.size();
        return solver(inorder,postorder,0,n-1,0,n-1);
    }
};