class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size(); 
        vector<int> rmax , cmax; 
        
        
        for(auto&x:grid)
        {
            int gg=0;
            for(auto &y:x)
                gg = max(gg,y);
            rmax.push_back(gg); 
        }
        
        for(int j=0;j<n;j++)
        {   
            int gg=0;
            for(int i=0;i<n;i++)
                gg=max(gg,grid[i][j]);
            cmax.push_back(gg); 
        }
        
        int res=0;
        for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)
                   res +=max(0 , min(rmax[i],cmax[j])-grid[i][j] );
        return res;
    }
};