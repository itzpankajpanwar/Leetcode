class Solution {
public:
    bool canConstruct(string s, int k) {
    vector<int> gg(26,0);
    if(s.length()<k) return false;
    for(auto &x:s) gg[x-'a']++;
    int ct=0;
    for(auto &x:gg) ct+= x%2==0 ? 0 : 1;
    return ct>k ? false : true ;

    }
};