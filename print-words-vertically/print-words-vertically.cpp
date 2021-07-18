class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v;
        int mx = 0;
        istringstream ss(s);
        for (string w; ss >> w;) v.emplace_back(w), mx = max(mx, (int)w.length());
        vector<string> res(mx);
        for (int i = 0; i < mx; i++) {
            for (auto& w : v) res[i] += i < w.length() ? w[i] : ' ';
            while (res[i].back() == ' ') res[i].pop_back();
        }
        return res;
    
    }
};