class Solution {
public:
    Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
  
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    
    for (auto &s: strs) {
        int ones = count(s.begin(), s.end(), '1');
        int zeros= s.size()-ones;
        for (int i=m; i>=zeros; i--) 
            for (int j=n; j>=ones; j--)
                dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
    }
    return dp[m][n];
}
};