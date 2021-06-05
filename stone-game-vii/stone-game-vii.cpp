class Solution {
public:
    Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
    
    int solve(vector<vector<int>>& dp, vector<int> &stones, int sum, int left, int right){
        if(sum <= 0) return 0;
        if(left == right) return 0;
        if(dp[left][right] != -1) return dp[left][right];
         return dp[left][right] = max(sum-stones[left] - solve(dp ,stones, sum-stones[left], left+1, right),
                  sum-stones[right] - solve(dp, stones, sum-stones[right], left, right-1));
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int stone : stones) sum += stone;
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(dp, stones, sum, 0, n-1);
    }
};