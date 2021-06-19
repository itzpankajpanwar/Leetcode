class Solution {
public:
    void dfs( vector<vector<int>>& grid , int i ,int j , set< pair<int,int> > &visi)
    {
        if( i<0 || j<0 || i == grid.size() || j==grid[0].size() ) return ;
        if( grid[i][j] == 1 || visi.find({i,j}) != visi.end() )
            return ;
        grid[i][j] =  1;
        
        visi.insert( { i, j});
        
        dfs( grid , i+1 , j , visi);
        dfs( grid , i-1 , j , visi);
        dfs( grid , i , j+1 , visi);
        dfs( grid , i , j-1 , visi);
    }
    
    int closedIsland(vector<vector<int>>& grid)
    {
    
        set< pair<int,int> > visi;

        for( int j=0; j< grid[0].size() ; j++ )
        {
            dfs( grid , 0 , j, visi);
            dfs( grid , grid.size()-1 , j, visi);
        }

        for( int i=0; i< grid.size() ; i++ )
        {
            dfs( grid , i , 0, visi);
            dfs( grid , i, grid[0].size()-1 , visi);
        }
        
        int res=0;
        for(int i=1;i<grid.size() ; i++)
        {
            for(int j=1;j<grid[0].size(); j++)
            {
                if(grid[i][j]==0)
                {
                    res++;
                    dfs( grid , i , j,visi);
                }
            }
        }
    
        return res;
        
        
    }
};