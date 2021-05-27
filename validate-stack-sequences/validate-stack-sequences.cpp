class Solution {
public:
    bool validateStackSequences(vector<int>& p, vector<int>& pp) {
    int n=p.size() , m=pp.size(),i=0,j=0;
    stack<int> st;
        while(i<n && j<m)
        {
            if(st.empty()) st.push(p[i++]);
            else if(st.top() == pp[j]) { st.pop(); j++; }
            else st.push(p[i++]);
        }
        
        while(j<m)
        {
            if(st.empty() or st.top() != pp[j]) return false;
            else { st.pop(); j++; }
        }
        
        return i==n && j==m && st.empty() ?  true : false;
    }
};