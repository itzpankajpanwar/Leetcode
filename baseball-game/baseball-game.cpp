class Solution {
public:
    Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
   
    int calPoints(vector<string>& ops) 
    {
    int sum = 0, score = 0;
        vector<int> rounds;
        for (string op : ops) {
            if (op == "C") {
                sum -= rounds.back();
                rounds.pop_back();
                continue;
            }
            if (op == "D") {
                sum += score = rounds.back() * 2;
            }
            else if (op == "+") {
                sum += score = rounds[rounds.size() - 1] + rounds[rounds.size() - 2];
            }
            else {
                sum += score = stoi(op);
            }
            rounds.push_back(score);
        }
        return sum;
    }
};