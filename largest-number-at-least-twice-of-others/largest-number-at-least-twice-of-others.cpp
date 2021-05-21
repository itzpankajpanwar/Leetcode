class Solution {
public:
    Solution(){ ios_base::sync_with_stdio(0),cin.tie(0);}
    
    int dominantIndex(vector<int>& nums) {
    int maxi = nums[0];
    int index=0;
        
    for(int i=0;i<nums.size();i++)
        if(nums[i]>maxi)
        {maxi=nums[i];
            index=i; }  
    for(int i=0;i<nums.size();i++)
        if(nums[i]!=maxi)
            if(!(maxi>= 2*nums[i]))
                return -1;
    return index;
    }
};