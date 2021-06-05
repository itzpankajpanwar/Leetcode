class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    if(x==0) return 0;
    unordered_set<int> visi(forbidden.begin(),forbidden.end());
    set<pair<int,bool>> gg;
    queue<pair<int,bool>> q;
    q.push({0,true});
    int res=0;
    while(!q.empty())
    {
        int k=q.size();
        for(int i=0;i<k;i++)
        {
            auto ct = q.front(); q.pop();
           
            if(ct.first == x) return res;
            
            if(visi.count(ct.first) == 0 && gg.count(ct)==0)
                {
                    gg.insert(ct);

                    if(ct.first+a <=6000)
                        q.push({ct.first+a , true});
                   
                    if(ct.second==true && ct.first-b >=0)
                        q.push({ct.first-b ,false}); 
                        
                }
             }
            res++;
        }
    
        return -1;
    }
};