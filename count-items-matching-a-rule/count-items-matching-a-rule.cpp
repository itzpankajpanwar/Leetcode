class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ct=0,comp;
        if(ruleKey=="type") comp=0;
        else if(ruleKey=="color") comp =1;
        else comp=2;
        for(auto &x:items)
            if(x[comp]==ruleValue)
                ct++;
        return ct;
        }
};