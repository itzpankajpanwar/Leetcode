
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
   
    int s= 1, e= 1e9;
    
    while (s < e) 
    {
        int mid = (s + e) / 2 , cnt = 0;
        for (auto &x: nums)
            cnt += (x - 1) / mid;
        
        if (cnt > maxOperations)
           s = mid + 1;
        else
            e = mid;
    }
    return s;
    }
};