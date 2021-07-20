class Solution {
public:
    vector<int> diStringMatch(string S) {
        int left = count(S.begin(), S.end(), 'D'), right = left;
        vector<int> res = {left};
        for (char &c : S)
            res.push_back(c == 'I' ? ++right : --left);
        return res;
    }
};