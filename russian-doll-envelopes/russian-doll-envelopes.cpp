class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
    vector< pair<int , int> > vct;
    
    for(auto &x: envelopes)
        vct.push_back( make_pair(x[0] , x[1]));
    
    sort( vct.begin() , vct.end());
    
    int maxi = 1;
    vector<int> res(envelopes.size() , 1);
    
    for(int i=0;i<vct.size() ; i++)
    {
        for(int j=i+1 ; j<vct.size(); j++)
        {
            if( vct[i].first < vct[j].first && vct[i].second < vct[j].second)
            {   res[j] = max( res[j] , res[i]+1);
                if( res[j] > maxi)
                    maxi = res[j];
            }           
        }
    }
    return maxi;
    }
};