class Solution {
public:
    bool chacha_ji(vector<int> master , vector<int> temp)
    {
        for(int i=0 ; i<26 ; i++)
            if( temp[i]<master[i])
                return 0;
        return 1;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        vector<int> master(26,0);
        for(auto x : words2)
        {
            vector<int> temp(26,0);
            for(auto y : x)
                temp[y-'a']++;
            for(int i=0 ; i<26; i++)
                master[i] = max(master[i] , temp[i]);
        }
        vector<string> res; 
        for(auto &x: words1)
        {
            vector<int> temp(26,0);
            for(auto y : x)
                temp[y-'a']++;
            if( chacha_ji(master , temp))
                res.push_back(x);  
        }
        return res;
    }
};