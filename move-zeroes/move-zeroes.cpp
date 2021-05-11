class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int zc=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
            zc++;
        else if(zc>0)
        {   nums[i-zc]=nums[i]; 
            nums[i]=0;
        }    
    }
    
    }
};