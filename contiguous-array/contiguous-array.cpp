class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int,int> hmap;
        hmap[0]=0;
        int ct=0;
        int res=0;
        for(int i=0 ; i<nums.size() ; i++)
        {   
            ct += nums[i]==1 ? 1 : -1 ;
            if(hmap.find(ct) != hmap.end())
                res = max( res , i+1-hmap[ct]);
            else
                hmap[ct]=i+1;
        }
    return res;
    }
};