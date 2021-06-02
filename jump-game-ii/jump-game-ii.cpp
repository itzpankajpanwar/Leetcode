class Solution {
public:
    int jump(vector<int>& nums) {
        
    vector<int> temp(nums.size() , nums.size());
    temp[0]=0;
    
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1; j<=i+nums[i] && j<nums.size() ; j++)
            temp[j] = min( temp[j] , 1+temp[i]);
    }    
   return temp[nums.size()-1];  
    }
};