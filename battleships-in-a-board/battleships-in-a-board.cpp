class Solution {
public:
    void update(vector<vector<char>>& board , int i ,int j )
    {   
        board[i][j]='.';
        if(j+1 < board[0].size() && board[i][j+1]=='X')
        {
            while(j+1 < board[0].size() && board[i][j+1]=='X')
                board[i][++j]='.';
        }
        else if(i+1 < board.size() && board[i+1][j]=='X')
        {
            while(i+1 < board.size() && board[i+1][j]=='X')
                board[++i][j]='.';
        }
    }
    int countBattleships(vector<vector<char>>& board) 
    {
        int res=0;
        for(int i=0 ; i<board.size() ; i++)
            for(int j =0; j<board[0].size() ; j++)
                if(board[i][j]=='X')
                { 
                    res++; 
                    update(board,i,j);
                }
        return res;
    
    }
};