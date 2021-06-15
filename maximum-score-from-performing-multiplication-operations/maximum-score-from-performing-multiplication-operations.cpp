class Solution {
public:
    int dp[1001][1001] = {};
    int solver( vector<int>& nums, vector<int>& mul , int s , int e , int index)
    {   
        
            
        if( index>=mul.size() ) return 0;
        
        if( !dp[index][s])
        dp[index][s]=max( (nums[s]*mul[index])+solver(nums, mul , s+1 , e , index+1) , (nums[e]*mul[index]) + solver(nums,mul,s,e-1,index+1) );
    
        return dp[index][s];
    }
        
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int i=0 , j = nums.size()-1;
        return solver( nums , mul , i , j  , 0 );
    }
};