class Solution {
public:
    
    int solver(string &s,int a,int b)
    {   
        if(a>=b)
            return 0;
        int rc=0,lc=0;
        if(s[a]=='R') rc++;
        if(s[a]=='L') lc++;
        
        for(int i=a+1;i<=b;i++)
        {
            if(s[i]=='R') rc++;
            else lc++;
            
            if(rc==lc) 
                return 1+solver(s,i+1,b);
        }
        return 0;
    }
    
    int balancedStringSplit(string s) {
    return solver(s,0,s.length()-1);
    }
};