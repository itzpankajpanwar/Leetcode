class Solution {
public:
    
   
    int minOperations(vector<int>& nums, int x) 
    {
        
        int sum=0;
        for(auto i:nums) sum+=i;
        sum-=x;
        if(sum==0) return nums.size();
        
        int low=0;
        int cur=0;
        int ml = 0;
        for(int high=0;high<nums.size();high++)
        {
            cur+=nums[high];
            while(sum<cur and low<nums.size())
            {
                cur-=nums[low++];
            }
            if(sum == cur)
            {
                ml = max(ml,high-low+1);
            }
        }
        return (ml==0)?-1:nums.size()-ml;
    

    }
};