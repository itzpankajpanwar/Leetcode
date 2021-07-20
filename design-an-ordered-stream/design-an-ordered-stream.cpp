class OrderedStream {
public:
    
    vector<string>res;
    int ptr;
    OrderedStream(int n) {
        res.resize(n);
        ptr = 1;
    }
    
    vector<string> insert(int id, string value) {
        res[id-1] = value;
        vector<string> ans;
        
        if(ptr == id) {
            int i = ptr - 1;
            
            for(; i < res.size(); i++) {
                if(res[i] == "")
                    break;
                ans.push_back(res[i]);
            }
            ptr = i+1;
        }
        return ans;
    }
};