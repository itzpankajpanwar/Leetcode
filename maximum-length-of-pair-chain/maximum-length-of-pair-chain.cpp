

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
    vector< pair<int, int> > vct;
    for(auto &x: pairs) vct.push_back( {x[0] , x[1]});
    sort( vct.begin() , vct.end());
        
    vector<int> res( vct.size()+1 , 1);
        
    int maxi =1;
        
    for(int i=0;i<vct.size() ; i++)
        for(int j=i+1 ; j<vct.size() ; j++)
            if( vct[i].second < vct[j].first ) 
               {
                   res[j]= max(res[j] , res[i]+1);
                   if(res[j] > maxi)
                       maxi = res[j];
               }
    
    return maxi;
    }
};