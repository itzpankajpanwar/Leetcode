class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    unordered_set<int> visi;
    queue<size_t> q;
    q.push(0); int res=0;
    
    while(!q.empty())
    {
        int k=q.size();
        for(int i=0;i<k;i++)
        {
            auto x=q.front(); q.pop();
            if(x==amount) return res;
            if(visi.count(x)==0)
            {
                visi.insert(x);
                for(auto&y:coins)
                    if( y+x <= amount )
                        q.push(y+x);
            }
        }
        res++;
    }
     return -1; 
    }
};