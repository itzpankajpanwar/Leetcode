class Solution {
public:
    int minInsertions(string s) {
        int ct = 0 , bt=0;
        vector<char> st;
        for(int i=0;i<s.length() ; i++)
        {
            if(s[i]=='(')
                st.push_back(s[i]);
            else if(st.size()>0)
               {
                   if(i+1 < s.length())
                       {
                           if(s[i+1]==')')
                             { st.pop_back(); i++; }
                           else
                                { ct++; st.pop_back(); }  
                       }
                   else
                       { ct++; st.pop_back(); }           
               } 
            else
            {
                if((i+1 < s.length()))
                    if(s[i+1]==')') { bt++; i++; }
                    else bt+=2;
                else
                    bt+=2;
                
            }
               
        }
        int res = 2*st.size();
        res += ct + bt;
     return res;   
    }
};