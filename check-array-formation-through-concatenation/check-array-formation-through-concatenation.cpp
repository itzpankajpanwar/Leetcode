class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int> ps(101, -1);
    for (int i = 0; i < pieces.size(); ++i)
        ps[pieces[i][0]] = i;
    for (int i = 0; i < arr.size(); ) {
        int p = ps[arr[i]], j = 0;
        if (p == -1)
            return false;
        while (j < pieces[p].size())
            if (arr[i++] != pieces[p][j++])
                return false;
    }
    return true;
    }
};