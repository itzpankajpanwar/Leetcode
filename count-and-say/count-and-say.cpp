class Solution {
public:
    string countAndSay(int n)
    {   
        string res="";
        if(n==1)
            return "1";
       
        else
            {
            auto st = countAndSay(n-1);
            int ct=1;
            auto tt=st[0];
            for(int i=1;i<st.size();i++)
                {
                    if(st[i]==tt)
                        ct++;
                    else
                    {
                        res.push_back(ct+'0');
                        res.push_back(tt);
                        ct=1; tt=st[i];
                    }  
                }
            res.push_back(ct+'0');
            res.push_back(tt);
            }
        return res;
    }
};