class Solution {
public:
    int longestCommonSubsequence(string p, string q) 
    {
        int  n = p.length() , m = q.length(); 
        vector<vector<int>> dp(n+1, vector<int>(m+1,0)); 
        for(int i=1; i<=n; i++ )
        {
            for(int j =1 ; j<=m ; j++)
            {
                if( p[i-1] == q[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};