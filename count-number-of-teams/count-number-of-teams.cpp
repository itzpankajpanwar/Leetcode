class Solution {
public:
    int numTeams(vector<int>& r)
    {
        int res =0 ;
        res += getcombinations(r);
        reverse(r.begin(), r.end());
        res+=getcombinations(r);
        return res;
    }
    
    int getcombinations(vector<int>& r)
    {   
        int res=0;
        int n=r.size();
        vector<int> dp(n,0);
        for(int i=n-2; i>=0;i--)
        {   int ct=0 ;
            for(int j=i+1;j<n;j++)
            {
                if(r[j]<r[i]) 
                {
                    ct++; 
                    res+=dp[j]; 
                }
            }
            dp[i]=ct;
        }
        return res;  
    }
};