class Solution {
    int dp[5001][1001][2];
public:
    Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
    int solver(vector<int> &prices , int index , int bs , int cp )
    {
        if(index >= prices.size() ) return 0;
        if( dp[index][cp][bs] != -1)
            return dp[index][cp][bs];
        if(bs==0)
            return dp[index][cp][bs] = max( solver(prices , index+1 , 0 , cp ) , solver(prices , index+1 , 1, prices[index]));
        
        return dp[index][cp][bs] = max( solver(prices , index+1 , 1 , cp ) , ( prices[index] - cp) + solver(prices , index+2, 0 , 0 ) );
    
    }
    
    int maxProfit(vector<int>& prices) {
    memset(dp,-1,sizeof(dp));
    return solver(prices , 0 , 0 , 0 );
    }
};