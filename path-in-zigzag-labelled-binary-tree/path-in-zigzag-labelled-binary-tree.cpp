class Solution {
public:
    
    int findh(int label)
    {
        int h=0;
        while(label>=1)
        {
            label/=2;
            h++;
        }
        return h;
    }
    
    void solve(int l,int h,vector<int>& res)
    {   
        if(l<=1) return;
        int p = pow(2,h);
        int d = l-p;
        int mirror = (2*p-1) - d;
        solve(mirror/2,h-1,res);
        res.push_back(mirror/2);
    }
    
    
    vector<int> pathInZigZagTree(int label) {
    vector<int> res;
    int h = findh(label);
    solve(label,h-1,res);
    res.push_back(label);
    return res;
    }
};