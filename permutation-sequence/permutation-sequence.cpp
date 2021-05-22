class Solution {
public:
    string getPermutation(int n, int k) {
    string res="";
    string s;
    int ff = 1;
    for(int i=1;i<=n;i++)
        {   s.push_back(i+'0');
            ff*=i;
        }
    k--;
    ff/=n;
    while(--n)
        {   
            int index = k / ff ;
            res.push_back(s[index]);
            k -= index*ff ;
            ff /= n;
            s.erase(index,1);       
        }
    res.push_back(s[0]);
    return res; 
    }
};