class Solution {
public:
    void dfs( vector<vector<int>>& grid , int i ,int j , int color , int nw)
    {
        if( i<0 || j<0 || i == grid.size() || j==grid[0].size() ) return ;
        
        if( grid[i][j] == color  ) 
        {
        grid[i][j] =  nw;
    
        dfs( grid , i+1 , j , color  , nw);
        dfs( grid , i-1 , j , color , nw);
        dfs( grid , i , j+1 , color , nw);
        dfs( grid , i , j-1 , color , nw);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nw)
    {
    if(image[sr][sc] == nw) 
        return image;
    dfs( image , sr, sc , image[sr][sc] , nw );
    return image;
    }
};