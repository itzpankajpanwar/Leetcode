class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
    
    for(int i=1;i<t.size();i++)
    {
        for(int j=0;j<t[i].size();j++)
        {
            if(j!=0 && j!=t[i].size()-1)
                t[i][j]+=min(t[i-1][j-1],t[i-1][j]);
            else if(j==0)
                t[i][j]+=t[i-1][j];
            else
                t[i][j]+=t[i-1][j-1];
            
        }
    }
    int res=INT_MAX;
    
    int g = t.size()-1;
    for(auto &x:t[g])
        if(x<=res)
            res=x;
    return res;
    }
};