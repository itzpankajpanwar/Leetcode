#define pi pair<int,int> 
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    
    unordered_map<int,int> mp;
    for(auto &x: barcodes) 
        mp[x]++;
    
    priority_queue< pi > hp;
    for(auto &x: mp)
        hp.push( { x.second,x.first} );
    
    vector<int> res;
    
    while(!hp.empty())
    {
        auto x = hp.top();
        hp.pop();
        if(hp.empty())
            {  res.push_back(x.second);  break; }
        else
        {
            auto y = hp.top();
            hp.pop();
            res.push_back(x.second); res.push_back(y.second);
            x.first--; y.first--;
            if(y.first > 0) hp.push(y);
            if(x.first > 0) hp.push(x);   
        }
    }
    return res;
    }
};