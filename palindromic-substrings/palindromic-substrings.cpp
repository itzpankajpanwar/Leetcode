class Solution {
public:
    
    bool is_pal(string s,int i,int j)
    {
        while(i<j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
    int countSubstrings(string s) {
        int ct=0;
        cout<<s.length();
        for(int i=0 ; i < s.length() ; i++)
            for(int j=i ; j < s.length() ; j++)
                if(is_pal(s,i,j))
                    ct++;
        return ct;
        
    }
};