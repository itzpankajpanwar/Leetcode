class Solution {
public:
    int arrayNesting(vector<int>& A) {
        int res = 0, n = A.size();
        vector<bool> seen(n);
        for (int i: A) {
            int cnt = 0;
            while (!seen[i]) {
                seen[i] = true;
                cnt++;
                i = A[i];
            }
            res = max(res, cnt);
        }
        return res;
    }
};