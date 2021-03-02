class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> mt;
        for(auto &x:nums1)
            mt[x]++;
        for(auto &x : nums2)
            if(mt.count(x) != 0 && mt[x]!=0 )
            {  
                res.push_back(x);
                mt[x]=0;
            }
        return res;
    }
};