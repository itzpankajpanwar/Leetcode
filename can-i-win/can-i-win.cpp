class Solution {
public:

    bool recurse(int sum,int mask,int n,vector<int>& dp)
    {
        
        if(sum<0)return 0;
        if(sum==0)return false;
        if(dp[mask]!=-1)return dp[mask];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i)&&!recurse(sum-i-1,mask^(1<<i),n,dp))
            return dp[mask]=1;
        }
                        return dp[mask]=0;
    
    }
    bool canIWin(int n, int sum) {
        int mask=(1ll<<n)-1;
        if(sum==0)return 1;
        if(2*sum>(n*(n+1)))return 0;
        if(sum*2==(n*(n+1)))
        {
            if(n%2)return 1;
            return 0;
        }
        int summ=(n*(n+1))/2+1;
        vector<int>dp(mask,-1);
        for(int i=0;i<n;i++)
                              
                              {
                                  if(!recurse(sum-i-1,mask^(1<<i),n,dp))
                                      return true;
                            
                              }
                              return false;
    }
};