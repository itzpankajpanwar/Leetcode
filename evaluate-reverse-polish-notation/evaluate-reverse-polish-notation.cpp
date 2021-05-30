class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(auto &x: tokens)
    {
        if( x=="+" or x=="-" or x=="*" or x=="/")
        {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            if(x=="+") st.push(a+b);
            else if(x=="-") st.push(a-b);
            else if(x=="*") st.push(a*b);
            else if(x=="/") st.push(a/b);
        }
        else
        {
            int i=0 , f=0;
            for(auto & y :x)
            {
                if(y=='-') f=1;
                else  i = i*10 + y-'0';
                    
            }
            if(f==1) i = -i;
               
            st.push(i);
        }
    }
        return st.top();
    
    }
};