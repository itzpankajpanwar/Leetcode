class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        n = len(mat) 
        m = len(mat[0])
        for i in range(n):
            for j in range(m):
               
                gg = ( i<=0 or mat[i][j] >mat[i-1][j] ) and ( j<=0  or mat[i][j] > mat[i][j-1]) and ( i>=n-1 or mat[i][j] >mat[i+1][j] ) and ( j>=m-1 or mat[i][j] > mat[i][j+1] )
                if gg == True: 
                    return [i,j]
        return [-1,-1]
                
        