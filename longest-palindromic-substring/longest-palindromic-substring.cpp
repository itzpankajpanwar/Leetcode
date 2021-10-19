class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
    }
    string longestPalindrome(string s) 
    {
        string str;
        for(int i=0;i<s.size();i++)
            str+="#"+s.substr(i,1);
        str.push_back('#');

        vector<int> dp(str.size(),0); 
        int center=0 , bd=0 , maxLen=0 , resCenter=0;

        for(int i=1;i<str.size()-1;i++) 
        {
            int im=2*center-i; 
            dp[i] = (bd>i) ? min(bd-i,dp[im]) : 0 ;
            while( i-1-dp[i]>=0 && i+1+dp[i]<=str.size()-1 && str[i+1+dp[i]] == str[i-1-dp[i]] ) 
                dp[i]++;
            if( i+dp[i] > bd ) { 
                center = i;
                bd = i+dp[i];
            }
            if(dp[i] > maxLen ) { 
                maxLen = dp[i];
                resCenter = i;
            }    
        }
        return s.substr((resCenter - maxLen)/2, maxLen);
}
};