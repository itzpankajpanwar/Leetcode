class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
    vector<int> dp;
    for(int i=1; i<nums.size() ; i++ )
        dp.push_back( nums[i]-nums[i-1] );
    
    int res = 0;
    int ct=1;
    for(int i=1 ; i<dp.size() ; i++ )
    {
        if(dp[i]==dp[i-1])
            ct++;
        else
        {   ct++;
            if(ct>=3) 
            {  res += ( (ct*(ct+1))/2 ) - ( 2*ct -1 ); }
            ct=1;
        }
    }
    //cout<<ct;
    if(ct>=2) { ct++; res += ( (ct*(ct+1))/2 ) - ( 2*ct -1 ); }
    return res;
    }
};