class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    int sum=0;
    for(auto &x:nums) sum+=x;
    int ls=0,rs=sum;
    for(int i=0;i<nums.size();i++)
    {
        if(ls == rs-nums[i])
            return i;
        else
        {   ls+=nums[i]; 
            rs-=nums[i];
        }       
    }
        return -1;
    }
};