class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        int maxi=0;
        for(auto &x:r)
            maxi = max( maxi , min(x[0],x[1]));
        int res=0;
        for(auto &x:r)
            res += min(x[0],x[1])==maxi ? 1 : 0;
        return res;
        
    }
};