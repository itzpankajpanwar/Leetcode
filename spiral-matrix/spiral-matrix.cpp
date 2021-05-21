class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
   
    int a=0,b=m[0].size()-1,p=0,q=m.size()-1;
    vector<int> res;
    while(a<=b && p<=q)
    {
        for(int i=a;i<=b;i++)
            res.push_back(m[p][i]);
        for(int i=p+1;i<=q;i++)
            res.push_back(m[i][b]);
        if(p!=q)
        for(int i=b-1;i>a;i--)
            res.push_back(m[q][i]);
        if(a!=b)
        for(int i=q;i>p;i--)
            res.push_back(m[i][a]);    
        
        a++;
        b--;
        p++;
        q--;
    }
    return res;
        
    }
};