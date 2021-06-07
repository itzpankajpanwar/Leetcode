class Solution {
public:
    Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
         if (nums.size() < 2 || k == 0)
            return false;
        deque<int> windows_deq;
        multiset<long> windows;
        for (int i = 0; i < nums.size(); i++) {
            if (windows.size() > k) {
                int num = windows_deq.front();
                windows_deq.pop_front();
                windows.erase(windows.find(num));
            }
            auto it = windows.lower_bound((long)nums[i] - (long)t);
            if (it == windows.end() || *it > (long)nums[i] + (long)t) {
                // not found
                windows_deq.push_back(nums[i]);
                windows.insert(nums[i]);
            }
            else return true;
        }
        return false;
    }
};