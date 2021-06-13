class Solution {
    int rm[100001] = {};
    bool valid(string &s, string &p, vector<int> &A, int k) {
        memset(rm, 0, sizeof(rm));
        for (int i = 0; i < k; ++i) rm[A[i]] = 1; // mark this index as removed
        int N = s.size(), M = p.size(), j = 0; // `j` is the number of characters in `p` we matched with `s`
        for (int i = 0; i < N && j < M; ++i) {
            if (rm[i] == 1) continue; // this character is removed, skip
            if (s[i] == p[j]) ++j; // found a match, increment `j`
        }
        return j == M; // if `j` reaches the end of `p`, `p` is still a subsequence of `s`.
    }
public:
    int maximumRemovals(string s, string p, vector<int>& A) {
        int L = 0, R = A.size();
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(s, p, A, M)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};