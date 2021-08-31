class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        sort(nums.begin(),nums.end(), [](string &s1,string &s2){
        if(s1.length()!=s2.length())
            return s1.length()<s2.length();
        else
            return s1<s2;
            
        });
        return nums[nums.size()-k];
    }
};