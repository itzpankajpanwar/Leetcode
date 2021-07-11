class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) 
    {
        string  s= makeword(p);
        vector<string> res;
        for(auto &x:words)
        {
            string r = makeword(x);
            if(s==r)
                res.push_back(x);
        }
    return res;
    }
    
    string makeword(string s)
    {
        unordered_map<char,int> mp;
        int i=0;
        string res="";
        for(auto &x:s )
        {
            if(mp.find(x) == mp.end())
            {
                res += '1'+i;
                mp[x]=i;
                i++;
            }
            else
                res += '1'+mp[x];    
        }
    return res;
    }
};