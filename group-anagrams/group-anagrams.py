class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = collections.defaultdict(list)
        for x in strs:
            l = [0]*26
            for i in x:
                l[ord(i)-ord('a')]+=1
         
            d[tuple(l)].append(x)
            
        res = []
        for x in d.values():
            res.append(x)
        return res
            
        