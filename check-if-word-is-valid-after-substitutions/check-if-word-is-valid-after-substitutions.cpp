class Solution {
public:
    bool isValid(string S) {
    for (auto i = S.find("abc"); i != string::npos; i = S.find("abc"))
        S.erase(i, 3);
  return S.empty();
    }
};