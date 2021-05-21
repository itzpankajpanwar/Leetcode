class Solution {
public:
    string convert(string s, int nr) 
    {
       
        vector<vector<char>> rows(nr);
        if(nr==1 or nr > s.length())
            return s;
        int i=0;
        int d=1;
        for(auto &x:s)
        {
            if(d==1 && i<nr)
            {
                rows[i++].push_back(x);
                if(i==nr){
                    d=0;
                    i-=2;
                }  
            }
            else if(d==0 && i>=0)
            {
                rows[i--].push_back(x);
                if(i<0){
                    d=1;
                    i+=2;
                }  
            }      
        }
        string res="";
        for(auto &x:rows)
        for(auto &rr:x)
           res+=rr;
        return res;
    }

};