class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin() , arr.end(),[](vector<int> &v1, vector<int> &v2){
            return v1[0]==v2[0] ? v1[1]<v2[1] : v1[0]<v2[0];
        });
        for(auto &x:arr)
            cout<<x[0]<<"   "<<x[1]<<endl;
        int res=0 , ci= 0;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i][0]< arr[ci][1] )
             {
                res++;
                if(arr[i][0] >= arr[ci][0] && arr[i][1]<=arr[ci][1])
                    ci=i;
             }
            else 
                ci= i ;
        }
        return res;
    }
};