class Solution {
public:
    string removeDuplicates(string s, int k) {
   
    vector< pair<char,int> > st;
    for(auto &x: s)
    {
        if(st.empty()) st.push_back({x,1});
        else
        {   
            if( st.back().first != x ) st.push_back({x,1});
            else if(st.back().second+1 == k )
                st.pop_back();
            else st.back().second++;
        }
    }
    s="";
    
    for (auto& p : st) s += string(p.second, p.first);
    
    return s;
    }
};