#define vvi vector<vector<int>> 
class Solution {
public:
    vvi intervalIntersection(vvi& fl, vvi& sl)
    {
        vvi res; 
        vector<int> temp;
        for(auto &x:fl )
        {
            for(auto &y:sl)
            {
                temp = { max(x[0],y[0]) , min(x[1],y[1])};
                if(temp[1] >= temp[0])
                    res.push_back(temp);
            }
        }
        return res;
    }
};