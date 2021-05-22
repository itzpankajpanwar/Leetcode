#define v vector 
#define s string 
#define loop(i,n) for(int i = 0; i < n; i++)

class Solution {
public:
    
   Solution()
   {
    ios_base::sync_with_stdio(0);
      cin.tie(NULL);
   }
    v<v<s>> res;
    bool checkifpossible(v<v<int>> &cb,int a,int b,int n)
    {
        loop(i,n)   // for row and column check 
            if(cb[a][i]==1 or cb[i][b] ==1)
                return false;
 
        for(int i=a,j=b; i<n && j<n; i++,j++)
            if(cb[i][j]==1)
                return false;
        for(int i=a,j=b; i>=0 && j<n; i--,j++)
            if(cb[i][j]==1)
                return false;
        for(int i=a,j=b; i>=0 && j>=0 ;i--,j--)
            if(cb[i][j]==1)
                return false;
        for(int i=a,j=b; i<n && j>=0; i++,j--)
            if(cb[i][j]==1)
                return false; 
        return true;
    }
    
    void looper(v<v<int>> &cb,int p,int q,int n,set< v<s> > &st)
    {   
        if(p>=n)
        {   
            vector<string> vt;
            for(auto &x:cb)
            {   string tt="";
                for(auto&y:x)
                {
                    if(y==0) tt+='.';
                    else if(y==1) tt+='Q';
                }
                
                vt.push_back(tt);         
            }
            if(!st.count(vt))
            { res.push_back(vt);
              st.insert(vt);
            }
            return;
        }
        
        if(checkifpossible(cb,p,q,n))
        {
            cb[p][q]=1;
            for(int i=0;i<n;i++)
                looper(cb,p+1,i,n,st);
            cb[p][q]=0;
        }
    
    }
    
    v<v<s>> solveNQueens(int n) 
    {
        set< v<s> > st;
        v<v<int>> cb(n,v<int>(n,0));
        
        for(int i=0;i<n;i++)
            looper(cb,0,i,n,st);
        return res;
    }
};