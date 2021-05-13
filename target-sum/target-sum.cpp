class Solution {
public:
    int res=0;
    int findTargetSumWays(vector<int>& nums, int target) {
    vector<int> dp;
    return solveit(nums,0,target);
    }
    
    int  solveit(vector<int> &nums,int i,int target)
    {   
        if(target==0 && i==nums.size()) 
            return 1;
        if(i>=nums.size())
            return 0;
        
        int a1 = solveit(nums, i+1 , target - nums[i]);
        
        int a2 = solveit(nums , i+1 , target + nums[i]);
        
        return a1+a2;
    } 
};