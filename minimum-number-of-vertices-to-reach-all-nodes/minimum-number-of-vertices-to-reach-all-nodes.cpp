class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> req , rej ; 
        for(auto &x : edges)
        {   
            if(rej.find(x[0]) != rej.end())
            {
                if(req.find(x[1]) != req.end())
                    req.erase(x[1]);
                 rej.insert(x[1]);
            }
               
            else if(req.find(x[1]) != req.end())
            {
                req.erase(x[1]);
                req.insert(x[0]);
                rej.insert(x[1]);
            }
            
            else if( req.find(x[0]) != req.end() )
                rej.insert(x[1]);
            else
            {
                req.insert(x[0]);
                rej.insert(x[1]);
            }
        }
        vector<int> res;
        for(auto &x: req)
            res.push_back(x);
        return res;
    }
};