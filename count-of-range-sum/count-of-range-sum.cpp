class Solution {

    int diviAndCon(vector<long>& nums, int lower, int upper, int l, int r) {
        if (r - l <= 1) return 0;
        int mid = l + (r - l) / 2;
        int count = diviAndCon(nums, lower, upper, l, mid) + diviAndCon(nums, lower, upper, mid, r);
        int n = mid, m = mid;
        for (int i = l; i < mid; i++) {
            while (n < r && nums[n] - nums[i] < lower) n++;
            while (m < r && nums[m] - nums[i] <= upper) m++;
            count += m - n;
        }

        inplace_merge(nums.begin() + l, nums.begin() + mid, nums.begin() + r);
        return count;
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) sums[i + 1] = sums[i] + nums[i];

        return diviAndCon(sums, lower, upper, 0, nums.size() + 1);
    }
};