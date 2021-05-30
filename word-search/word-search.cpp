class Solution {
public:
    bool findWord(vector<vector<char>> &Board,int m, int n,int r, int c, string Word, int len, int idx){
        if(idx == len) return true;
        if(r<0 || c<0 || r>=m || c >=n) return false;
        if(Board[r][c]!= Word[idx]) return false;
        char gg =Board[r][c];
        Board[r][c] = '#';
        bool res= findWord(Board,m,n,r+1,c,Word,len,idx+1)  
            ||  findWord(Board,m,n,r,c+1,Word,len,idx+1) 
            || findWord(Board,m,n,r-1,c,Word,len,idx+1)
            ||  findWord(Board,m,n,r,c-1,Word,len,idx+1);
        Board[r][c] = gg;
        return res;
        
    } 
        
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m==0) return false;
        int n = board[0].size();
        int len = word.length();
        
        for(int r=0; r<m; ++r)
            for(int c=0; c<n; ++c){
                vector<vector<bool>> visited(m,vector<bool>(n));        
                if(findWord(board,m,n,r,c,word,len,0)) 
                    return true;
            }
        return false;
    }
};