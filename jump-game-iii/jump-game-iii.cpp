class Solution {
public:
    
    unordered_set<int> visited;
    bool canReach(vector<int>& arr, int s) {
        if(arr[s] == 0)
            return true;
        if( visited.find(s) != visited.end())
            return false;
         visited.insert(s);
         bool res = false;
         if( s+ arr[s] < arr.size()) res = res || canReach(arr,s+ arr[s]);
         if( s- arr[s] >=0 ) res = res || canReach(arr,s- arr[s]);
         return res;  
    }
};