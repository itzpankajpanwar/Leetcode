class Solution {
public:
    bool isAnagram(string s, string t) {
    vector<int> mp(26,0);
    for(auto &x: s) mp[x-'a']++;
    for(auto &y : t) 
    {
        if(mp[y-'a'] == 0) return false;
        mp[y-'a']--;
    }
    for(auto &x:mp) if(x > 0 ) return false;
    return true;
    }
};