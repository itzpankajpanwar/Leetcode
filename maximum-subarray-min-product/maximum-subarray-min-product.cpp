class Solution {
public:
    int maxSumMinProduct(vector<int>& A) {
        long long mod = 1e9+7, N = A.size(), ans = 0;
        vector<long long> sum(N + 1); // prefix sum
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        vector<int> prev(N, -1), next(N, -1); // prev[i]/next[i] is the index to the previous/next smaller element
        vector<int> s; // a stack.
        for (int i = 0; i < N; ++i) { // compute the index to the previous smaller elements
            while (s.size() && A[s.back()] >= A[i]) s.pop_back();
            if (s.size()) prev[i] = s.back();
            s.push_back(i);
        }
        s.clear();
        for (int i = N - 1; i >= 0; --i) { // compute the index to the next smaller elements
            while (s.size() && A[s.back()] >= A[i]) s.pop_back();
            if (s.size()) next[i] = s.back();
            s.push_back(i);
        }
        for (int i = 0; i < N; ++i) {
            long long s = next[i] == -1 ? sum.back() : sum[next[i]];
            if (prev[i] != -1) {
                s -= sum[prev[i] + 1];
            }
            ans = max(ans, (long long) A[i] * s);
        }
        return ans % mod;
    }
};