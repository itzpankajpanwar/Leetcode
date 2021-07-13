class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = size(nums), XOR = 0;
	vector<int> ans(n);
	for(auto& num : nums) XOR ^= num;
	ans[0] = XOR ^= (1 << maximumBit) - 1;  // 2^maximumBit - 1
	for(int i = 1; i < n; i++)
		ans[i] = XOR ^= nums[n - i];            
	return ans;
    }
};