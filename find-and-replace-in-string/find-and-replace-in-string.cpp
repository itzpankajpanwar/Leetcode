class Solution {
public:
   
    
     string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> sorted;
        for (int i = 0 ; i < indexes.size(); i++)
            sorted.push_back({indexes[i], i});
        sort(sorted.rbegin(), sorted.rend());
        for (auto ind : sorted) {
            int i = ind.first;
            string s = sources[ind.second], t = targets[ind.second];
            if (S.substr(i, s.length()) == s)
                S = S.substr(0, i) + t + S.substr(i + s.length());
        }
        return S;
    }
    
    
};

/*

first lets assume indices are sorted : i.e i can process directly 

if indices are not sorted then i have to manually do it by making map of indices and target 


*/