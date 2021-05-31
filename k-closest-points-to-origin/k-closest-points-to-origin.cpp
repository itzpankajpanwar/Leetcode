#define ld long double 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    if(k==points.size())
        return points;
    priority_queue< pair< ld , int >> maxh;
    for(int i=0;i<points.size();i++)
    {
        ld val = sqrt( (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]) );
        maxh.push({val,i});
        if(maxh.size() > k)
            maxh.pop();
    }
    vector<vector<int>> res;
    while(maxh.size() > 0)
    {
        res.push_back( points[maxh.top().second] );
        maxh.pop();
    }
    return res;
    }
};