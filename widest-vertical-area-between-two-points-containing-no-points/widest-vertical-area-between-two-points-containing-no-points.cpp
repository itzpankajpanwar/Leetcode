class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> res;
        for(auto &x:points)
            res.push_back(x[0]);
        sort(res.begin() , res.end());
        int diff = res[1]-res[0];
        for(int i=2 ; i < res.size() ; i++ )
            diff = max(diff , res[i]-res[i-1]);
        return diff;
    }
};