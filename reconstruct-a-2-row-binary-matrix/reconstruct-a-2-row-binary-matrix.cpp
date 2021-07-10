class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int col = colsum.size(); 
        vector<vector<int>> res(2, vector<int>(col,0));
        
        int sum=0 , two_count=0;
        for(auto &x: colsum) 
        { 
            sum+=x;
            if(x==2)
                two_count++;
        }
        if( (sum != upper+lower) || (two_count>upper) || (two_count>lower) )
        {
            res.clear();
            return res;
        }
        
        for(int i=0; i<col; i++)
        {
            if(colsum[i]==2)
            {   
                res[0][i]=1; res[1][i]=1;
                upper--; lower--;
            }
        }
        
        
        for(int j=0;j<col; j++)
        {   
            if(colsum[j] != 2)
            {
                res[0][j] =  upper>0 && colsum[j]>0 ? 1 : 0 ;
                upper -= res[0][j]; 
                colsum[j]-=res[0][j]; 
            }
        }
        for(int j=0; j<col; j++)
        {   
            if(colsum[j] != 2)
            {
                res[1][j] =  lower>0 && colsum[j]>0 ? 1 : 0 ;
                lower -= res[1][j]; 
                colsum[j]-=res[1][j]; 
            }
        }
    return res;
    }
};