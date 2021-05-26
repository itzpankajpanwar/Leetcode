#define vi vector<int>
#define loop(i,n) for(int i=0;i<n;i++)
#define m 1e9+7
class Solution {
public:
    
    vi findright(vi& arr)
    {   
        vi ans(arr.size(),0);
        stack<int> st;
        loop(i,arr.size())
        {   
            int x =arr[i];
            if(!st.empty())
            {
                if(x>= arr[st.top()])
                    st.push(i);
                else
                {
                    while(!st.empty() && x < arr[st.top()])
                    {
                        ans[st.top()] =  abs(i-st.top()-1);
                        st.pop();
                    }
                    st.push(i);
                }
            }
            else
                st.push(i);
            
        }
      
        while(!st.empty())
        {    ans[st.top()] =  (arr.size()-1) - st.top() ;
            st.pop();
        }
        return ans;
    }
    
    vi findleft(vi& arr)
    {   
        vi ans(arr.size(),0);
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--)
        {   
            int x =arr[i];
            if(!st.empty())
            {
                if(x>arr[st.top()])
                    st.push(i);
                else
                {
                    while(!st.empty() && x <= arr[st.top()])
                    {
                        ans[st.top()] = max(0,abs(i-st.top())-1);
                        st.pop();
                    }
                    st.push(i);
                }
            } 
            else
                st.push(i);
        }
        
        while(!st.empty())
        {    ans[st.top()] = st.top();
            st.pop();
        }
        return ans;
    }
    
    int sumSubarrayMins(vi& arr)
    {
        vi ll = findright(arr) , rr =findleft(arr);
        
        long long sum =0 ;
        int mod = 1000000007;
        loop(i,arr.size())
        {   
          long long  l =ll[i]+1;
          long long r = rr[i]+1;
          long long x = (arr[i] * (l*r)) ; 
          sum = (sum%mod + x%mod) %mod ; 
        }
        return int( int(sum) % 1000000007 );
    }
};