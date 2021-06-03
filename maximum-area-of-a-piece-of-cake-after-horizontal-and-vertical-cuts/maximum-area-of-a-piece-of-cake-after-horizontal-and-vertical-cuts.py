class Solution:
    def maxArea(self, h: int, w: int, hh: List[int], vv: List[int]) -> int:
        hh.append(0)
        hh.append(h)
        vv.append(0)
        vv.append(w)
        hh.sort()
        vv.sort()
        x , y , mod = 0 ,0 , 1e9 + 7
        for i in range(1,len(hh)):
            if hh[i]-hh[i-1] > x :
                x = hh[i]-hh[i-1]
        for i in range(1,len(vv)):
            if vv[i]-vv[i-1] > y :
                y = vv[i]-vv[i-1]
        return int((x*y)%mod )
        
        