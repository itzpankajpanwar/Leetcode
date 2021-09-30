class Solution {
public:
    int minSideJumps(vector<int>& ob) 
    {   
        int n  = ob.size(); 
        vector<vector<int>> dp(3, vector<int>(n , 1000000));
        
        dp[0][n-1] = dp[1][n-1] = dp[2][n-1] = 0; 
        for(int i=n-2 ; i>=0; i--)
        {
            if( ob[i]  != 1) dp[0][i] = dp[0][i+1]; 
            if( ob[i]  != 2) dp[1][i] = dp[1][i+1]; 
            if( ob[i]  != 3) dp[2][i] = dp[2][i+1]; 
            
            if( ob[i]  != 1) dp[0][i] = min( { dp[0][i] , 1+dp[1][i] , 1+dp[2][i] }); 
            if( ob[i]  != 2) dp[1][i] = min( {dp[1][i] , 1+dp[0][i] , 1+dp[2][i] }); 
            if( ob[i]  != 3) dp[2][i] = min( {dp[2][i] , 1+dp[0][i] , 1+dp[1][i] });   
        }
        
        return min({ dp[1][0] , 1+dp[0][0] , 1+dp[2][0]});
    }
};