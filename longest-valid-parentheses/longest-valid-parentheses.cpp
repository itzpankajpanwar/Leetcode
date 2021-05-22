class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if(s.length() == 0) 
            return 0;
        int len = s.length();    
        int count = 0; 
        stack<int> indexStack; 
        indexStack.push(-1); 
        for(int i = 0; i < len; i++)   
            if(s[i] == '(')
                indexStack.push(i);
            else if(s[i] == ')')
            {
                if(!indexStack.empty()) 
                {
                    indexStack.pop();
                    if(indexStack.empty())
                        indexStack.push(i);
                    else
                        count = std::max(count, i - indexStack.top());
                }
            }    
        return count;
    }
};