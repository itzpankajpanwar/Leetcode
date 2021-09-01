class Solution {
public:
    int minFlips(string s) 
    {   
        int n=s.length();
        string t1="",t2="";
        s +=s;
        char t='0';
        for(int i=0;i<s.length();i++)
        {
            t1+=t; 
            t2 += t=='0' ? '1' : '0';
            t = t=='0' ? '1' : '0';
        }
        
        int res=INT_MAX , res1=0 , res2=0;
        
        for(int i=0;i<n;i++)
        {
            res1 += (s[i]!=t1[i]);
            res2 += (s[i]!=t2[i]);
        }
        res = min({res, res1,res2});
        int j=0;
        
        for(int i=n;i<s.length(); i++ , j++)
        {
            res1 += (s[i]!=t1[i]) - (s[j]!=t1[j]) ;
            res2 += (s[i]!=t2[i]) - (s[j]!=t2[j]);
            res = min({res, res1,res2});
        }
        return res;
    }
};