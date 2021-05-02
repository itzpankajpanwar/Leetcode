class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
    int ct=0;
    sort(costs.begin(),costs.end());
    for(auto &x:costs)
    {
    if(coins-x>=0)
        { 
            ct++;
            coins-=x;
        }
    else
        break;
    }
    return ct;
    }
};