class Solution {
public:
    int jump(vector<int>& nums) {
    vector<int> dp(nums.size()+1,-1);
    return solver(nums,0,dp);

    }
    
    int solver(vector<int>& nums,int index,vector<int>& dp)
    {
        if(index==nums.size()-1)
            return 0;
        if(index>=nums.size())
            return 1001;
        if(dp[index] != -1)
           return dp[index];
        int mini=1001;
        for(int i=1;i<=nums[index];i++)
            mini = min(mini,1+solver(nums,index+i,dp));
        return dp[index] = mini;     
    }
};