class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> eo,res;
        for(int i=0;i<s.length() ; i++)
            if(s[i]==c)
                eo.push_back(i);
        for(int i=0;i<s.length() ; i++)
        {
            int tt=0;
            if(s[i]!=c)
            {
            tt = abs(eo[0]-i);
            for(int j=1;j<eo.size(); j++)
                tt = min(tt,abs(eo[j]-i));
            }
            res.push_back(tt);
        }
        return res;
    }
};