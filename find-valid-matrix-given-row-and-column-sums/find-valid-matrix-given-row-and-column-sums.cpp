class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int n = row.size()  , m =col.size();
        vector<vector<int>> res(n,vector<int>(m,0));
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<m;j++)
            {
                res[i][j]=min(row[i] , col[j]);
                row[i]-=res[i][j]; 
                col[j]-=res[i][j];
            }
        }
        return res;
    }
};