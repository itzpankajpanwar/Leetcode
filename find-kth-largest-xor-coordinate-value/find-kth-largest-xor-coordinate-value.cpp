class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int> > hp;
        int n=matrix.size() , m = matrix[0].size();
        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                matrix[i][j]^=matrix[i][j-1];
        
        for(int j=0;j<m;j++)
            for(int i=1;i<n;i++)
                matrix[i][j]^=matrix[i-1][j];
        for(auto &x:matrix)
            for(auto &y:x)
            {
                hp.push(y);
                if(hp.size()>k)
                    hp.pop();
            }
        return hp.top();
    }
};