class Solution {
public:
    
    bool solver(vector<int>& nums , int s , int e , int chance , int s1 , int s2)
    {
        if(s>e) { 
            if(s1>=s2) return true;
            else return false; }
        
        if(chance == 1)
            return solver(nums,s+1,e,2,s1+nums[s],s2) || solver(nums,s,e-1,2,s1+nums[e],s2);
        return solver(nums,s+1,e,1,s1,s2+nums[s]) && solver(nums,s,e-1,1,s1,s2+nums[e]);
        
    }
        
        
    bool PredictTheWinner(vector<int>& nums) 
    {
        return solver(nums,0,nums.size()-1,1,0,0);
    }
};