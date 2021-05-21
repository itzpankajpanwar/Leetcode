class Solution {
public:
    
    bool solver(string &s,string &p,int a ,int b)
    {
        if(a>=s.length() and b>=p.length()) 
            return true;
        if(b>=p.length())
            return false;
        bool match = ( a <s.length() and (s[a]==p[b] or p[b]=='.'));
        
        if( b<p.length() and p[b+1]=='*')
            return solver(s,p,a,b+2) or ( match and solver(s,p,a+1,b));
        if(match)
            return solver(s,p,a+1,b+1);
        return false;
    }
    
    
    bool isMatch(string s, string p) {
    return solver(s,p,0,0);
    }
};