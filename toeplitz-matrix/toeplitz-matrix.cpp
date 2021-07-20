class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) 
    {
        for(int j=0; j<mat[0].size() ; j++)
        {
            int x=j+1 , e = mat[0][j];
            for(int i=1;i<mat.size() && x<mat[0].size(); i++ ,x++)
                if(mat[i][x] != e)
                    return false;
        }
        for(int i=0; i<mat.size() ; i++)
        {
            int x=i+1 , e = mat[i][0];
            for(int j=1; j<mat[0].size() && x<mat.size() ; j++ ,x++)
                if(mat[x][j] != e)
                    return false;
        }
        return true;
        
    }
};