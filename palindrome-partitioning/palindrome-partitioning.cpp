#define vs vector<string> 
#define vvs vector<vector<string>>

class Solution {
public:
    vvs res;
    
    bool check_palindrome(string &s,int b,int e)
    {
        while(b<=e)
            if( s[b++] != s[e--])
                return false;
        return true;  
    }
    
    void solver(string s , int b , int e ,vs &v)
    {       
        if(b>e) { res.push_back(v); return; }
        
        for( int i = b; i < s.length() ; i++ )
        {   
            if(check_palindrome(s,b,i))
            {
                v.push_back(s.substr(b,i-b+1));
                solver(s,i+1,e,v);
                v.pop_back(); 
            }
        }  
        
    }
    
    vvs partition(string s) {
    vs v;
    int n=s.length();
    solver(s,0,n-1,v);
    return res;
    }
};