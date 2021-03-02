class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mt;
        for(auto &x:s)
            mt[x]++;
        int i=0;
        for(auto &x:s)
        {   if(mt[x]<=1)
                return i;
            else i++;
        }
        return -1;        
    }
};