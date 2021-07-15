class Solution {
public:
   
    
    int dfs(vector<vector<int>>& grid , int i ,int j)
    {   
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() or grid[i][j]==0)
            return 0;
        int t = grid[i][j];
        grid[i][j]=0;
        int res = max( { dfs(grid,i-1,j) , dfs(grid, i+1,j) , dfs(grid,i,j-1) , dfs(grid,i,j+1) } );
        grid[i][j]=t;
        return res+t;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int res=0 ;
         int n , m;
        n= grid.size(); 
        m= grid[0].size();
        
        for(int i=0 ; i<n ; i++)
            for(int j=0; j<m;j++)
                if(grid[i][j]>0)
                    res = max(res , dfs(grid,i,j));
        return res;
    }
};