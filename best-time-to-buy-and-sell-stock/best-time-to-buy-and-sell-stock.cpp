class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int res=0,cp=0;
    int b=prices[0];
    for(int i=1;i<prices.size();i++)
        {
            if( prices[i]-b > 0)
                cp=(prices[i]-b);
            else
                b=prices[i];
            
            if(cp>res)
                res=cp;
        }
    return res;
    }
};