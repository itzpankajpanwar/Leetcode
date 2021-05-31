#define pi pair<int,string> 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
    //priority_queue< pi , vector<pi> , greater<pi> > pq;
    
    unordered_map< string , int> mp;
    for(auto &x:words)
        mp[x]++;
        
    auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
    typedef priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq_t;
        
    pq_t pq(comp); 
        
    for(auto & x : mp) 
    { 
        pq.push({x.first , x.second});
        if( pq.size() > k )  pq.pop(); 
    }
        
    vector<string> res;
    while (!pq.empty() ) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    reverse(res.begin(),res.end());
    return res;
    }
};