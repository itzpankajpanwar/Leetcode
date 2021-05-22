class Solution {
public:
    
    bool solver(string &s, string &p,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=s.length() && j>=p.length() ) return true;
        if( j>=p.length() )
            return false;
        bool match=false;
        if(dp[i][j]!= -1)
            return dp[i][j];
        match = (i<s.length() and (s[i]==p[j] or p[j]=='?') );
        if(p[j]=='*')
        {   if(i<s.length())
                return dp[i][j] = solver(s,p,i+1,j,dp) or (solver(s,p,i,j+1,dp));
            else
                return dp[i][j] = (solver(s,p,i,j+1,dp));
        }
        if(match)
            return dp[i][j] = solver(s,p,i+1,j+1,dp);
        
        return false;
    }   
        
    bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,-1));
    return solver(s,p,0,0,dp);
    }
};