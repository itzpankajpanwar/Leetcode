class Solution {
public:
    bool isvowel(char c)
    {
        if( c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
    int maxVowels(string s, int k)
    {
        int res=0 , i=0 , j;
        for(j=0; j<k;j++)
            if(isvowel(s[j]))
                res++;
        int temp=res;
        for( ; j<s.length(); j++, i++)
        {
            if(isvowel(s[j]))
                temp++;
            if(isvowel(s[i]))
                temp--;
            res = max(res ,temp);
        }
        return res;
    }
};