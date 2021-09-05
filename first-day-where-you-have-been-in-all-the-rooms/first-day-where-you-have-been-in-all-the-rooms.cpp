class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& A) {
        long mod = 1e9 + 7, N = A.size();
        vector<int> dp(N + 1);
        for (int i = 1; i < N; ++i) {
            dp[i] = ((long)2 + 2 * dp[i - 1] - dp[A[i - 1]] + mod) % mod;
        }
        return dp[N - 1];
    }
};