class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
    int res=1,cl=1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]>nums[i-1])
        {
            cl++;
            if(cl>res)
                res=cl;
        }
        else
            cl=1;
    }
      return res; 
    }
};