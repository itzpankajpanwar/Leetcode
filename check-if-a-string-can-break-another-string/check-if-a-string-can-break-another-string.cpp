class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool res1 =true , res2=true;
        for(int i=0;i<s1.length();i++)
        {  if(s1[i]>s2[i])
             res1=false;
            if(s1[i]<s2[i])
                res2=false;
         }
        return res1 || res2 ;
    }
};