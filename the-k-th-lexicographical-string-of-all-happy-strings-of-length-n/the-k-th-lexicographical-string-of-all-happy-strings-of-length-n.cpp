class Solution {
public:
   
    string getHappyString(int n, int k) {
        vector<string> ans;
        queue<string> q;
        q.push("a");
        q.push("b");
        q.push("c");
        while(!q.empty())
        {
            string x=q.front();
            q.pop();
            if(x.length()==n)
            {
                ans.push_back(x);
            }
            string s1="",s2="";
            if(x[x.length()-1]=='a')
            {
                s1=x+"b";
                s2=x+"c";
                
            }
            if(x[x.length()-1]=='b')
            {
                s1=x+"a";
                s2=x+"c";
                
            }
            if(x[x.length()-1]=='c')
            {
                s1=x+"a";
                s2=x+"b";
                
            }
            
            //push only when less than n
            
            if(s1.length()<=n)
            {
                q.push(s1);
            }
            if(s2.length()<=n)
            {
                q.push(s2);
            }
        }
   
        string s="";
        if(k-1>=ans.size())
        {
            s="";
        }
        else
        {
            s=ans[k-1];
        }
        return s;
        
    
    }

};