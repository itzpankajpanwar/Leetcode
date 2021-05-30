class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    int n = nums.size();
        if (n<3) return false;
        stack<int> st;vector<int> smallest(n);
        for (int i =0;i<n;i++){
            smallest[i] = i==0? nums[i] : min(smallest[i-1],nums[i]);
        }
        for (int i =0;i<n;i++){
            while(st.size() && nums[st.top()]<=nums[i]) st.pop();
            if (st.size() && st.top()!=0 && smallest[st.top()-1]<nums[i]) return true;
            st.push(i);
        }
        return false;
    }
};