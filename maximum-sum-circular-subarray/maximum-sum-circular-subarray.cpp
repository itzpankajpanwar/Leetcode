class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
    
    int t1 = kadane(nums); 
    if(t1<0)
        return t1;
    int t2=0;
    for(int i=0;i<nums.size();i++)
    {   t2+=nums[i];
        nums[i] = -(nums[i]);
    }
    int t3 = kadane(nums);
    return max(t1,t2+t3);
    
    }
    
    int kadane(vector<int>& nums)
    {
        int res=nums[0],maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            maxi=max(nums[i],nums[i]+maxi);
            res=max(res,maxi);
        }
        return res;
    }
};