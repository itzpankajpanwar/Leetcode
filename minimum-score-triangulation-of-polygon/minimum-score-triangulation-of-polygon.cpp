class Solution {
public:
  int dp[50][50] = {};

int minScoreTriangulation(vector<int>& A, int i = 0, int j = 0, int res = 0) {
  if (j == 0) j = A.size() - 1;
  if (dp[i][j] != 0) return dp[i][j];
  for (auto k = i + 1; k < j; ++k) {
    res = min(res == 0 ? INT_MAX : res, 
      minScoreTriangulation(A, i, k) + A[i] * A[k] * A[j] + minScoreTriangulation(A, k, j));
  }
  return dp[i][j] = res;
}
};


/*

what is covex polygon : regualr polygon 

n-sided polygon 
traingulate into n-2 traingles 

dp problem 



*/