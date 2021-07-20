class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res=0;
        
        for(int i=0;i<grid.size() ; i++)
        {   
            int maxi=0;
            for(int j=0;j<grid[0].size() ; j++)
            {    maxi = max( maxi , grid[i][j] ); 
                 if(grid[i][j]>0 ) res++; 
            }
            res+=maxi;   
        }
        for(int j=0;j<grid[0].size(); j++)
        {
            int maxi=0;
            for(int i=0; i<grid.size() ; i++)
                maxi = max(maxi , grid[i][j]);
            res+=maxi;
        }
        return res;
    }
};