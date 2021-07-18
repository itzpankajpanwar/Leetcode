class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int v, int maxPrice, int maxDistance) {
        vector<pair<int,int> > vct;
        vector<int> res;
        for(auto &x: restaurants)
        {
            if( (v==0 || (v==1 && x[2]==v)) && x[3]<=maxPrice && x[4]<=maxDistance)
                vct.push_back({x[0],x[1]});
        }
        sort(vct.begin() , vct.end() , [](pair<int,int> &p1 ,pair<int,int> &p2){
            if(p1.second==p2.second)
                return p1.first>p2.first;
            return p1.second>p2.second;  
        });
        for(auto &x:vct)
            res.push_back(x.first);
        return res;
    }
};