class Solution {
public:
    
    void solver(vector<vector<int>>& mat,int i,int j,int m,int n)
    {
        vector<int> temp;
        for(int x=i,y=j ; x<m && y<n ; x++,y++)
            temp.push_back(mat[y][x]);
        
        sort(temp.begin(),temp.end());
        
        for(int x=i,y=j,index=0; x<m && y<n ;x++,y++)
            mat[y][x] = temp[index++];
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
      
    for(int i=0,j=0;i<m;i++)
        solver(mat,i,j,m,n);
    for(int j=0,i=0;j<n;j++)
        solver(mat,i,j,m,n);
  
    return mat;
    }
};