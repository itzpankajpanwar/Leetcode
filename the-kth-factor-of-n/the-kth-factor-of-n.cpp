class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> gg;
        for(int i=1;i<=n;i++)
            if(n%i==0)
                gg.push_back(i);
        if(k-1 > gg.size()-1)
            return -1;
        return gg[k-1];
    }
};