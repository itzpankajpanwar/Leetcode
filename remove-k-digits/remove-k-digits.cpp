class Solution {
public:
    string removeKdigits(string num, int k) {
    string res;
    int keep = num.size() - k;
    for (int i=0; i<num.size(); i++) {
        while (res.size()>0 && res.back()>num[i] && k>0) {
            res.pop_back();
            k--;
        }
        res.push_back(num[i]);
    }
    res.erase(keep, string::npos);

    int s = 0;
    while (s<(int)res.size()-1 && res[s]=='0')  s++;
    res.erase(0, s);

    return res=="" ? "0" : res;
    }
};