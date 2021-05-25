class Solution {
public:
    
    Solution()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
    }
                
    int repeatedStringMatch(string a, string b) {
        
        const int min_repeat = ceil((float)b.size() / a.size());
        string temp;
        for(int i = 0; i < min_repeat; i++)
            temp += a;
        if(temp.find(b) != string::npos)
            return min_repeat;
        temp += a;
        if(temp.find(b) != string::npos)
            return min_repeat + 1;
        return -1;
    }
};