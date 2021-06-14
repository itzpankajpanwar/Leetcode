class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        long long  sum=0 , res=0;
        for(auto &x:nums)
        {
            sum+=x;
            if( mp.find(sum-k) != mp.end() )
                res += mp[sum-k];
            mp[sum]++;
        }
    return res;
    }
};