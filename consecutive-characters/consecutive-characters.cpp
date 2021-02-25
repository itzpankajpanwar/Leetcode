class Solution {
public:
    int maxPower(string s) {
    int max=1;
    int len=0;
    int ct=1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1])
            { ct++ ;
              if(ct>max)
                  max=ct;
            }
        else
            ct=1;
    }
        return max;
    }
};