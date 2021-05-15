/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void solver(vector<Node*> v)
    {
        if(v.size()==0)
            return;
        vector<Node*> c;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]) 
            {
                c.push_back(v[i]->left);
                c.push_back(v[i]->right);
                if(i!=v.size()-1)
                    v[i]->next = v[i+1];
                else
                    v[i]->next = nullptr;
            }

        }
        solver(c);
    }
    
    Node* connect(Node* root) {
    vector<Node*> v;
    v.push_back(root);
    solver(v);
    return root;
    }
};