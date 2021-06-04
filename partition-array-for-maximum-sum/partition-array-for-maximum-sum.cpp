class Solution {
public:
    int s;
    int solver(vector<int> &arr, int k , int index, int maxi ,vector< vector<int>> &dp )
    {     
        if(index >= arr.size() ) return (s-k)*maxi;
        if( dp[index][k] != -1)
            return dp[index][k];
        if(k==0) 
            return dp[index][k] = solver(arr,s,index+1,0,dp);
        if(arr[index]>maxi)
            maxi = arr[index];
        return dp[index][k] = max( (s-k+1)*maxi + solver(arr,s,index+1,0,dp) , solver(arr,k-1,index+1,maxi,dp));
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
    s=k;
    vector< vector<int>> dp(arr.size()+1 , vector<int>(k+1,-1));
    return solver(arr,k,0,0,dp);
    }
};