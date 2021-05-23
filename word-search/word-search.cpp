class Solution {
public:
    bool dfs(int i, int j, int idx, vector<vector<char>> &board, string word, vector<vector<int>> used){
        if(idx == word.length()) return true;
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || used[i][j]) return false;
        else if(board[i][j] == word[idx]){
            used[i][j] = 1;
            bool ans = false;
            ans = ans || dfs(i-1, j, idx+1, board, word, used);
            if(ans) return true;
            ans = ans || dfs(i+1, j, idx+1, board, word, used);
            if(ans) return true;
            ans = ans || dfs(i, j-1, idx+1, board, word, used);
            if(ans) return true;
            ans = ans || dfs(i, j+1, idx+1, board, word, used);
            return ans;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> used(n, vector<int>(m, 0));
        int wordlen = word.length();
        if(wordlen > n*m) return false;
        bool ans = false;
        for(int i=0;i < word.length();i++){
            char cur = word[i];
            bool found = false;
            for(int r=0;r < n;r++) for(int c=0; c < m; c++) if(board[r][c] == cur) found=true;
            if(found==false) return false;
        }
        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                if(dfs(i, j, 0, board, word, used)) return true;
            }
        }
        return ans;
    }
};