#define maxi 1000000
class Solution {
public:
    
    int solver(vector<vector<int>>& matrix ,int i ,int j ,  vector< vector<int> > &dp)
    {   
        if(dp[i][j] != 1e8 )
            return dp[i][j];
        int sum = matrix[i][j];
        int mini = INT_MAX;
        if( i+1 < matrix.size())
        {
            if(j-1>=0) 
                mini = min(mini , solver(matrix,i+1,j-1 ,dp) );
            
            mini = min( mini , solver( matrix,i+1,j , dp) );
            
            if(j+1 < matrix[0].size())  
                mini = min( mini , solver(matrix,i+1,j+1 , dp) ); 
        }
        else
            return dp[i][j] = sum;
            
        return dp[i][j] = sum+mini;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix )
    {
        vector< vector<int> > dp(matrix.size()+1 , vector<int>(matrix[0].size()+1 , 1e8));
        int mini = INT_MAX;
        for(int j=0 ; j<matrix.size() ; j++ )
            mini = min(mini , solver(matrix , 0 , j , dp) );
        
        return mini;
    }
};