class Solution {
public:
   vector<vector<int>> grid;
   vector<vector<int>> imarker;
   int dfs(int i, int j)
   {
       if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]<=0)
           return 0; 
       grid[i][j]=-1;
       return 1+dfs(i+1,j)+dfs(i-1,j)+dfs(i,j+1)+dfs(i,j-1); 
     
   }

   void fill_with_gg(int i, int j , int gg ,  int c)
   {
       if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]>=0)
           return; 
       grid[i][j]=gg;
       imarker[i][j]=c;
       fill_with_gg(i+1,j,gg,c);
       fill_with_gg(i-1,j,gg,c);
       fill_with_gg(i,j+1,gg,c);
       fill_with_gg(i,j-1,gg,c); 
   }
    
    int getsum( int i , int j )
    {
        bool a , b , c ,d;
        a = j-1 >= 0 ? true : false;
        b = i+1 < grid.size() ? true : false;
        c = j+1 < grid[0].size() ? true : false;
        d = i-1 >= 0 ? true : false;
        
        int sum=1;
        sum += (a ? grid[i][j-1] : 0)  + ( b ? grid[i+1][j] : 0) + (c ? grid[i][j+1] : 0) + (d? grid[i-1][j] : 0) ;
        
        if( d && c && imarker[i-1][j]==imarker[i][j+1] ) sum-=grid[i-1][j];
        else if( d && b && imarker[i-1][j]==imarker[i+1][j] ) sum-=grid[i-1][j];
        else if( d && a && imarker[i-1][j]==imarker[i][j-1] ) sum-=grid[i-1][j];
        else {}
        
        if( c && b && imarker[i][j+1]==imarker[i+1][j] ) sum-=grid[i][j+1];
        else  if( c && a && imarker[i][j+1]==imarker[i][j-1] ) sum-=grid[i][j+1];
        else { }
        
        if( b && a && imarker[i+1][j]==imarker[i][j-1] ) sum-=grid[i+1][j];
        
        return sum;
    }

int largestIsland(vector<vector<int>> _grid)
    {  
       imarker = _grid;
       grid = _grid; 
    
       int res=0 , c=1;
    for(int i=0; i<grid.size() ; i++)
            for(int j=0 ; j<grid[0].size(); j++)
                if(grid[i][j]==1)
                {   
                    grid[i][j]=1;
                    int gg = dfs(i,j);
                    res = max( res , gg); 
                    fill_with_gg(i , j , gg , c++);
   
                }
  /*  for(auto &x:grid)
    {
        cout<<endl;
        for(auto &y:x)
            cout<<y<<"  ";
    }
    
    cout<<"\nimarker "<<endl;
    for(auto &x:imarker)
    {
        cout<<endl;
        for(auto &y:x)
            cout<<y<<"  ";
    }
    */
    for(int i=0; i<grid.size() ; i++)
            for(int j=0 ; j<grid[0].size(); j++)
                if(grid[i][j]==0)
                    res = max( res , getsum(i ,j )); 
    return res; 
    }
};


/*
apply dfs on ones and update matrix value accordingly 
*/