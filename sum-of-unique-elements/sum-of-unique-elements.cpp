class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
    map<int,int> mt;
    for(auto &x : nums)
        mt[x]++;
    int res=0;
    for(auto &x:mt)
    {   
        if(x.second==1)
        { res+=x.first;
        }
    }
    return res;
    }
};