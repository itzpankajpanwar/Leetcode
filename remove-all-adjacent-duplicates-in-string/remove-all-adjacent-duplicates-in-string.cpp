class Solution {
public:
    string removeDuplicates(string s) {
    vector<int> st;
    for(auto &x:s)
    {
        if(st.size()==0) st.push_back(x);
        else
        {   
            if(st.back() != x) st.push_back(x);
            else
            while(st.size() != 0 && st.back() == x)
                st.pop_back() ;
        }
    }
    s="";
    for(auto &x: st) s+=x;
    return s;
    }
};