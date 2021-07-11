class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {        
        vector<int> res ; 
        for(auto &gg:queries)
        {
            int x=gg[0] , y=gg[1] , r=gg[2]; 
            int resi=0;
            for(auto &tt:points)
            {
                int a=tt[0] , b=tt[1];
                if( sqrt( (a-x)*(a-x) + (b-y)*(b-y) ) <= r)
                    resi++;            
            }
            res.push_back(resi);      
        }
        return res;
    }
};