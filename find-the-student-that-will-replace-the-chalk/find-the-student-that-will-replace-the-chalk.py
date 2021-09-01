class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        gg = sum(chalk)
        k = k%gg
        for  i,n in enumerate(chalk):
            if n>k:
                return i
            k-=n
        return len(chalk)-1