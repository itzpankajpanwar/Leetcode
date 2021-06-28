class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        if( e[0][0] == e[1][0] || e[0][1] == e[1][0])
            return e[1][0];
        return e[1][1];
    }
};