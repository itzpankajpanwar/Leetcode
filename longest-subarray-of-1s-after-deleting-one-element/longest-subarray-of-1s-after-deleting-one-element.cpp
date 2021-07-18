class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        vector<int> gg(n,0);
        int ct=0;
        for(int i=0;i<nums.size(); i++)
        {   gg[i]=ct;
            if(nums[i]==0) ct=0;
            else ct++;
        }
        ct=0;
        for(int i=nums.size()-1; i>=0;i--)
        {
            gg[i]+=ct;
            if(nums[i]==0) ct=0;
            else ct++;
            res = max(res ,gg[i]);
        }
        return res;
    }
};