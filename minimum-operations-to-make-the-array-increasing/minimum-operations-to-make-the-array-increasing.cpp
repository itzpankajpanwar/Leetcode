class Solution {
public:
    int minOperations(vector<int>& nums) {
    int res=0;
    int cmax=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]>cmax) cmax=nums[i];
        else
        {
            res+=cmax-nums[i]+1;
            nums[i]=cmax+1;
            cmax++;
        }
    }
    return res;
    }
};