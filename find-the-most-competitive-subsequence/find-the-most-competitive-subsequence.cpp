class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> st;
     int n = nums.size() ; 
    for(auto i=0 ; i<n ; i++ )
    {
       while( st.size() != 0  && st.back() > nums[i] && st.size()+(n-i) >k )     
           st.pop_back();
      
        if(st.size()<k)
            st.push_back(nums[i]);
    
    }
    return st;
        
    }
};