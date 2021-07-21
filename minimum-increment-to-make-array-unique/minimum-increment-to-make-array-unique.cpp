class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
    map<int,int> mp;
    for(auto &x:nums) mp[x]++;
        
    int res=0;
    for(auto &x:mp)
    {
        int i = x.first , j = x.second ; 
        if(j>1)
        {
            res+=( ( j*(j-1)) / 2 );
            for( int p= i+1; p < i+j; p++ )
                mp[p]++;
        }
    }
    return res;
    }
};