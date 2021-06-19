class Solution {
public:
    
    Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
    
    void dfs( vector<vector<char>>& grid , int i ,int j )
    {
        if( i<0 || j<0 || i == grid.size() || j==grid[0].size() ) return ;
        
        if( grid[i][j] == '0'  ) return ;
        
        grid[i][j] =  '0';
    
        dfs( grid , i+1 , j);
        dfs( grid , i-1 , j);
        dfs( grid , i , j+1 );
        dfs( grid , i , j-1 );
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        int res=0;
        for(int i=0;i<grid.size() ; i++)
            for(int j=0;j<grid[0].size(); j++)
                if(grid[i][j]=='1')
                {  res++;dfs( grid , i , j); }
        return res;
 
    }
};