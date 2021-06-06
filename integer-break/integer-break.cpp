class Solution {
public:
    int integerBreak(int n) {
    vector<size_t> dp(n+1,0);
    if(n==2) return 1;
    if(n==3) return 2;
    dp[1]=1; dp[2]=2;  dp[3]=3;
    for(int i=4;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            dp[i] = max( dp[i] , dp[j]*dp[i-j]);
    }
    return dp[n];
    }
};