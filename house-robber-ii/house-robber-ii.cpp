class Solution {
public:
    int dp[101][2];
    int solver(vector<int> &nums, int i , bool f)
    {
        if(i>=nums.size()) return 0;
        if(i==nums.size()-1)
            return f==true ? 0 : nums[i] ;
        if(dp[i][f] != -1)
            return dp[i][f];
        if(i==0)
            return dp[i][f] = max( nums[i]+ solver(nums,i+2,true) , solver(nums,i+1,false));
        return dp[i][f] = max(nums[i]+solver(nums,i+2,f) , solver(nums,i+1,f));
    }
   
        
    int rob(vector<int>& nums)
    {   
        memset( dp , -1 , sizeof(dp));
        return solver(nums,0,false);
    }
};