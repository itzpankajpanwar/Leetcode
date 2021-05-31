class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> mh;
    for(auto &x:matrix)
        for(auto &y:x)
        {
            mh.push(y);
            if(mh.size()>k)
                mh.pop();
        }
    return mh.top();
    }
};