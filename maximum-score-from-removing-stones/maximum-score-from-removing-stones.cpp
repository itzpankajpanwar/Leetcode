class Solution {
public:
    int maximumScore(int a, int b, int c) {
    return min( (a + b + c) / 2 , a + b + c- max(a, max(b, c))  );
    }
};