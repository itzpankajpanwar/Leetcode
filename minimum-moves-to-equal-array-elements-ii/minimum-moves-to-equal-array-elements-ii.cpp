class Solution {
public:
    int minMoves2(vector<int>& nums) {
         int n = nums.size();
        auto it = nums.begin() + n/2;
        nth_element(nums.begin(), it, nums.end());
        int median = *it;
        int total = 0;
        for (auto &i : nums)
            total += abs(i-median);
        return total;
    }
};