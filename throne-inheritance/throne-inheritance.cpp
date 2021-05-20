class ThroneInheritance {
public:
   struct Node
    {
        string val;
        vector<Node*> children;
        Node(string s): val(s) {}
        Node(string s,vector<Node*> child_) : val(s){
            children=child_;
        }
    };
    Node* root;
    unordered_map<string,Node*> mp;
    ThroneInheritance(string kingName) {
        root=new Node(kingName);
        mp[kingName]=root;
    }
    
    void birth(string parentName, string childName) {
        Node* child=new Node(childName);
        mp[childName]=child;
        mp[parentName]->children.push_back(child);
        
    }
    
    void death(string name) {
        mp[name]=NULL;
    }
    void dfs(Node* root, vector<string> &res){
        if(mp[root->val])res.push_back(root->val);
        for(auto i:root->children){
            dfs(i,res);
        }
        
    }
    vector<string> getInheritanceOrder() {
        vector<string> res;
        if(!root)return res;
        dfs(root,res);
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */