class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
    }
    void set_val( int i , vector<int> &res)
    {   
        if(i==res[2] or i==res[1] or i==res[0]) return ;
        if( i > res[2]){ res[0] = res[1]; res[1]= res[2]; res[2]=i; }
        else if(i>res[1]){ res[0] = res[1]; res[1]=i; }
        else if(i>res[0]){ res[0] = i; }
    }
    
    void findpossiblerobus(vector<vector<int>>& grid , int i, int j, int &n , int &m , vector<int>&res)
    {
        for(int x = 1;x<n;x++)
        {   
           
            if(i-x <0 or i+x>=n or j+ 2*x >=m )
                break;
            
            int sum = 0;
            int p=i,q=j;
            for( ; p< i+x && q< j+x    ; p++, q++) sum+=grid[p][q];
            for( ; p>i   && q<j+2*x ; p--,q++)  sum+=grid[p][q];
            for( ; p>i-x && q> j+x   ; p--,q--)  sum+=grid[p][q];
            for( ; p<i   && q> j     ; p++,q--)  sum+=grid[p][q];
            
            set_val(sum,res) ; 
        }
        
    }
    
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
    vector<int> res(3,0);
    int n=grid.size();
    int m=grid[0].size();
    
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   
            set_val( grid[i][j] , res );
            findpossiblerobus(grid , i , j ,n,m ,res);
        }
    }
    reverse(res.begin(),res.end());
    if(res[2]==res[1] or res[2]==0) res.pop_back();
    if(res[1]==res[0] or res[1]==0) res.pop_back();
    
        
    return res;
    }
};