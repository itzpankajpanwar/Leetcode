class Solution {
public:
    int minFlips(string target) {
        int nxt = 0 , res=0;
        for(auto &x:target)
            if( x != nxt+'0') 
            { res++;
              nxt = nxt==0 ? 1 : 0 ;
            }
        return res;
    }
};