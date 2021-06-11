class Solution {
public:
    Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
    int minInsertions(string s) { 
    int n=s.length();
    int dp[n+1][n+1];
    memset( dp ,0 , sizeof(dp));
    for(int i=1;i<n+1;i++)
        for(int j=1; j <n+1 ; j++)  
        dp[i][j] = (s[i-1] == s[(n-1)-(j-1)] ) ? 1+dp[i-1][j-1] : max(dp[i-1][j] , dp[i][j-1]);
    return n-dp[n][n];
    }
};