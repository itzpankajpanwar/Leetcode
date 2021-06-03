class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        fillPrefixArray(mat, prefix);
        
        
        for(int i=0; i<mat.size(); ++i) {
            for(int j=0; j < mat[0].size(); ++j) {
                mat[i][j] = extractSum(i+k, j+k, prefix) - extractSum(i+k, j-k-1, prefix) - extractSum(i-k-1, j+k, prefix) + extractSum(i-k-1, j-k-1, prefix);
            }
        }
        
        return mat;
    }
    
    void fillPrefixArray(vector<vector<int>> &mat, vector<vector<int>> &prefix) {
        prefix[0][0] = mat[0][0];
        for(int i=1; i<mat[0].size(); ++i) {
            prefix[0][i] = prefix[0][i-1] + mat[0][i];
        }
        for(int i=1; i<mat.size(); ++i) {
            prefix[i][0] = prefix[i-1][0] + mat[i][0];
        }
        
        for(int i=1; i<mat.size(); ++i) {
            for(int j=1; j<mat[0].size(); ++j) {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mat[i][j];
            }
        }
    }
    
    int extractSum(int i, int j, vector<vector<int>> &prefix) {
        if(i<0 || j<0) return 0;
        if(i >= prefix.size()) i = prefix.size()-1;
        if(j >= prefix[0].size()) j = prefix[0].size()-1;
        return prefix[i][j];
    }
};