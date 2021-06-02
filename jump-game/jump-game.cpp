class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_possible = 0;
        for(int i=0; i<nums.size() && i<=max_possible ; i++)
            max_possible = max( max_possible , i+ nums[i] );
        return max_possible >= nums.size()-1 ? 1 : 0 ;
    }
};