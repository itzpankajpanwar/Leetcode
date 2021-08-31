class Solution {
public:
    bool isMatch(string s, string p) 
    {   
        int n = s.length() , m = p.length() , i=0 , j=0 , pre_i = -1 , pre_j =-1;
        while(i < n)
        {
            if( j<m && (p[j] == s[i] or p[j] == '?')) { i++; j++; }
            else if(j<m && p[j]=='*') { pre_j = j; pre_i = i ; j++; }
            else if( pre_j == -1 ) return false;  
            else { j = pre_j+1; i = pre_i+1; pre_i = i; }
        }
        for( int x=j; x<m;x++) if(p[x]!='*') return false;
        return true;
    }
};