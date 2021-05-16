/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "x,";
        string l=serialize(root->left);
        string r=serialize(root->right);
        return to_string(root->val)+","+l+r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s="";
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                q.push(s);
                s="";
                continue;
            }
            s+=data[i];
        }
        return helper(q);
    }
    
    TreeNode* helper(queue<string> &q){
        string ch=q.front();
        q.pop();
        if(ch=="x") return NULL;
        TreeNode* root=new TreeNode(stoi(ch));
        root->left=helper(q);
        root->right=helper(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;