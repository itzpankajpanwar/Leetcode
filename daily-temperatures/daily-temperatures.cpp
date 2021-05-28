class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; --i) {
        int j = i+1;
        while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
            if (res[j] > 0) j = res[j] + j;
            else j = temperatures.size();
        }
     
        if (j < temperatures.size()) res[i] = j - i;
    }
    return res;
        
    }
};