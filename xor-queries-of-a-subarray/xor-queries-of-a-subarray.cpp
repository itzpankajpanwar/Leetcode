class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res ;
        for(int i=1; i<arr.size() ; i++)
            arr[i] = arr[i]^arr[i-1];
        for(auto &x: queries)
            res.push_back( arr[x[1]]^ ( x[0] > 0 ? arr[x[0]-1] : 0 ) );
        return res;
    }
};