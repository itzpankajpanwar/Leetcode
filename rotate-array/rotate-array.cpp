class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k=k%nums.size();
        reverse_it(nums,0,nums.size()-1);
        reverse_it(nums,0,k-1);
        reverse_it(nums,k,nums.size()-1);
    }
    
    void reverse_it(vector<int> &nums,int low,int high)
    {
        while(low<high)
        {
            int temp=nums[low];
            nums[low++]=nums[high];
            nums[high--]=temp;
        }
    }
};