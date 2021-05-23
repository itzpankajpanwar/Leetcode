class Solution {
public:
    
    int m,n;
    map<pair<int,int>,int> mp;
    pair<int,int> p;
    bool solver(vector<vector<char>>& board, int i,int j, string &word, int index)
    {   
        p={i,j};
        if( index>=word.length() or  word[index] != board[i][j] or mp[p]==1) 
            return false;
        
        if(index==word.length()-1 && word[index]==board[i][j])
            return true;
      
        if(i+1 < m) 
            {   
                pair<int,int> pp;
                pp = {i,j};
                mp[pp]=1;
                if(solver(board,i+1,j,word,index+1) == true )
                    return true; 
                mp[pp]=0;
            }
        if(j+1 < n) 
            {   
                pair<int,int> pp;
                pp = {i,j};
                mp[pp]=1;
                if(solver(board,i,j+1,word,index+1) == true )
                    return true;     
                mp[pp]=0;
            }
        if(i-1 >=0 ) 
            {   
                pair<int,int> pp;
                pp = {i,j};
                mp[pp]=1;
                if(solver(board,i-1,j,word,index+1) == true )
                   return true; 
                 mp[pp]=0;
            }
         if(j-1 >=0 ) 
            {   
                pair<int,int> pp;
                pp = {i,j};
                mp[pp]=1;
                if(solver(board,i,j-1,word,index+1) == true )
                    return true; 
                 mp[pp]=0;
            }
        return false;
    }
    
    
    void makeboard()
    {
        for(int x=0;x<m;x++)
             for(int y=0;y<n;y++)
             {
                 p={x,y};
                  mp[p]=0;
             }
    }
    
    
    bool exist(vector<vector<char>>& board, string word) 
    {
         m= board.size();
         n=board[0].size();
         makeboard();
         for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {  
                 
                 if(solver(board,i,j,word,0))
                     return true;
             }
         }
        return false;
    }
};