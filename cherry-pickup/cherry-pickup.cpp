class Solution {
public:
    int dp[51][51][51];
    int solver(vector<vector<int>>& grid, int r1 , int c1 , int c2)
    {
        int r2 = r1+c1-c2 ;
        int n = grid.size();
        
        if( r1>=n || r2 >= n || c1>=n || c2 >= n || grid[r1][c1]==-1 || grid[r2][c2]==-1) 
            return INT_MIN;
        
        if( dp[r1][c1][c2] != -1 ) 
            return dp[r1][c1][c2];
        
        if( r1==n-1 && c1==n-1) 
            return grid[r1][c1];
        
        int res =  grid[r1][c1];
        if( c1 != c2) res += grid[r2][c2];  // to make sure same grid not selected twice 
        
        int gg = max( { solver(grid ,r1 , c1+1 , c2+1) ,  solver(grid ,r1 , c1+1 , c2) , solver(grid ,r1+1 , c1 , c2+1) , solver(grid ,r1+1 , c1 , c2) });
        res += gg;
        
        return dp[r1][c1][c2]=res;
       
    }
    
    
    int cherryPickup(vector<vector<int>>& grid)
    {     
        int n = grid.size();
        memset(dp , -1 , sizeof(dp));
        return max( 0 , solver(grid , 0 ,0 ,0 ) );                                   
    }
};