class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {   
        unordered_map<int,int> mp;
        for(auto &x:nums) 
            ++mp[x];
        
        int res=0;
        if(k==0)
            {
                for(auto &x:mp)
                    if( x.second > 1) res++;
                return res;
            }
        for(auto &x:mp)
            if( mp.find((x.first) + k )  != mp.end() )
                res++;
        return res;
    }
};