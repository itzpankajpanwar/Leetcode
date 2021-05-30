class Solution {
public:
    bool isValidSerialization(string preorder) {
        int ct = 1,f=0;
        for(auto &x:preorder)
        {   
            if(x>='0' && x<='9') { f=1; }
            else if(ct==0) return false;
            else if(x == '#') { ct--; f=0; }
            else if( x==',' && f==1 ) ct++;
        }
        return ct==0 ? true : false;
    }
};