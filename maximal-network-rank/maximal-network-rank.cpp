class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        vector< vector<int> > vct(n);
        for(auto &x:roads)
        { vct[x[0]].push_back(x[1]);
          vct[x[1]].push_back(x[0]);
        }
        int maxi=0;
        for(int i=0;i<n;i++)
            for(int j=i+1 ; j<n; j++)
            {
                int jj = vct[i].size() + vct[j].size(); 
                for(auto &x:vct[j])
                    if(x==i)
                    {
                        jj--;
                        break;
                    }
                maxi  = max(maxi, jj);
            }
        return maxi;
    }
};