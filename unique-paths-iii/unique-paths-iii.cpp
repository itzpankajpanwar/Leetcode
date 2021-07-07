class Solution {
public:
vector<vector<int>> grid ; 
int solver( int a , int b , int ct)
{
    if( a<0 || b<0 || a>= grid.size() || b>=grid[0].size() || grid[a][b]==-1 )
        return 0 ; 
    
    if(grid[a][b]==1) grid[a][b]=-1; 
    
    if( grid[a][b]==2 && ct!= 0 ) return 0; 
    if( grid[a][b]!=2 && ct== 0 ) return 0; 
    if( grid[a][b]==2 && ct == 0 ) return 1; 
    grid[a][b] = -1;
    int res =  solver(a-1,b,ct-1) + solver(a+1,b,ct-1) + solver(a,b-1,ct-1) + solver(a,b+1,ct-1);
    grid[a][b]=0;
    
    return res ; 
}
    
int uniquePathsIII(vector<vector<int>>& _grid)
{   
    int a , b , ct=0; 
    grid = _grid; 
    for(int i=0 ; i<grid.size(); ++i )
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            if( grid[i][j] == 1) { a=i; b=j; }
            if( grid[i][j] == 0) ct++; 
        }
    }
    cout<<a<<"   "<<b<<"   "<<ct;
    // a ,b contians start position i.e. index of 1 
    // ct contians no of zeros in grid 
    grid[a][b]=-1; 
    return solver(a-1,b,ct) + solver(a+1,b,ct) + solver(a,b-1,ct) + solver(a,b+1,ct);
        
}
};

/*
can dfs be applied here ? 
make node visited and solve for each non visited nodes 

from current node let say ( x, y )
we have 4 directions 
(x-1 , y) ---> up
(x, y-1)  ---> left
(x+1 , y) ---> down
(x,y+1)   ---> right 

we start from starting node and keeps on processing unvisited adjacent nodes 
if we reach end then we have to make sure that all nodes contaning 0 is covered 
( specified in question )

intiallly we keep count of all zero nodes 

since matrix size is 20*20 do we need Dp for this ? 

*/