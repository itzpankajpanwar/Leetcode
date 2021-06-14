class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum=0;
        bool f=0;
        long long m = 7+ 1e9, ans = 0  , a=0 , diff=0;
        for( int i : arr)
        {   if(i<0) { f=1; break;}
            sum += i;
        }
        if(f==0)
            return ( (sum%m)*(k%m ) )%m;
        else
            for(int i=0;i<3;i++)
            {   int pre=ans;
                k--;
                for(auto x:arr)
                    {
                        a += x;
                        ans = ans>a ? ans : a;
                        a = a>0 ? a : 0  ;
                        ans = ans % m ;
                    }
                if(k==0) break;
                diff = ans-pre;
            }
        ans = (ans + (diff*k)%m)%m;
        return ans%m;
            
    }
};