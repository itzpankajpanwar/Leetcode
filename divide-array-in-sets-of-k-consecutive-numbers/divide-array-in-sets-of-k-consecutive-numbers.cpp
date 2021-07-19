class Solution {
public:
    bool isPossibleDivide(vector<int> A, int k) {
        map<int, int> c;
        for (int i : A) c[i]++;
        for (auto it : c)
            if (c[it.first] > 0)
                for (int i = k - 1; i >= 0; --i)
                    if ((c[it.first + i] -= c[it.first]) < 0)
                        return false;
        return true;
    }
};