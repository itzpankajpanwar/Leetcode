class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int> dp(n,0);
    for(int i=1;i<n;i++)    
            dp[i]=max(0,prices[i]-prices[i-1]);
    int res=0;
    for(auto &x:dp)
        res+=x;
    return res;
    }
};