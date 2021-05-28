class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {   
        vector<int> res(2*nums.size(),-1);
        stack<int> st;
        for(int k=0;k<2;k++)
        for( int i=0 ; i<nums.size();i++ )
        {   
            while( !st.empty() && nums[i] > nums[st.top()] )
            {   
                res[ st.top() ] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        while(res.size()!=nums.size())
            res.pop_back();
        return res;   
    }
};