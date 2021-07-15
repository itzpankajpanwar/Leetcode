class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& n) {
        int left = 0, right = accumulate(begin(n), end(n), 0), sz = n.size();
    for (int i = 0; i < sz; ++i) {
        right -= n[i];
        left += n[i];
        n[i] = right - n[i] * (sz - i - 1) - left + n[i] * (i + 1);
    }
    return n;
        
    }
};


/*

 1    4    6   8   10
 
 1    5    11  19  29
 
 29   28   24  18  10
 

*/