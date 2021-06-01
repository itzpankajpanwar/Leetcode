#define ll long long int
class Solution {
public:
   int nthSuperUglyNumber(int n, vector<int>& primes) {
    
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