class Solution(object):
    def isMatch(self, s, p):
        n = len(s)
        m = len(p)
        dp = [[False]*(m+1) for i in range(n+1)]
        dp[0][0] = True
        for j in range(1,m+1):
            if p[j-1] == '*':
                dp[0][j] = dp[0][j-1]
        
        for i in range(1,len(s)+1):
            for j in range(1,len(p)+1):
                dp[i][j] = (p[j-1] in [s[i-1],'?','*'] and dp[i-1][j-1]) or (p[j-1] == '*' and (dp[i][j-1] or dp[i-1][j]))
  
        return dp[n][m]
        