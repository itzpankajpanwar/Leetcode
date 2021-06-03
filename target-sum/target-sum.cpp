class Solution {
public:
    
    int res=0;
    int findTargetSumWays(vector<int>& nums, int target) {
    map< pair<int,int> , int > mp;
    return solveit(nums,0,target , mp);
    }
    
    int  solveit(vector<int> &nums,int i,int target , map< pair<int,int> ,int> &mp )
    {   
        if(target==0 && i==nums.size()) 
            return 1;
        if(i>=nums.size())
            return 0;
        
        if( mp.find({i,target}) != mp.end())
            return mp[{i,target}];
        
        int a1 = solveit(nums, i+1 , target - nums[i] , mp );
        
        int a2 = solveit(nums , i+1 , target + nums[i] , mp );
        
        return mp[{i,target}] = a1+a2;
    } 
};