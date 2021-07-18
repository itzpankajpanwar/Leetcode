class Solution {
public:
  
    int minHeightShelves(vector<vector<int>>& books, int sw) 
    {
        int n = books.size();
        vector<int> dp(n + 1, 0);  // min height for book up to i (starting from 0)
        dp[0] = 0;
        
        // doing dp
        for(int i = 0; i < n; i++)
        {
            dp[i + 1] = dp[i] + books[i][1]; // Step 2- 1: on the new layer
            int sum = 0, h = 0;
            for(int j = i; j >= 0; j--)
            {
                sum += books[j][0]; // try to put on current layer, rather than the new one
                if(sum > sw) // the sum of width exceeds the shift width, unable to squeeze
                {
                    break;
                }
                else // Step 2- 2: keep squeezing
                {
                    h = max(h, books[j][1]); // get the tallest book for this layer
                    dp[i + 1] = min(dp[j] + h, dp[i + 1]); // for i + 1 th book it can either be the next layer, or this layer(try the combination to make 'one layer' as short as possible)
                    // printf("sum %d booksj_h %d h %d j %d dp[j] %d i %d dp[i + 1] %d\n", sum, books[j][1], h, j, dp[j], i, dp[i + 1]);
                }
            }
            // print_dp(dp);
        }
        // print_dp(dp);
        return dp[n];
    }
};