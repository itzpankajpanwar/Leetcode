class Solution {
public:
    unordered_map<int,int> dp;
    int getpower(int i)
    {   
        if(dp.find(i) != dp.end()) 
            return dp[i];
        if(i%2 == 0)
            return dp[i] = 1+getpower(i/2);
        return dp[i] = 1+getpower(i*3 + 1);
    }
    int getKth(int lo, int hi, int k) {
    
        int t=1;
        dp[1]=0;
        for(int i=2;i<5000;i*=2)
            dp[i]=t++;
        vector<int> gg , tt;
        for(int i=lo;i<=hi;i++)
            gg.push_back(getpower(i)); 
        tt =gg;
        
        sort(tt.begin(),tt.end());
        int  k_th = tt[k-1];
        int ct=1;
        while(k-2 >=0 && tt[k-2]==k_th)
             {   ct++; k--; }
        for(int i=0;i<gg.size();i++)
            if( gg[i] == k_th)
            {
                ct--;
                if(ct==0)
                    return i+lo;
            }
        return lo; 
    }
};