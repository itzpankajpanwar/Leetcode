class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) 
    {
        int n=grid.size() , m = grid[0].size();
        
        for(int i=0 ; i<n;i++)
        {
            if(grid[i][0] == 0)
                for(int j=0;j<m; j++)
                    grid[i][j] =  grid[i][j]==0 ? 1 : 0 ;
        }
        int res=0;
        for(int j=0 ; j<m ; j++)
        {
            int oc=0 , zc=0 ;
            for(int i=0;i<n;i++)
                grid[i][j]==1 ? oc++ : zc++;
            res +=   max(oc,zc) * ( pow(2 , m-j-1 ) );
        }
        return res;
        
    }
};