class Solution {
public:
    int comb(int n, int r) 
    {
        long ans = 1;
        for (int i = 1, j = n - r + 1; i <= r; ++i, ++j) ans = ans * j / i;
        return ans;
    }
    string kthSmallestPath(vector<int>& A, int k) 
    {
        int h = A[1], v = A[0], N = h + v;
        string s;
        for (int i = 0; i < N; ++i) {
            if (h) { // we have H available to pick
                int c = comb(h - 1 + v, v); // if we pick H at the current position, there will be `c` combinations for the rest of characters
                if (k <= c) { // k is covered within `c`, so we should pick H.
                    s += 'H';
                    --h;
                } else { // otherwise we should pick V
                    k -= c;
                    s += 'V';
                    --v;
                }
            } else { // no H left, have to pick V.
                s += 'V';
                --v;
            }
        }
        return s;
    }
};
