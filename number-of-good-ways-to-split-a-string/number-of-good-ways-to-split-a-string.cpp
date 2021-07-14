class Solution {
public:
    
    int numSplits(string s) 
    {   
        vector<int> gg(26,0);
        int n=s.length();
        vector<int> lsum(n,0) , rsum;
        rsum = lsum;
        int ct=0;
        for(int i=0;i<s.length() ; i++)
        {
            if(gg[s[i]-'a']==0) { lsum[i]= ++ct ;  gg[s[i]-'a']=1;}
            else lsum[i]=ct;    
        }
        for(auto &x:gg) x=0;
        ct=0;
        for(int i=s.length()-1 ; i>=0 ; i--)
        {
             if(gg[s[i]-'a']==0) { rsum[i]= ++ct ;  gg[s[i]-'a']=1;}
             else rsum[i]=ct; 
        }
        int res=0;
        for(int i=0;i<s.length()-1 ; i++)
            res += lsum[i]==rsum[i+1] ? 1 : 0;
        return res;
    }
};


/*

prefix sum of distinct letters 
 left prefix sum 
 

rigt prefix sum 


*/