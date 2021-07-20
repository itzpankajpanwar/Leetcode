class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<pair<string,string>> s;
    for (const auto& w : A) {
        pair<string,string> p;
        for (int i = 0; i < w.size (); ++i) {
            if (i % 2) p.first  += w[i];
            else       p.second += w[i];
        }
        sort (p.first.begin  (), p.first.end ());
        sort (p.second.begin (), p.second.end ());
        s.insert (p);
    }
    return s.size ();
    }
};