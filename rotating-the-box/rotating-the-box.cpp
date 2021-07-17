class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size() , m = box[0].size();
        
        vector<vector<char>> res(m,vector<char>(n,'.'));
        
        for(int i=0;i<n;i++)
        {
            for(int j=m-1 ; j>=0 ; j--)
            {   
            
                if(box[i][j]=='*' || box[i][j]=='.')
                {
                    int ct=0 , t = j; 
                    while(j-1>=0 && box[i][j-1]!='*')
                    {
                        if(box[i][j-1]=='#') ct++;
                        j--;
                    }
                    if( box[i][t]=='*' )
                       res[t--][n-i-1] = '*';
                    while(ct--)
                        res[t--][n-i-1] = '#';  
                }
                else
                    res[j][n-i-1] = '#';  
            }
        }
        return res;
    }
};