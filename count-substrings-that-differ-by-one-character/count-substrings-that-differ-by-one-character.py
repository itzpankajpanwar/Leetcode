class Solution(object):
    def countSubstrings(self, s, t):
        n, m = len(s), len(t)

        def test(i, j):
            res = pre = cur = 0
            for k in xrange(min(n - i, m - j)):
                cur += 1
                if s[i + k] != t[j + k]:
                    pre, cur = cur, 0
                res += pre
            return res
        return sum(test(i, 0) for i in xrange(n)) + sum(test(0, j) for j in xrange(1, m))
        