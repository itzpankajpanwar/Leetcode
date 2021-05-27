class Solution {
public:
    int scoreOfParentheses(string s) {

    stack<int> st;
    for(auto &x : s)
        {  
            if( x == '(') st.push(-1) ;
            else
            {   int temp = 0;
                while(st.top() != -1 )
                {
                    temp += (st.top());
                    st.pop();
                }
                st.pop();
                if(temp == 0 ) st.push(1);
                else  st.push((2*temp ));   
            } 
        }
    int sum=0;
    while(!st.empty())
    {   
        sum+= (st.top());
        st.pop();
     }
    return sum; 
    }
};