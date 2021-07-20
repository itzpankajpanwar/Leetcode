class Solution(object):
    def sortByBits(self, A):
        return sorted(A, key=lambda a: [bin(a).count('1'), a])
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        