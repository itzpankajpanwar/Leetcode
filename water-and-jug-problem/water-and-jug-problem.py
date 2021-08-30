class Solution:
    def canMeasureWater(self, a: int, b: int, t: int) -> bool:
        q = [0]
        if a+b<t :
            return False
        visited = {0}
        while len(q)>0:
            node = q.pop(0)
            for step in [a,-a,b,-b]:
                csm = node+step
                if  csm == t : 
                    return True
                if csm<0 or csm>a+b:
                    continue
                if csm not in visited:
                    visited.add(csm)
                    q.append(csm)
        return False
    
"""
even though there is a mathematical solution for this problem 
but from interview point of view this solution is important 
and it works really well 

"""
                
                
        