class Solution {
public:
    char findTheDifference(string s, string t) {
    map<char,int> mt;
    for(auto &x: s)
        mt[x]++;
    for(auto &x: t)
    {
        if(mt.count(x)==0 || mt[x]==0)
            return x;
        else 
            mt[x]--;
    }
    return 'a';
    }
};