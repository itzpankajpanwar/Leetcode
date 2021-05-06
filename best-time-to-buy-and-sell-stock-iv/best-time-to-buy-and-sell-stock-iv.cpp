class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
    int res = solveit(prices,dp,0,k,1);
    return res;
    }
    
    int solveit(vector<int> &prices,vector<vector<vector<int>>> &dp,int i,int tr,int b)
    {   
        
        if(i>= prices.size() || tr<0)
            return 0;
        if(dp[i][tr][b]!=-1)
            return dp[i][tr][b];
        
        if(b==1)
            dp[i][tr][b]=max(solveit(prices,dp,i+1,tr-1,0)-prices[i],solveit(prices,dp,i+1,tr,1) );
        if(b==0)
            dp[i][tr][b]=max( solveit(prices,dp,i+1,tr,1)+prices[i],solveit(prices,dp,i+1,tr,0) );
        return  dp[i][tr][b];  
    }
};