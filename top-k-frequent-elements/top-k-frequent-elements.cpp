#define pi pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int>  mp;
    priority_queue< pi , vector<pi>,greater<pi> > pq;
    for(auto &x: nums) mp[x]++;
    for(auto &x: mp ) { pq.push({x.second,x.first}) ; if(pq.size() > k) pq.pop(); }
    vector<int> res;
    while(pq.size()>0) { res.push_back(pq.top().second);  pq.pop();}
    return res;
    }
};