class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size() , 1);
    int maxi=1;
    for( int i=0 ; i<nums.size();i++)
    {
        for(int j=i+1 ; j<nums.size() ; j++)
        {
            if( nums[i] <nums[j])
            { 
              dp[j] = max( dp[j] , dp[i]+1 );
              if( dp[j] > maxi)
                  maxi = dp[j]; 
            }
        }
    }
     return maxi;     
    }
};