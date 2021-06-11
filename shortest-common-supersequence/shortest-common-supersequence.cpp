class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
    int p = str1.length() , q = str2.length() ; 
    vector< vector<int> > dp( p+1 , vector<int> ( q+1 , 0));
    
    for(int i=1; i< p+1 ; i++)
    {
        for(int j=1;j<q+1 ; j++)
        {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
        }
    }
    string res="";
    int i=p , j=q;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1]) { res+=str1[i-1]; i-- ; j--; }
            else if( dp[i-1][j] > dp[i][j-1]) { res+=str1[i-1] ; i--; }
            else { res+=str2[j-1]; j--; }
        }
        
        while(i>0) { res+=str1[i-1]; i-- ;}
        while(j>0) { res+=str2[j-1]; j-- ;}
        
        reverse(res.begin(),res.end());
        return res;
    }
};