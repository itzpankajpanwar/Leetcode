class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        int res=0 ; 
        int start = 0 , end = 0 ; 
        long long csum=0;
        unordered_map<int, int > mp;
        while( end < nums.size() )
        {
            if( mp.find( nums[end] ) == mp.end() )
            {   
                mp[nums[end]]=1;
                csum+=nums[end]; 
                end++;
                res = csum>res ? csum : res; 
            }
            else
            {   
                csum+=nums[end];
                while( mp.find( nums[end] ) != mp.end() )
                {
                    csum-=nums[start]; 
                    mp.erase(nums[start]); 
                    start++;
                }
                mp[nums[end]]=1;
                end++;
            }
        }
        return res;
    }
};