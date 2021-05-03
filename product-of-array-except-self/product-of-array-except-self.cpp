class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int tt=1,ttt=1,zc=0;
        for(auto&x:nums)
            {   tt*=x; 
                if(x!=0)
                    ttt*=x;
                else
                    zc++;
            }
        if(zc>=2)
            {
                for(int i=0;i<nums.size();i++)
                    nums[i]=0;
            }
        else
        {
            for(int i=0;i<nums.size();i++)
            { 
                if(nums[i]!=0)
                    nums[i]=tt/nums[i];
                else 
                    nums[i]=ttt;
            }
        }
        return nums;
    }
};