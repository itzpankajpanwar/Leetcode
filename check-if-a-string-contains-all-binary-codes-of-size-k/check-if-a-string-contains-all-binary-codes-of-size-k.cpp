class Solution {
public:
    bool hasAllCodes(string s, int k, unordered_set<string> seen = {}) {
        if (s.size() < k) return false;
        int l = 0, r = k-1;
        while (r++ < s.size()){
            string word = s.substr(l++,k);
            seen.insert(word);
        }
        return seen.size() == (1 << k);
    }
};