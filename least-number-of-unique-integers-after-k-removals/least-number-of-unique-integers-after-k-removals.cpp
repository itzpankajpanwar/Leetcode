class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto &x:arr) mp[x]++;
        
        int tt = mp.size() , r = 0 , ci=1;
        
        while(k>=ci)
        {      
            for(auto &x:mp)
                {
                    if( x.second == ci )
                    {
                        x.second=0;
                        k-=ci;
                        r++;
                    }
                    if(k<ci)
                        break;   
                }
         ci++;
        }
        return tt-r;
    }
};