class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> res;
        for(int i=0 ; i<board.size() ; i++)
        {
            for(int j=0 ; j<board[0].size() ; j++)
            {   int lc=0;
                lc += i-1 >=0 ? board[i-1][j] : 0;
                lc += j-1 >=0 ? board[i][j-1] : 0;
                lc += i+1 <board.size() ? board[i+1][j] : 0;
                lc += j+1 <board[0].size() ? board[i][j+1] : 0;
                lc += j-1 >=0 && i-1 >=0 ? board[i-1][j-1] : 0;
                lc += j+1 <board[0].size() && i+1 <board.size() ? board[i+1][j+1] : 0;
                lc += j+1 <board[0].size() && i-1 >= 0 ? board[i-1][j+1] : 0;
                lc += i+1 <board.size() && j-1 >= 0 ? board[i+1][j-1] : 0;   
             
                if(board[i][j] == 0)
                    { 
                      if( lc == 3) res.push_back(1);
                      else res.push_back(0);
                    }
                else 
                {
                    if( lc < 2) res.push_back(0);
                    else if( lc>3) res.push_back(0);
                    else res.push_back(1);
                }
            }  
        }
        
        int pp=0;
        for(int i=0;i<board.size();i++)
            for(int j=0 ; j<board[0].size() ; j++)
                board[i][j] = res[pp++];

    }
};