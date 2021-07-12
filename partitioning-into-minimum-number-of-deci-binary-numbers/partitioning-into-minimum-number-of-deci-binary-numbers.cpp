class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for(auto &x:n)
            res = max(res , x-'0');
        return res;
    }
    
};

