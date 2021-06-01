#define ll long long int
class Solution {
public:
   Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
   int nthUglyNumber(int n) {
    vector<int> primes{2,3,5};
    priority_queue< ll , vector<ll> , greater<ll> > hp;
    ll res = 1;
    while(--n)
    {
       
       for(auto &x:primes)
          hp.push(res * x);
        
       res = hp.top();
       while(!hp.empty() && res==hp.top())
               hp.pop();   
    }
    return res;
    }
  
};