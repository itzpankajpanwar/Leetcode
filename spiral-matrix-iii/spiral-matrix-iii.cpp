class Solution {
public:
    vector<int> dirs={1,0,0,1,-1,0,0,-1};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c)    
    {   
        int index=2;
        int ct=1;
        vector<vector<int>> res;
        vector<int> temp(2,0);
        temp[0]=r ; temp[1]=c;
        res.push_back(temp);
       
        while(ct < rows*cols )
        {   
            for(int d=0; d<dirs.size() ; d+=2)
            {   
                int gg=floor(index/2);
                //cout<<gg<<"  ";
                index++;
                while(gg--)
                {
                    c += dirs[d]; 
                    r += dirs[d+1];
                   // cout<<r<<"  "<<c<<endl;
                    if(r>=0 && r<rows && c>=0 && c<cols)
                    {
                        temp[0]=r;
                        temp[1]=c;
                        res.push_back(temp);
                        ct++;
                    }
                }
            
            }
        }
        
        return res;
    }
};