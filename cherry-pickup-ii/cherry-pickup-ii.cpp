class Solution {
public:
    int dp[71][71][71];
    vector<vector<int>> grid;
    
    Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
    
    int solver( int r, int c1 , int c2)
    {
        int n = grid.size() , m = grid[0].size();
       
        if(c1 >= m || c1<0 || c2 >= m || c2<0) return INT_MIN;
        
        if( dp[r][c1][c2] != -1 ) 
            return dp[r][c1][c2];
        
        if( r==n-1 ) 
        {
            if(c1 != c2) return grid[r][c1]+grid[r][c2];
            else return grid[r][c1];
        }
        
        
        int res =  grid[r][c1];
        if( c1 != c2) res += grid[r][c2];  // to make sure same grid not selected twice 
        
        int gg = max({solver(r+1,c1,c2) ,solver( r+1, c1, c2-1),solver(r+1,c1,c2+1)  });
        gg = max( { gg ,solver(r+1,c1-1,c2) , solver( r+1, c1-1, c2-1) , solver(r+1,c1-1,c2+1)  });
        gg = max( { gg ,solver(r+1,c1+1,c2) , solver( r+1, c1+1, c2-1) , solver(r+1,c1+1,c2+1)  });
        res +=gg;
        return dp[r][c1][c2]=res;
       
    }
    
    
    int cherryPickup(vector<vector<int>>& _grid)
    {     
        grid = _grid;
        int m = grid[0].size();
        memset(dp , -1 , sizeof(dp));
        return max( 0 , solver( 0 ,0 ,m-1) );    
    }
    
};