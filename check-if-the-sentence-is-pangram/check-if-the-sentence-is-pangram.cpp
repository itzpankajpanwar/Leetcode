class Solution {
public:
    bool checkIfPangram(string sentence) {
    if(sentence.length()<26)
        return false;
    vector<int> sn(26,0);
    for(auto & x:sentence)
    {
        sn[x-'a']++;
    }
    for(auto &x:sn)
        if(x==0)
            return false;
    return true;
    }
};