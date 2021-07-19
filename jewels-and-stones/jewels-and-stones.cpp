class Solution {
public:
    int numJewelsInStones(string j, string s) {
        unordered_set<char> st;
        for(auto &x:j) st.insert(x);
        int res=0;
        for(auto &x:s) 
        { 
        if( st.find(x) != st.end() )
            res++;
            }
        return res;
    }
};