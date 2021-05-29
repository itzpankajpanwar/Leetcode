class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> st;
   
    vector<int> ct(26,0);
    vector<int> visi(26,0);
    for(auto &x:s) 
        ct[x-'a']++;
        
    for(auto&x:s)
    {   
        ct[x-'a']--;
        
        if(visi[x-'a']==0)
        {
            while(st.size()!=0 && x < st.back() && ct[st.back()-'a']>0)
            {   
                visi[st.back() - 'a']=0;
                st.pop_back();
            }
            visi[x-'a']=1;
            st.push_back(x);
        }
    }
     
    string res = "" ;
    for(auto &x : st)
        res += x;
    return res;
    }
};