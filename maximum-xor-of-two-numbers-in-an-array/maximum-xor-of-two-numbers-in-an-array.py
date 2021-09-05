class Solution(object):
    def findMaximumXOR(self, nums):
        ans = 0
        for i in reversed(range(32)):
            prefixes = set([x >> i for x in nums])
            ans <<=1
            candidate = ans + 1
            for p in prefixes:
                if candidate ^ p in prefixes:
                    ans = candidate
                    break      
        return ans
    
"""
this is a really beautiful question 


"""
        