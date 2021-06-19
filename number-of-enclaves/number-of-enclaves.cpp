

class Solution {
public:
Solution() { ios_base::sync_with_stdio(0) ; cin.tie(NULL); }
    
void dfs(vector<vector<int>>& board , int i , int j , set < pair<int,int> > &visi) 
{      
    if( visi.find( {i,j} ) != visi.end() ) return ;  //element founded
    else
       {
            if( i<0 || j<0 || i >= board.size() || j >= board[0].size() ) return ;

            else if( board[i][j] == 0) 
                return;
            else 
                board[i][j] = 0;

            visi.insert({i,j});
            dfs(board , i+1, j , visi) ;
            dfs(board , i-1, j , visi) ;
            dfs(board , i, j+1 , visi) ;
            dfs(board , i, j-1 , visi) ; 
       }

}  
        
int numEnclaves(vector<vector<int>>& board) 
{
     set < pair<int,int> > visi ; 
        
    int height = board.size() ;
    int width = board[0].size();
        
      for(int i=0 ; i<height ; i++)
     {   
          for(int j=0 ; j< width ; j++)
              if( i==0 || j==0 || i == board.size()-1 || j == board[0].size()-1 )
                dfs( board , i , j , visi);
      }
     
    int res=0;
     for(int i=0 ; i<height ; i++)
         for(int j=0 ; j< width ; j++)
         {
              if( board[i][j] == 1) res++;
         }
    return res;
}
};