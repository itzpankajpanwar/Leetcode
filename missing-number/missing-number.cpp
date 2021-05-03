class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum=n*(n+1)/2;
    for(auto &x : nums)
        sum-=x;
    return sum;
    }
};