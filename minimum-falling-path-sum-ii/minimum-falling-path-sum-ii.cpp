
class Solution {
public:
    int dp[201][201];    
    
    int solver( vector<vector<int>>& arr , int row  , int col  )
    {   
        
        if( row >= arr.size() ) return 0;
        if( dp[row][col] != 0 ) 
            return dp[row][col];
        int res = INT_MAX;
        for( int x =0 ; x< arr.size() ; x++)
            {   
                if( x!= col)
                    res = min(res , arr[row][x] + solver(arr,row+1 , x));
            }
        return dp[row][col] = res;
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        int res = INT_MAX;
        memset( dp , 0 , sizeof(dp));
        for(int i=0 ; i< arr[0].size() ; i++)
            res  = min( res , arr[0][i] + solver( arr, 1 , i));
        return res; 
    }
};