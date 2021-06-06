class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    int w = matrix[0].size();
    int h = matrix.size();
    vector<vector<int>> dp(h,vector<int>(w,0));
    int answer=0;
    for(int r=0;r<h;r++)
    {
        for(int c=0;c<w;c++)
        {
            if(matrix[r][c]== '1')
            {   dp[r][c]=1;
                if(r>0 && c>0)
                    dp[r][c]+= min( { dp[r-1][c] ,dp[r][c-1] , dp[r-1][c-1]});
            }
            answer = max(answer,dp[r][c]);
        }
    }
    return answer*answer;
    }
};