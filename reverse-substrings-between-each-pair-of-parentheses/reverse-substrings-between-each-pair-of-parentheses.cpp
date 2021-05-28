class Solution {
public:
    Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
    string reverseParentheses(string s) {
    stack<char> st;
       
    for(auto&x:s)
    {    
       if( x!= ')') st.push(x);
        else
        {   
            string tem = "";
            while(st.top() != '(')
                { 
                    tem+=st.top(); 
                    st.pop();
                }
            st.pop();
            for(auto &y:tem) st.push(y);
        }
    }
    
    string res="";  
    while(!st.empty())
    { 
      res+=st.top(); 
      st.pop(); 
    }
        
    reverse(res.begin(),res.end());
    return res;
    }
};