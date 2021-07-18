class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& gg) {
        int ct=0;
        for(int i=0; i<gg.size() ; i++)
            for(int j=0;j<gg.size();j++)
                if(i != j && gg[j][0]<=gg[i][0] && gg[j][1]>=gg[i][1])
                { ct++; break;}
            
        
        return gg.size()-ct;
    }
};