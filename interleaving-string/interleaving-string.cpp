class Solution {
public:
    
    bool solver(string &s1, string &s2, string &s3 , int i ,int j,int k, vector<vector<int>> &dp)
    {   
    if(k==s3.length())
            return true;
    
    if(i >= s1.length() && j>=s2.length())
        return false;
        
    if( i < s1.length() && j<s2.length())
         {
            if( dp[i][j] != -1 ) 
                return dp[i][j];

            if( s1[i]!= s3[k] && s2[j] != s3[k])
                return dp[i][j] = false ;

            if(s1[i] == s3[k] && s2[j] != s3[k])
                return dp[i][j] = solver(s1,s2,s3,i+1,j,k+1,dp);

            if(s1[i] != s3[k] && s2[j] == s3[k])
                return dp[i][j] = solver(s1,s2,s3,i,j+1,k+1,dp);

            return dp[i][j] = solver(s1,s2,s3,i,j+1,k+1,dp) or solver(s1,s2,s3,i+1,j,k+1,dp);
        }
    else if(i< s1.length())
        {
             if( s1[i]!= s3[k]) return false ;
                return solver(s1,s2,s3,i+1,j,k+1,dp);  
        }
    else if( j < s2.length())
        {
             if( s2[j] != s3[k]) return false ;
            return solver(s1,s2,s3,i,j+1,k+1,dp);  
        }
    return true;   
    
    }
   

bool isInterleave(string s1, string s2, string s3) 
    {
        int n = s1.length() , m= s2.length();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
       
        if(s3.length() != s1.length()+s2.length()) 
            return false;
        
        return solver(s1,s2,s3,0,0,0,dp);
    
    }
};