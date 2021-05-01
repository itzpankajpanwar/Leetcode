class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int fast=0,slow=0;
    do
    {
       fast = nums[nums[fast]];
       slow = nums[slow];
    }while(fast!= slow);
    fast=0;
    while(fast!=slow)
    {
        fast=nums[fast];
        slow=nums[slow];
    }
    return fast;
        
    }
};