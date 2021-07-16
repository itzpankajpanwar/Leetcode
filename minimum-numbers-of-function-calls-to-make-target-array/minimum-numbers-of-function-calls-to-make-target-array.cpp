class Solution {
public:
    int minOperations(vector<int>& A)
    {
       int res = 0, maxLen = 1;
        for (int a : A) {
            int bits = 0;
            while (a > 0) {
                res += a & 1;
                bits++;
                a >>= 1;
            }
            maxLen = max(maxLen, bits);
        }
        return res + maxLen - 1;
    }
};


/*

for each index get to closest power of two and then subract 


*/