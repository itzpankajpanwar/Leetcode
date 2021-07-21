class Solution {
public:
    vector<int> res;
    vector<int> findDiagonalOrder(vector<vector<int>>& mat , int i=0 , int j=0 ,int d=1) 
    {   
        //cout<<i<<"   "<<j<<endl;
        if(i>mat.size() || j>mat[0].size() || i<0 || j<0)
           return res;
        if( d==1)
        {   
            int a,b;
            for(a=i, b=j ; a>=0 && b<mat[0].size() ; a-- , b++)
                res.push_back(mat[a][b]);
            //cout<<a<<"  "<<b<<" d= 0"<<endl;
            if(b>=mat[0].size()) { a++; b--; }
            
            findDiagonalOrder(mat,a+1,b,0);
        }
        else
        {
            int a,b;
            for(a=i, b=j ; a<mat.size() && b>=0 ; a++ , b--)
                res.push_back(mat[a][b]);
            //cout<<a<<"  "<<b<<" d= 1"<<endl;
            if(a>=mat.size()) { a--; b++; }
            findDiagonalOrder(mat,a,b+1,1);
        }
        return res;
    }
};