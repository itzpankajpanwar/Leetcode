class Solution {
public:
    bool solver(string &s,string &p,int a ,int b,vector<vector<int>> &dp)
    {   
        if(dp[a][b]!=-1)
            return dp[a][b];
        if(a>=s.length() and b>=p.length()) 
            return true;
        if(b>=p.length())
            return false;
        bool match = ( a <s.length() and (s[a]==p[b] or p[b]=='.'));
        
        if( b<p.length() and p[b+1]=='*')
            return dp[a][b] = solver(s,p,a,b+2,dp) or ( match and solver(s,p,a+1,b,dp));
        if(match)
            return dp[a][b] = solver(s,p,a+1,b+1,dp);
        return false;
    }
    
    
    bool isMatch(string s, string p) {
    vector<vector<int>> dp( s.length()+1, vector<int>(p.length()+1,-1) );
    return solver(s,p,0,0,dp);
    }
};