class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        unsigned int dp[target+1];
        for(int i=1;i<=target;i++) dp[i]=0;
            dp[0]=1;
        for(int i=1;i<=target;i++)
           {
               for(int j=0;j<len;j++)
               {
                   if(i-nums[j]<0) break;
                   else 
                   {
                      dp[i]+=dp[i-nums[j]];  
                   }
               }
           }
            return dp[target];
    }
};