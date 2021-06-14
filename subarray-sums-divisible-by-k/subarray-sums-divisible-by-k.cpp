class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    long long sum = 0;
    int res=0;
    mp[0]=1;
    for(auto &x:nums)
    {
        sum+=x;
        int m = sum%k;
        if(m<0)
            m+=k;
        
        if( mp.find(m) != mp.end())
        {
            res += mp[m];
            mp[m]++;
        }
        else
            mp[m]=1;
    }
    return res;   
    }
};