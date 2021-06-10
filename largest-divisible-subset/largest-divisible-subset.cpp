class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 1);
    int max=1 , index = 0;
    for(int i=1 ; i<nums.size() ; i++ )
        for(int j=0 ; j<i; j++)
            if(nums[i] % nums[j] == 0)
            {   dp[i] = dp[j]+1;
                if(dp[i] > max )
                { max= dp[i]; index=i; }
            }
                
    int pre = -1;
    vector<int> res;
    cout<<"\n maximum is : "<<max; 
    for( ; index>=0 ; index--)
    {
        if(pre==-1) { res.push_back(nums[index]); pre = nums[index];  max--;}
        else
        {
           if( dp[index] == max && pre % nums[index] == 0 )
           {
              res.push_back(nums[index]); pre = nums[index] ; max--;
           }
        } 
    }
    reverse(res.begin() , res.end()) ;
    return res;
 
    }
};