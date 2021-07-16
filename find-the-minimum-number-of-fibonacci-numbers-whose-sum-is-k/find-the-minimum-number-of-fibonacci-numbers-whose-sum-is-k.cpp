class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = {1,1};
        int i=1;
        while(fib[i] < k )
        { 
            fib.push_back( fib[i]+fib[i-1]);
            i++;
        }
         int res=0; 
     
        for(int i=fib.size()-1;i>=0;i--)
        {
            if(fib[i]<=k){ k-=fib[i]; res++;} // cout<<fib[i]<<"  "; }
            if(k==0) break;
        }
        return res;
    }
};