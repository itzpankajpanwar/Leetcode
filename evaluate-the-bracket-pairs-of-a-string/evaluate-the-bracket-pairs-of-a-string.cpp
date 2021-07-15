class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        
        for(auto &x:knowledge)
            mp[x[0]]=x[1];
        
        int i=0;
        string gg;
        while(i<s.length())
        {
            if(s[i] == '(')
            {   i++;
                string res;
                while(s[i] != ')')
                    res+=s[i++];
                if(mp.find(res) != mp.end())
                    gg += mp[res];
                else
                    gg+='?';
             
                i++;
                    
            }
            else
                gg+=s[i++];
        }
        return gg;
        
    }
};