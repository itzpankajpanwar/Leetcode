class Solution {
public:
    unordered_map<string,int>points;
    vector<int>chars;
    //Solution() { ios_base::sync_with_stdio(0); cin.tie(NULL); }
    bool possible(string s)
    {
        vector<int>temp(26,0);
        for(auto c:s)
            temp[c-'a']++;
        for(int i=0;i<26;i++)
            if(chars[i]<temp[i])
                return false;
        return true;
    }
    
    void use_it(string s)
    {
        for(auto c:s)
            chars[c-'a']--;
    }
    
    void back_track(string s)
    {
        for(auto c:s)
            chars[c-'a']++;
    }
    
    int msw(int i,vector<string>& words)
    {
        int res=0;
        for(int j=i;j<words.size();j++)
        {
            if(possible(words[j]))
            {
                use_it(words[j]);
                res=max(res,points[words[j]]+msw(j+1,words));
                back_track(words[j]);
            }
        }
        return res;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        for(auto w:words)
        {
            int p=0;
            for(auto c:w)
                p+=score[c-'a'];
            points[w]=p;
        }
        chars.resize(26,0);
        for(auto c:letters)
            chars[c-'a']++;
        return msw(0,words);
    }
};