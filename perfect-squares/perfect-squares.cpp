class Solution {
public:
    int numSquares(int n) {
    
        vector<int> psq;
        int j=1;
        while(j*j<=n)
            { 
            psq.push_back(j*(j++));
            }
       
        queue<int> q;
        q.push(0);
        unordered_set<int> visi;
        int res=0;
        
        while(!q.empty())
        {
            int k=q.size();
            for(int m=0;m<k;m++)
            {
                auto i = q.front(); q.pop();
                if(i==n) return res;
                if(visi.count(i)==0)
                {
                    visi.insert(i);
                    for(auto &x: psq)
                        q.push(i+x);
                }
            }
             res++;
        }
    return n;
    }
};