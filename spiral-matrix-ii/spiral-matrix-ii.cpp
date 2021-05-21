class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    int a=0,b=n-1,p=0,q=n-1;
    vector<vector<int>> res(n,vector<int>(n,0));
    int ct=1;
    while(a<=b && p<=q)
    {
        for(int i=a;i<=b;i++)  { res[p][i]=ct++; }
        for(int i=p+1;i<=q;i++) { res[i][b]  =ct++; }
        if(p!=q)
        for(int i=b-1;i>a;i--) {res[q][i] =ct++; }
        if(a!=b)
        for(int i=q;i>p;i--) { res[i][a] =ct++; }    
        
        a++;
        b--;
        p++;
        q--;
    }
    return res;
    }
};