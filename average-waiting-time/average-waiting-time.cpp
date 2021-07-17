class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ct=0 , wt=0;
        for(auto &x : customers )
        {
            if(ct<=x[0])
            {
                ct=x[0]+x[1];
                wt += x[1];
            }
            else
            {
                wt += ct-x[0]+x[1];
                ct+=x[1];
            }
        }
        return wt/customers.size();
    }
};