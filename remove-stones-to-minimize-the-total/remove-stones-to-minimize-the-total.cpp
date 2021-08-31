class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> hp;
        for(auto &x: piles) hp.push(x);
        
        while(k-- && !hp.empty())
        {
            int x = hp.top();
            hp.pop();
            x = x - floor(x/2);
            if(x>0) hp.push(x);
        }
        int res=0;
        while(!hp.empty())
        {
            int x = hp.top();
            res +=x;
            hp.pop();
        }
        return res;
    }
};