class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>  v1(26,0),v2(26,0); 
        for(auto &x: s) v1[x-'a']++;
        for(auto &x: t) v2[x-'a']++;
        
        int res=0;
        for(int i=0;i<26;i++)
            res+=abs(v1[i]-v2[i]);
        return res/2;
            
        
    }
};