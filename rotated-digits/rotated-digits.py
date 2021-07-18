class Solution(object):
    def rotatedDigits(self, N):
        s1 = set([1, 8, 0])
        s2 = set([1, 8, 0, 6, 9, 2, 5])
        def isGood(x):
            s = set([int(i) for i in str(x)])
            return s.issubset(s2) and not s.issubset(s1)
        return sum(isGood(i) for i in range(N + 1))
        