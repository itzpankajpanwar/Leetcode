class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    
       int ans = 0;
        for (int i = 0, maxn = 0; i < arr.size(); i++) {
            maxn = max(arr[i], maxn);
            if (maxn == i) ans++;
        }
        return ans;
    }
};