class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res=0;
        unordered_map<int,int> visi;
        for(auto &x : answers)
        {
            if(visi.find(x) == visi.end())
                { res+= x+1;
                  visi[x]=x;
                }
            else
            {
                if(visi[x]-1 < 0 ) {res+= x+1; visi[x]=x;}
                else visi[x]--;        
            }
        }
        return res;
    }
};